
#include <iostream>
#include <vector>
#include <sstream>

#include "GameThread.hpp"

using namespace std;

#define MinimumBet 5

GameThread::GameThread()
{
	myBetValue = 0;

}

GameThread::~GameThread()
{
	cout << "arghhh you've destroyed me!" << endl;
}

/* Use ANSI escape codes to clear the screen */
void GameThread::ClearScreen()
{
	cout << "\033[2J\033[2;1H";
}

/* Return the number of players */
const int GameThread::CountPlayers()
{
	string UserEntry;
	int NumberOfPlayers;

	/* Ensure the user enters a valid number (loop question until they do) */
	do
	{
		ClearScreen();
		cout << "How many players? (1 - 7)" << endl;
		getline(cin, UserEntry);
		stringstream StrToInt(UserEntry); 
		StrToInt >> NumberOfPlayers;
		/* Number must be between 1 and 7 and only 1 character long */
	}while(!(NumberOfPlayers > 0 && NumberOfPlayers < 8 && UserEntry.size() == 1));
	
	return NumberOfPlayers;
}

Box* GameThread::NewBox(Player* pPlayer, bool Split)
{
	Box *pBox;

	pBox = new Box(pPlayer, Split);
	connect(pBox, SIGNAL(updatePlayersHand(QString,int)), this, SLOT(goodbye(QString,int)));
	connect(pBox, SIGNAL(updatePlayersHandValue(QString)), this, SLOT(thUpdatePlayersHandValue(QString)));
	connect(pBox, SIGNAL(updateBet(QString)), this, SIGNAL(updateBet(QString)));
	connect(this, SIGNAL(IncreaseBet(float)), pBox, SLOT(IncreaseBet(float)));
	connect(this, SIGNAL(DecreaseBet(float)), pBox, SLOT(DecreaseBet(float)));
//	connect(pBox, SIGNAL(updatePlayersName(QString)), this, SLOT(thUpdatePlayersName(QString)));

	return pBox;
}

/* Create a box for every player at the table */
void GameThread::SeatPlayers(Table& BlackJackTable, const int NumberOfPlayers)
{
	int i;
	string PlayerName;
	Player *pPlayer;
	Box *pBox;

	/* Request each player's name */
	for(i = 0; i < NumberOfPlayers; i++)
	{
		ClearScreen();
		//cout << "Player " << (i + 1) << "'s name:" << endl;
		//getline(cin, PlayerName);
		/* Create a player object to link to each box */
		//pPlayer = new Player(PlayerName);
		pPlayer = new Player("Jimbo");
		connect(pPlayer, SIGNAL(updateStack(QString)), this, SLOT(thUpdateStack(QString)));
		//pBox = new Box(pPlayer, false);
		pBox = NewBox(pPlayer, false);
/*		connect(pBox, SIGNAL(updatePlayersHand(QString,int)), this, SLOT(goodbye(QString,int)));
		connect(pBox, SIGNAL(updatePlayersHandValue(QString)), this, SLOT(thUpdatePlayersHandValue(QString)));
		connect(pBox, SIGNAL(updateBet(QString)), this, SLOT(thUpdateBet(QString)));*/
		BlackJackTable.AddBox(pBox, i);
		/* Add every box to the table */
//		BlackJackTable.AddBox(pPlayer, i);
	}
	ClearScreen();
}

/* Collect bets from every player */
void GameThread::CollectBets(Table& BlackJackTable)
{
	int BoxIndex;
	string UserEntry;
	int NewBet;

	QEventLoop eventLoop;
	connect(this, SIGNAL(BetDone()), &eventLoop, SLOT(quit()));
	connect(this, SIGNAL(Choice()), &eventLoop, SLOT(quit()));
// TAP INTO NEW GAME BUTTON PRESS	connect(this, SIGNAL(BetDone()), &eventLoop, SLOT(quit()));

	/* Loop through all players at the table */
	for(BoxIndex = 0; BoxIndex < BlackJackTable.CountBoxes(); BoxIndex++)
	{
		Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);
		//emit updatePlayersName(QString::fromStdString(CurrentBox->GetOwner()));
		do
		{
			emit ButtonVisibility(false, false, false, false, false, false, false, false);
			cout << CurrentBox->GetOwner() << ", place your bet (" << CurrentBox->CountStack() << " in your stack. Multiples of " << MinimumBet << " only):" << endl;
			emit updateStatus("Place your bet");
			eventLoop.exec();
//			cout << "Bet is " << CheckBetValue() << endl;
			cout << "Bet is " << CurrentBox->CountBet() << endl;
			cout << "CheckChoice = " << CheckChoice() << endl;
//	   		getline(cin, UserEntry);
	//		stringstream StrToInt(UserEntry); 
	//		StrToInt >> NewBet;
			/* ClearScreen needs to be at bottom of this loop to avoid the summary screen being hidden at the end of a round */
			ClearScreen();
		/* Player must be able to afford the bet and it must be at least the minimum bet value or a multiple of it */
//		}while(!(NewBet <= CurrentBox->CountStack() && NewBet >= MinimumBet && (int)NewBet % MinimumBet == 0));
//		}while(!(CheckBetValue() >= MinimumBet && (int)CheckBetValue() % MinimumBet == 0));
		}while((CheckChoice() != 8) and (!(CurrentBox->CountBet() >= MinimumBet && (int)CurrentBox->CountBet() % MinimumBet == 0)));
//		CurrentBox->PlaceBet(NewBet);
		//CurrentBox->PlaceBet(CheckBetValue());
		ClearBet();
	}
}

/* Deal everyone their first two cards (including the dealer) */
void GameThread::InitialDeal(Table& BlackJackTable, Croupier& Dealer)
{
	int Deal;
	int BoxIndex;
	Card DealtCard;

	for(Deal = 0; Deal < 2; Deal++)
	{
		for(BoxIndex = 0; BoxIndex < BlackJackTable.CountBoxes(); BoxIndex++)
		{
			Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);
	    	DealtCard = Dealer.Deal();
			CurrentBox->TakeCard(DealtCard);
		}
	    DealtCard = Dealer.Deal();
		Dealer.TakeCard(DealtCard);
	}
}

/* Check for player blackjack and state any insurance options */
void GameThread::InsuranceOffers(Table& BlackJackTable, Croupier& Dealer)
{
	int BoxIndex;
	string Choice;

	QEventLoop eventLoop;
	connect(this, SIGNAL(Choice()), &eventLoop, SLOT(quit()));

	for(BoxIndex = 0; BoxIndex < BlackJackTable.CountBoxes(); BoxIndex++)
	{
		Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);
		
		/* Player has blackjack - display message */
		if(CurrentBox->CheckHand() == 21)
		{
			Dealer.InitialStatus();
			cout << CurrentBox->GetOwner() << ": (" << CurrentBox->CountStack() << " in your stack, ";
			cout << CurrentBox->CountBet() << " on the table) You are holding: " << endl << endl;	
			CurrentBox->ListHand();
			cout << "  Blackjack!" << endl << endl;
			emit updateStatus("Blackjack!");
			emit ResultTextVisibility(false, false, true, false);
			sleep(2);
			emit ResultTextVisibility(false, false, false, false);
		}
				
		/* If dealer has an ace as their upcard, and they have enough money, offer insurance */
		if (Dealer.CheckCard(0) == "Ace" and (CurrentBox->CountStack() >= (CurrentBox->CountBet() / 2)))
		{
			/* If the player has blackjack their status will already be displayed */
			if(CurrentBox->CheckHand() != 21)
			{
				Dealer.InitialStatus();
				CurrentBox->Status();
			}
			//do
			//{
				cout << CurrentBox->GetOwner() << ", the dealer is showing an ace. ";
				
				/* Hands of blackjack receive different message for same offer */
				if (CurrentBox->CheckHand() == 21)
				{
					cout <<	"Even money? (y or n)" << endl;
					emit updateStatus("The dealer is showing an ace\nEven money?");
				}
				else
				{
					emit updateStatus("The dealer is showing an ace\nWould you like insurance?");
					cout << "Would you like insurance? (y or n)" << endl;
				}
				emit ButtonVisibility(false, false, false, false, false, true, true, false);
				eventLoop.exec();
				emit ButtonVisibility(false, false, false, false, false, false, false, false);
/*				getline(cin, Choice);

				if(Choice == "y")
				{
					CurrentBox->PlaceInsurance();
				}*/

				if(CheckChoice() == 6)
				{
					CurrentBox->PlaceInsurance();
				}
				else if(CheckChoice() == 7)
				{
				}

			//	ClearScreen();
			/* Loop until they give a valid answer */
			//}while(Choice != "y" && Choice != "n");
		}
		ClearScreen();
	}
}

/* Check for any blackjacks and handle insurance claims accordingly */
bool GameThread::CheckForBlackJack(Table& BlackJackTable, Croupier& Dealer)
{
	int BoxIndex;
	bool DealerBlackjack = false;
	bool PauseForMessage = false;

	/* If the dealer has blackjack, show it! */
	if (Dealer.CheckHand() == 21)
	{
		emit updateStatus("Dealer has blackjack!");
		cout << "Dealer is holding: " << endl << endl;	
		Dealer.ListHand();
		cout << "  Blackjack!" << endl << endl;
		DealerBlackjack = true;
		emit ResultTextVisibility(false, false, false, true);

/********************** added ********************************/
		Box* CurrentBox = BlackJackTable.GetBox(0);
		CurrentBox->Status();
/*************************************************************/
		sleep(2);
		emit ResultTextVisibility(false, false, false, false);
	}
	else
	{
		DealerBlackjack = false;
	}

	/* Check for push or even money condition for every player and list each result */
	for(BoxIndex = 0; BoxIndex < BlackJackTable.CountBoxes(); BoxIndex++)
	{
		Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);
		/* Player has blackjack */
		if (CurrentBox->CheckHand() == 21)
		{
			/* Player has taken out insurance */
			if (CurrentBox->CheckInsurance() == true)
			{
				cout << "Even money for " << CurrentBox->GetOwner() << endl;
				emit updateStatus("Even money");
				PauseForMessage = true;
			}
			/* Player hasn't taken out insurance */
			else
			{
				/* Dealer has blackjack */
				if (DealerBlackjack == true)
				{
					cout << "Dealer and " << CurrentBox->GetOwner() << " both have blackjack!  Push!" << endl;
					emit updateStatus("Dealer and player both have blackjack!\nPush!");
					PauseForMessage = true;
				}
			}
		}
	}

	/* Keep any messages on the screen for a bit */
	if (PauseForMessage == true)
	{
		sleep(2);
		cout << endl;
	}

	/* Also check insurance situation for every player but only display resulting message once */
	for(BoxIndex = 0; BoxIndex < BlackJackTable.CountBoxes(); BoxIndex++)
	{
		Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);

		/* Player has taken out insurance and doesn't have blackjack */
		if (CurrentBox->CheckInsurance() == true and CurrentBox->CheckHand() != 21)
		{
			/* Dealer doesn't have blackjack */
			if (DealerBlackjack == false)
			{
				cout << "Dealer doesn't have blackjack.  Insurance bets lost" << endl;
				emit updateStatus("Dealer doesn't have blackjack\nInsurance bets lost");
			}
			/* Dealer has blackjack */
			else
			{
				emit updateStatus("Dealer has blackjack\nInsurance bet pays out");
				cout << "Dealer has blackjack\nInsurance bets pay out" << endl;
			}
			sleep(2);
			break;
		}
	}
	return DealerBlackjack;
}

/* Give player options on how they can play their hand */
void GameThread::StateOptions(Box* CurrentBox, bool PlayersFirstGo)
{
	string FirstCard = CurrentBox->CheckCard(0);
	string SecondCard = CurrentBox->CheckCard(1);

	bool HitVisible = false;
	bool StandVisible = false;
	bool SurrenderVisible = false;
	bool DoubleVisible = false;
	bool SplitVisible = false;

	if (CurrentBox->CheckSplit() == true)
	{
		emit updateStatus("Split Hand\nWhat would you like to do?");			
	}
	else
	{
		emit updateStatus("What would you like to do?");
	}

	cout << "Hit (h), ";
	HitVisible = true;
	/* If past initial hand stage */
	if (CurrentBox->CountCards() > 2)
	{
		cout << "or stand (s)?" << endl;
		StandVisible = true;
	}
	/* Initial hand stage */
	else
	{	
		/* Not after split */
		if (PlayersFirstGo == true and CurrentBox->CheckSplit() != true)
		{
			cout << "stand (s)";
			StandVisible = true;
			/* Player has enough money to double or split */
			if (CurrentBox->CountStack() >= CurrentBox->CountBet())
			{
				cout << ", double (d)";
				DoubleVisible = true;
				/* First two cards are the same */
				if (FirstCard.compare(SecondCard) == 0)
				{
					cout << ", split (p)";
					SplitVisible = true;
				}
			}
			cout << ", or surrender (q)?" << endl;
			SurrenderVisible = true;
		}
		/* After split */
		else
		{
			/* Player has enough money to double or split */
			if (CurrentBox->CountStack() >= CurrentBox->CountBet())
			{
				cout << "stand (s), ";
				StandVisible = true;
				/* First two cards are the same */
				if (FirstCard.compare(SecondCard) == 0)
				{
					cout << "double (d), or split (p)?" << endl;
					DoubleVisible = true;
					SplitVisible = true;
				}
				/* Cards are not the same */
				else
				{
					cout << "or double (d)?" << endl;
					DoubleVisible = true;
				}
			}
			else
			{
				cout << "or stand (s)?" << endl;
				StandVisible = true;
			}
		}
	}
	emit ButtonVisibility(HitVisible, StandVisible, SurrenderVisible, DoubleVisible, SplitVisible, false, false, false);
}

void GameThread::SetChoice(int ButtonIndex)
{
	ButtonChoice = ButtonIndex;
}

int GameThread::CheckChoice()
{
	return ButtonChoice;
}

int GameThread::CheckBetValue()
{
	return myBetValue;
}

void GameThread::ChoiceMade(int ButtonIndex)
{
	cout << "button " << ButtonIndex << " was pressed" << endl;
	SetChoice(ButtonIndex);
	emit Choice();
}

void GameThread::RemoveFromStack(int BetValue)
{
	Box* CurrentBox = BlackJackTable.GetBox(0);
	CurrentBox->PlaceBet(BetValue);
//	emit thUpdateBet(BetValue);
	emit ButtonVisibility(false, false, false, false, false, false, false, true);
	cout << "did this work?\n";
}

void GameThread::ClearBet()
{
	myBetValue = 0;
}

void GameThread::BettingDone()
{
	cout << "betting done!" << endl;
	emit BetDone();
}

void GameThread::hello(QString LoadCardName, int CardPosition)
{
	cout << endl << "Am I used????" << endl;
	emit updateDealersHand(LoadCardName, CardPosition);
}

void GameThread::goodbye(QString LoadCardName, int CardPosition)
{
	cout << endl << "How about me????" << endl;
	emit updatePlayersHand(LoadCardName, CardPosition);
}

void GameThread::thUpdatePlayersHandValue(QString HandValue)
{
	emit updatePlayersHandValue(HandValue);
}

void GameThread::thUpdateDealersHandValue(QString HandValue)
{
	emit updateDealersHandValue(HandValue);
}

void GameThread::thUpdateStack(QString StackValue)
{
	emit updateStack(StackValue);
}

void GameThread::thUpdateBet(float BetValue)
{
	cout << "bet updated to " << BetValue << endl;
//	emit updateBet(QString::number(BetValue));
}

/*void GameThread::thUpdatePlayersName(QString pName)
{
	emit updatePlayersName(pName);
}*/


/* Every player plays their hands */
const bool GameThread::PlayersPlay(Table& BlackJackTable, Croupier& Dealer)
{
	int BoxIndex;
	string Choice;
	Card DealtCard;
	int SplitIndex;
	/* Keep track of if any players are left for dealer to play against */
	bool PlayersStanding = false;
	/* Certain plays can only take place upon a player's first go */
	bool PlayersFirstGo;
	
	QEventLoop eventLoop;
	connect(this, SIGNAL(Choice()), &eventLoop, SLOT(quit()));

	for(BoxIndex = 0; BoxIndex < BlackJackTable.CountBoxes(); BoxIndex++)
	{
		Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);
		//emit updatePlayersName(QString::fromStdString(CurrentBox->GetOwner()));
		PlayersFirstGo = true;
		ClearScreen();

		/* Check player doesn't already have blackjack */
		if (CurrentBox->CheckHand() != 21)
		{			
			emit clearPlayersHand();
			do
			{
				Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);
				/* Check first two cards in case a split is possible */
				string FirstCard = CurrentBox->CheckCard(0);
				string SecondCard = CurrentBox->CheckCard(1);
				
				ClearScreen();
				Dealer.InitialStatus(); 
				CurrentBox->Status();
					
				/* Check for a non-blackjack 21 */
				if(CurrentBox->CheckHand() == 21)
				{
					/* Auto-stand on a 21 */
					emit updateStatus("Auto-standing on 21");
					emit ButtonVisibility(false, false, false, false, false, false, false, false);
					PlayersStanding = true;
					sleep(2);
					break;
				}
				
				/* Tell the player their options of play */
				StateOptions(CurrentBox, PlayersFirstGo);
//				getline(cin, Choice);
//				cout << "Sat waiting....." << endl;
				eventLoop.exec();
			//	emit ButtonVisibility(false, false, false, false, false, false, false, false);
				/* Player hits */
				if(CheckChoice() == 1)
				{
					PlayersFirstGo = false;		
					DealtCard = Dealer.Deal();
					CurrentBox->TakeCard(DealtCard);
					QString CardName = DealtCard.GetName();
					QString CardSuit = DealtCard.GetSuit();
					//QString LoadCardName = "PlayerCards/" + CardName + CardSuit + ".png";
					QString LoadCardName = "PlayerCards/" + CardName + CardSuit + ".png";

					//emit updatePlayersHand(LoadCardName);		
					/* If the hit causes them to go bust */
					if(CurrentBox->CheckHand() > 21)
					{
						ClearScreen();
						emit updateStatus("Bust!");
						emit ButtonVisibility(false, false, false, false, false, false, false, false);
						CurrentBox->Status();
						emit ResultTextVisibility(true, false, false, false);
						sleep(2);
						emit ResultTextVisibility(false, false, false, false);
						break;
					}	
				}
				/* Player stands */
				else if(CheckChoice() == 2)
				{
					PlayersStanding = true;
					//ClearScreen();
				}
				else if(CheckChoice() == 8)
				{
					PlayersStanding = false;
					//ClearScreen();
					cout << endl << "Player trying to start a new game...." << endl;
					return PlayersStanding;
				}
				/* Certain plays can only happen if player is holding two cards (regardless of whether first go or not) */
				if (CurrentBox->CountCards() == 2)
				{
					/* Players can only surrender on their first go */
					if (PlayersFirstGo == true and CheckChoice() == 5)
					{
						cout << endl << CurrentBox->GetOwner() << " surrenders" << endl;
						cout << "Half of bet of " << CurrentBox->CountBet() << " returned" << endl;
						emit updateStatus("You surrendered\nHalf of bet returned");
						emit ButtonVisibility(false, false, false, false, false, false, false, false);
						CurrentBox->Surrender();
						sleep(2);
						break;
					}
					/* Some plays are only possible if a player has enough money in their stack */
					if (CurrentBox->CountStack() >= CurrentBox->CountBet())
					{
						/* Player doubles */
						if (CheckChoice() == 3)
						{		
							cout << endl << "Initial bet doubled. Dealing one more card...." << endl;

							ClearScreen();
							/* Place bet again to double initial bet and take one last card */
						//	CurrentBox->PlaceBet(CurrentBox->CountBet());
							emit IncreaseBet(CurrentBox->CountBet());
							emit updateStatus("Initial bet doubled\nDealing one more card....");
							emit ButtonVisibility(false, false, false, false, false, false, false, false);
							sleep(2);
							emit updateBet("0");
							DealtCard = Dealer.Deal();
							CurrentBox->TakeCard(DealtCard);
							
							PlayersFirstGo = false;	
						//	PlayersStanding = true;

	/*						CurrentBox->Status();							
							sleep(2);
							break;*/
							/***************************************/
							if(CurrentBox->CheckHand() > 21)
							{
								PlayersStanding = false;
								ClearScreen();
								emit updateStatus("Bust!");
								emit ButtonVisibility(false, false, false, false, false, false, false, false);
								CurrentBox->Status();
								emit ResultTextVisibility(true, false, false, false);
								sleep(2);
								emit ResultTextVisibility(false, false, false, false);
								break;
							}	
							else
							{
								PlayersStanding = true;
								CurrentBox->Status();							
								sleep(2);
								break;
							}
							/***************************************/
						}
						/* Players can split if they have two of the same card */
						if (FirstCard.compare(SecondCard) == 0 and CheckChoice() == 4)
						{
							PlayersFirstGo = false;		
							/* Add a new box to the table in the next position with same owner as the current box */
							Box *pBox;
							pBox = new Box(CurrentBox->GetOwnerObj(), true);
							connect(pBox, SIGNAL(updatePlayersHand(QString,int)), this, SLOT(goodbye(QString,int)));
							connect(pBox, SIGNAL(updatePlayersHandValue(QString)), this, SLOT(thUpdatePlayersHandValue(QString)));
							connect(pBox, SIGNAL(updateBet(QString)), this, SIGNAL(updateBet(QString)));
							connect(this, SIGNAL(IncreaseBet(float)), pBox, SLOT(IncreaseBet(float)));
							connect(this, SIGNAL(DecreaseBet(float)), pBox, SLOT(DecreaseBet(float)));
							BlackJackTable.AddBox(pBox, BoxIndex + 1);
//							pBox = NewBox(CurrentBox->GetOwnerObj(), BoxIndex + 1);
					//		BlackJackTable.AddBox(pBox, true);
							/* Have to redefine CurrentBox after the insert */	
							Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);
							Box* SplitBox = BlackJackTable.GetBox(BoxIndex+1);

							/* New box places same bet as current box */
							SplitBox->PlaceBet(CurrentBox->CountBet());
							emit updateBet("0");
							
							SplitBox->TakeCard(CurrentBox->MoveSplitCard());
							/* Deal a new card for both boxes */
							for(SplitIndex = BoxIndex; SplitIndex < BoxIndex + 2; SplitIndex++)
							{
								Box* CurrentBox = BlackJackTable.GetBox(SplitIndex);										
								DealtCard = Dealer.Deal();
								CurrentBox->TakeCard(DealtCard);	
							}	
						}
					}
				}
			/* Keep looping until everyone stands (or goes bust) */
//			}while(Choice != "s");
			}while(CheckChoice() != 2);
		}
		/* Split hands may have 21 but can't have blackjack */
		else if (CurrentBox->CheckHand() == 21 and CurrentBox->CheckSplit() == true)
		{
			CurrentBox->Status();
			sleep(2);
		}
	//	emit ButtonVisibility(false, false, false, false, false, false, false, false);
//		emit clearPlayersHand();
	}
	emit ButtonVisibility(false, false, false, false, false, false, false, false);
	return PlayersStanding;
}

/* Dealer plays until hand value is greater than 17 */
void GameThread::DealerPlays(Croupier& Dealer)
{
	Card DealtCard;

	emit updateStatus("Dealer plays....");
	/* Show dealer's current status before continuing */
	ClearScreen();
	Dealer.Status();
	sleep(1);

	/* Keep taking cards until over 17 or bust */
	while (Dealer.CheckHand() < 17)
	{
		ClearScreen();
		DealtCard = Dealer.Deal();
		Dealer.TakeCard(DealtCard);
		Dealer.Status();
		if(Dealer.CheckHand() > 21)
		{
			emit updateStatus("Dealer bust!");
			emit ResultTextVisibility(false, true, false, false);
			sleep(2);
			emit ResultTextVisibility(false, false, false, false);
		}
		else
		{
			sleep(1);
		}
	}
	
}

/* Remove broke players from the table and report on remaining players */
void GameThread::RefreshPlayerList(Table& BlackJackTable)
{
	int BoxIndex = 0;	

	/* While there are still boxes to check */
	while(BoxIndex != BlackJackTable.CountBoxes())	
	{
		Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);
		/* Player doesn't have enough money to bet with */
		if (CurrentBox->CountStack() < MinimumBet)
		{
			cout << CurrentBox->GetOwner() << " has no money left to play and has left the table" << endl;
			BlackJackTable.RemoveBox(BoxIndex);
		}
		else
		{
			BoxIndex++;
		}
	}
	/* List all players left at the table, else exit the game with a message */
	if(BlackJackTable.CountBoxes() > 0)
	{
		BlackJackTable.ListPlayers();
	}
	else
	{
		cout << endl << "All players have gone bust!  Exiting the game...." << endl << endl;
	}
}

string GameThread::NumberToString(float Number)
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

/* Work out who has won and who has lost and settle all bets */
void GameThread::SettleBets(Table& BlackJackTable, Croupier& Dealer)
{
	int BoxIndex;
//	QString ResultsSummary;
	std::string ResultsSummary;
	string StrCountBet;
	string StrCheckHand;
	string StrDealersCheckHand;
	string StrHalfBet;
	string StrBlackjack;
	string StrHandNum;
	string StrNumHands;

	bool PlayerWonBet;

	ClearScreen();
	emit updateStatus("Results");	

	/* Give summary for every box at the table */
	for(BoxIndex = 0; BoxIndex < BlackJackTable.CountBoxes(); BoxIndex++)
	{
		Box* CurrentBox = BlackJackTable.GetBox(BoxIndex);

		StrCountBet = NumberToString(CurrentBox->CountBet());
		StrCheckHand = NumberToString(CurrentBox->CheckHand());
		StrDealersCheckHand = NumberToString(Dealer.CheckHand());
		StrHalfBet = NumberToString((CurrentBox->CountBet() / 2));
		StrBlackjack = NumberToString(CurrentBox->CountBet() + (CurrentBox->CountBet() / 2)) ;
		StrHandNum = NumberToString(BoxIndex + 1);
		StrNumHands = NumberToString(BlackJackTable.CountBoxes());
		/* Note the equal sign here instead of += clears all text stored up to this point */
		ResultsSummary = "Hand " + StrHandNum + " of " + StrNumHands + "\n\n"; 

		/* Include a player's split hand results under their same name heading as their other results */
		if(CurrentBox->CheckSplit() == false)
		{
			//cout << CurrentBox->GetOwner() << ":" << endl;
			//ResultsSummary += CurrentBox->GetOwner() + ":\n";
		}
		/* If player didn't surrender */
		if(CurrentBox->CheckSurrended() == false)
		{
			/* Start the summary with a different label if referring to a split hand */
			if(CurrentBox->CheckSplit() == false)
			{
				cout << "  Hand of ";
				ResultsSummary += "Hand of ";
			}
			else
			{
				cout << "  Split hand of ";
				ResultsSummary += "Split hand of ";
			}
			/* Player didn't go bust */
			if (CurrentBox->CheckHand() < 22)
			{
				/* Dealer had blackjack (checking for 2 cards to ensure they don't just have a 21 score) */
				if (Dealer.CheckHand() == 21 and Dealer.CountCards() == 2)
				{
					/* Player also had blackjack */
					if (CurrentBox->CheckHand() == 21 and CurrentBox->CountCards() == 2 and CurrentBox->CheckSplit() == false)
					{
						cout << "blackjack in push with dealer's blackjack" << endl;
						ResultsSummary += "blackjack in push with dealer's\nBet of " + StrCountBet + " returned\n";
						emit PlayLoseSound();
						CurrentBox->RetrieveBet();	
						/* Player took insurance */
						if (CurrentBox->CheckInsurance() == true)
						{
							/* Even money */
							CurrentBox->ReceiveInsurance();
							emit PlayWinSound();
							ResultsSummary += "Win insurance bet and collect " + StrCountBet + " from the dealer\n";
						}
					}
					/* Player didn't have blackjack as well */ 
					else
					{
						cout << CurrentBox->CheckHand() << " beaten by dealer's blackjack" << endl;
						ResultsSummary += StrCheckHand + " beaten by dealer's blackjack\n";
						cout << "  " << "Loses bet of " << CurrentBox->CountBet() << endl;
						ResultsSummary += "Lose bet of " + StrCountBet + "\n";
						emit PlayLoseSound();
					}
				}
				/* Dealer doesn't have blackjack */
				else
				{
					/* Player had blackjack */
					if (CurrentBox->CheckHand() == 21 and CurrentBox->CountCards() == 2 and CurrentBox->CheckSplit() == false)
					{
						cout << "blackjack beat's dealer's " << Dealer.CheckHand() << endl;
						ResultsSummary += "blackjack beat's dealer's " + StrDealersCheckHand + "\n";
						ResultsSummary += "Win bet and collect " + StrBlackjack + " from the dealer\n";	
						emit PlayWinSound();
						PlayerWonBet = true;		
						CurrentBox->ReceiveWinnings();
					}
					/* Player didn't have blackjack */
					else
					{
						/* Player's hand is greater than dealer's hand or dealer is bust */
						if (CurrentBox->CheckHand() > Dealer.CheckHand() or Dealer.CheckHand() > 21)
						{
							cout << CurrentBox->CheckHand() << " beats dealer's " << Dealer.CheckHand() << endl;
							ResultsSummary += StrCheckHand + " beats dealer's " + StrDealersCheckHand + "\n";	
							ResultsSummary += "Win bet and collect " + StrCountBet + " from the dealer\n";
							emit PlayWinSound();
							PlayerWonBet = true;
							CurrentBox->ReceiveWinnings();
						}
						/* Player's hand in push with dealer's hand */
						else if (CurrentBox->CheckHand() == Dealer.CheckHand())
						{
							cout << CurrentBox->CheckHand() << " in push with dealer's " << Dealer.CheckHand() << endl;
							ResultsSummary += StrCheckHand + " in push with dealer's " + StrDealersCheckHand + "\nBet of " + StrCountBet + " returned\n";	
							CurrentBox->RetrieveBet();
							emit PlayLoseSound();
						}
						/* Player's hand is less than dealer's hand */
						else
						{
							cout  << CurrentBox->CheckHand() << " beaten by dealer's " << Dealer.CheckHand() << endl;
							ResultsSummary += StrCheckHand + " beaten by dealer's " + StrDealersCheckHand + "\n";		
							cout << "  " << "Loses bet of " << CurrentBox->CountBet() << endl;
							ResultsSummary += "Lose bet of " + StrCountBet + "\n";
							emit PlayLoseSound();
						}
					}
				}
			}				
			/* Player went bust */
			else	
			{
				cout  << CurrentBox->CheckHand() << " went bust" << endl;
				ResultsSummary += StrCheckHand + " went bust\n";
				cout << "  Loses bet of " << CurrentBox->CountBet() << endl;
				ResultsSummary += "Lose bet of " + StrCountBet + "\n";
				emit PlayLoseSound();
			}
			
			/* Player took out insurance (need to check this even if player went bust) */
			if (CurrentBox->CheckInsurance() == true)
			{
				/* Player had blackjack */
				if (CurrentBox->CheckHand() == 21 and CurrentBox->CountCards() == 2 and CurrentBox->CheckSplit() == false)
				{
					/* Even money situation already dealt with above */
				}
				/* Player didn't have blackjack */
				else
				{
					/* Dealer had blackjack */
					if (Dealer.CheckHand() == 21 and Dealer.CountCards() == 2)
					{
						/* Message displayed with function */
						CurrentBox->ReceiveInsurance();
						emit PlayWinSound();
						ResultsSummary += "Win insurance bet and collect " + StrCountBet + " from the dealer\n";
					}
					/* Dealer didn't have blackjack */
					else
					{
						cout << "  Loses insurance bet of " << (CurrentBox->CountBet() / 2) << endl;
						ResultsSummary += "Lose insurance bet of " + StrHalfBet + "\n";
						/* This is here to ensure that if the player wins their bet but lose their insurance
							only the win sound is played */
						if(PlayerWonBet != true)
						{
							emit PlayLoseSound();
						}
					}
				}
			}	
		}
		/* Player surrendered */
		else
		{
			cout << "  Surrendered" << endl << "  Half of bet of " << CurrentBox->CountBet() << " returned" << endl;
			ResultsSummary += "Surrendered\nHalf of bet of " + StrCountBet + " returned\n";
			emit PlayLoseSound();
		}
		cout << endl;
		/* Player returns cards to the dealer */
		CurrentBox->ReturnCards();
//		emit clearPlayersHand();

		// Test string
//		ResultsSummary = "Hand of blackjack in push with dealer's blackjack\nWin insurance bet and collect 1500 from the dealer\nWin bet and collect 1500 from the dealer\n";
/*		StrHandNum = NumberToString(BoxIndex + 1);
		StrNumHands = NumberToString(BlackJackTable.CountBoxes());
		if(BlackJackTable.CountBoxes() > 1)
		{
			ResultsSummary += "\n\t\t\t\tHand " + StrHandNum + " of " + StrNumHands;
		}*/
		QString qstr = QString::fromStdString(ResultsSummary);
		updateResultsSummary(qstr);
		sleep(4.0);
		HideResultsSummary();
	}
}

void GameThread::ReturnBet(int ReturnedChipValue)
{
	cout << "You returned a chip of value = " << ReturnedChipValue << endl;
	Box* CurrentBox = BlackJackTable.GetBox(0);
	CurrentBox->ReturnToStack(ReturnedChipValue);
//	emit thUpdateBet(QString::number(CheckBetValue()));
}

void GameThread::run()
{
	/* Create table object */
	//Table BlackJackTable;

	/* Seat new players at the table */
	//SeatPlayers(BlackJackTable, CountPlayers());
	SeatPlayers(BlackJackTable, 1);

	/* Create a dealer object which generates a shoe of cards which are then shuffled */
	Croupier Dealer;

	connect(&Dealer, SIGNAL(updateDealersHand(QString, int)), this, SLOT(hello(QString, int)));
	connect(&Dealer, SIGNAL(updateDealersHandValue(QString)), this, SLOT(thUpdateDealersHandValue(QString)));

	/* Game begins and loops until all players go bust! */
	do
	{
		/* Collect bets from all players at the table*/
		emit DisableChips(true);
		CollectBets(BlackJackTable);
		if(CheckChoice() != 8)
		{
			emit DisableChips(false);
			emit updateBet("0");
			/* Deal out the inital two cards to every player and the dealer */
			InitialDeal(BlackJackTable, Dealer);
		
			/* If the dealer is showing an ace, and a player has enough money, offer insurance */
			InsuranceOffers(BlackJackTable, Dealer);

			/* Dealer checks for blackjack before continuing with game */		
			if(CheckForBlackJack(BlackJackTable, Dealer) == false)
			{
				/* Each player takes their turn (returns if players still in game after plays) */
				if(PlayersPlay(BlackJackTable, Dealer) != false)
				{
					/* If players are still in the game the Dealer plays his hand */
					DealerPlays(Dealer);
				}
				/* If all players go bust, display dealer's status */
				else
				{
					if(CheckChoice() == 8)
					{
					}
					else
					{
						int DealersHandVal = Dealer.CheckHand();
						emit updateStatus("Dealer was holding " + QString::number(DealersHandVal));
						ClearScreen();
						Dealer.Status();
						sleep(2);
					}
				}
			}
		}

/***********************  DO SOMETHING ABOUT RETURNING CARDS AS WELL TO CLEAR BETS ETC *****************************/


		if(CheckChoice() != 8)
		{
			/* Work out who has won and who has lost and settle all bets */
			SettleBets(BlackJackTable, Dealer);
		}

		/* The dealer returns his cards */
		Dealer.ReturnCards();
		emit clearDealersHand();
		emit clearPlayersHand();
		emit HandValueSpotsVisibility();

		/* Clear all boxes containing splits */
		BlackJackTable.RemoveSplits();
		
		if(CheckChoice() != 8)
		{
			/* Remove broke players from the table */
			RefreshPlayerList(BlackJackTable);
		}
		else
		{		
			BlackJackTable.Clear();
		}
		emit Clearchips();
	}
	while(BlackJackTable.CountBoxes() > 0);
	emit updateStatus("Game Over");
	QString qstr = QString::fromStdString("You've run out of playable money!\n\nWould you like to play again?");
	updateResultsSummary(qstr);
	//emit GameOver();
}

