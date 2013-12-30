
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include "dragwidget.h"
#include <QGroupBox>
#include <QMessageBox>

//using namespace Phonon;

#define MinimumBet 5
/*#define XScalingFactor 0.533
#define YScalingFactor 0.711

#define XScalingFactor 1
#define YScalingFactor 1*/

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
	QRect Screen = QApplication::desktop()->screenGeometry();

	/* Scale = User's screen size / My screen size */
	float wScale = Screen.width() / 1920.0;
	float hScale = Screen.height() / 1080.0;

	XScalingFactor = wScale;
	YScalingFactor = hScale;

 //   ui->setupUi(this);

	media = new Phonon::MediaObject(this);
	createPath(media, new Phonon::AudioOutput(Phonon::MusicCategory, this));

	PlayersCards = new QGroupBox(this);
	DealersCards = new QGroupBox(this);

	PlayersCards->setGeometry(195*XScalingFactor, 310*YScalingFactor, 300*XScalingFactor, 300*YScalingFactor);
	DealersCards->setGeometry(230*XScalingFactor, 50*YScalingFactor, 300*XScalingFactor, 300*YScalingFactor);

/*	int posX = 195;
	int posXDealer =230;*/
	int posX = 0;
	int posXDealer = 0;

//	GameThread *myThread = new GameThread();

	for(int a = 0; a < 11; a++)
	{
		posX += 24;
		posXDealer += 19;

		DealersHand[a] = new QLabel(DealersCards);
//		DealersHand[a]->setGeometry(posXDealer, 50, 191, 250);
		DealersHand[a]->setGeometry(posXDealer*XScalingFactor, 0, 191*XScalingFactor, 250*YScalingFactor);
		DealersHand[a]->lower();

		PlayersHand[a] = new QLabel(PlayersCards);
//		PlayersHand[a]->setGeometry(posX, 310, 191, 250);
		PlayersHand[a]->setGeometry(posX*XScalingFactor, 0, 191*XScalingFactor, 250*YScalingFactor);
		PlayersHand[a]->lower();
	}

  	NewGame = new QAction("&New Game", this);
	ToggleSound = new QAction("&Toggle Sound", this);
	About = new QAction("&About", this);
	Quit = new QAction("&Quit", this);

	ToggleSound->setCheckable(true);
	ToggleSound->setChecked(true);

	QMenu *Menu;
	Menu = menuBar()->addMenu("&Menu");
	Menu->addAction(NewGame);
	Menu->addAction(ToggleSound);
	Menu->addAction(About);
	Menu->addAction(Quit);

	connect(ToggleSound, SIGNAL(triggered()), this, SLOT(toggleStatusbar()));
	connect(About, SIGNAL(triggered()), this, SLOT(DisplayAboutBox()));
	connect(Quit, SIGNAL(triggered()), qApp, SLOT(quit()));

	QPalette* TextPalette = new QPalette();
	TextPalette->setColor(QPalette::WindowText,Qt::black);

	QRgb rgbvalue;
	rgbvalue = qRgb(205, 205, 0);

	QPalette* BetValueTextPalette = new QPalette();
	BetValueTextPalette->setColor(QPalette::WindowText,rgbvalue);

	QFont LabelFont("mry_KacstQurn");
	LabelFont.setPointSizeF(24.0*XScalingFactor);
	QFont StatusFont("mry_KacstQurn");
	StatusFont.setPointSizeF(22.0*XScalingFactor);
	QFont ResultsFont("mry_KacstQurn");
	ResultsFont.setPointSizeF(16.0*XScalingFactor);
	QFont HandValueFont("mry_KacstQurn");
	HandValueFont.setPointSizeF(16.0*XScalingFactor);

/*	QFont LabelFont("mry_KacstQurn", 18);
	QFont StatusFont("mry_KacstQurn", 14);
	QFont ResultsFont("mry_KacstQurn", 10);
	QFont HandValueFont("mry_KacstQurn", 10);*/

	labelBetRing = new QLabel(this);
//	labelBetRing->setGeometry(240*XScalingFactor, 520*YScalingFactor, 151*XScalingFactor, 111*YScalingFactor);
	labelBetRing->setGeometry(240*XScalingFactor, 520*YScalingFactor, 140*XScalingFactor, 89*YScalingFactor);
	QPixmap BetRingPixMap(":/Images/Bet_Ring2.gif");
	labelBetRing->setScaledContents(true);
	labelBetRing->setPixmap(BetRingPixMap);

	labelStackSpot = new QLabel(this);
	labelStackSpot->setGeometry(240*XScalingFactor, 665*YScalingFactor, 139*XScalingFactor, 39*YScalingFactor);
	QPixmap StackSpotPixMap(":/Images/StackSpot.png");
	labelStackSpot->setScaledContents(true);
	labelStackSpot->setPixmap(StackSpotPixMap);

	labelHandValueSpot = new QLabel(this);
	labelHandValueSpot->setGeometry(240*XScalingFactor, 655*YScalingFactor, 139*XScalingFactor, 39*YScalingFactor);
	QPixmap HandValueSpotPixMap(":/Images/HandValueSpot.png");
	labelHandValueSpot->setScaledContents(true);
	labelHandValueSpot->setPixmap(HandValueSpotPixMap);
	labelHandValueSpot->setVisible(false);

	labelDealersHandValueSpot = new QLabel(this);
	labelDealersHandValueSpot->setGeometry(240*XScalingFactor, 655*YScalingFactor, 139*XScalingFactor, 39*YScalingFactor);
	QPixmap DealerHandValueSpotPixMap(":/Images/HandValueSpot.png");
	labelDealersHandValueSpot->setScaledContents(true);
	labelDealersHandValueSpot->setPixmap(HandValueSpotPixMap);
	labelDealersHandValueSpot->setVisible(false);

	labelResultsBubble = new QLabel(this);
	labelResultsBubble->setGeometry(25*XScalingFactor, 250*YScalingFactor, 567*XScalingFactor, 165*YScalingFactor);
	QPixmap ResultsBubblePixMap(":/Images/ResultsSummary.png");
	labelResultsBubble->setScaledContents(true);	
	labelResultsBubble->setPixmap(ResultsBubblePixMap);
	labelResultsBubble->setVisible(false);

	labelStatusBubble = new QLabel(this);
	labelStatusBubble->setGeometry(20*XScalingFactor, 15*YScalingFactor, 559*XScalingFactor, 94*YScalingFactor);
//	labelStatusBubble->setGeometry(10.66, 8, 297.97, 50);
	QPixmap StatusBubblePixMap(":/Images/StatusBubble.png");
	labelStatusBubble->setScaledContents(true);
	labelStatusBubble->setPixmap(StatusBubblePixMap);

	labelBetValue = new QLabel(this);
	labelBetValue->setGeometry(110*XScalingFactor, 555*YScalingFactor, 121*XScalingFactor, 41*YScalingFactor);
	labelBetValue->setPalette(*BetValueTextPalette);
	labelBetValue->setFont(LabelFont);
	labelBetValue->setAlignment(Qt::AlignRight);

	labelStackValue = new QLabel(this);
	labelStackValue->setGeometry(250*XScalingFactor, 662*YScalingFactor, 121*XScalingFactor, 41*YScalingFactor);
//	labelStackValue->setGeometry(133, 352.88, 64.50, 21.86);
	labelStackValue->setPalette(*TextPalette);	
	labelStackValue->setFont(LabelFont);
	labelStackValue->setAlignment(Qt::AlignCenter);

	labelGameStatus = new QLabel(this);
	labelGameStatus->setGeometry(30*XScalingFactor, 20*YScalingFactor, 541*XScalingFactor, 81*YScalingFactor);
	labelGameStatus->setPalette(*TextPalette);
	labelGameStatus->setFont(StatusFont);
	labelGameStatus->setAlignment(Qt::AlignCenter);

	labelPlayersHandValue = new QLabel(this);
	labelPlayersHandValue->setPalette(*TextPalette);
	labelPlayersHandValue->setFont(HandValueFont);
	labelPlayersHandValue->setAlignment(Qt::AlignCenter);
	labelPlayersHandValue->setVisible(false);

	labelDealersHandValue = new QLabel(this);
	labelDealersHandValue->setPalette(*TextPalette);
	labelDealersHandValue->setFont(HandValueFont);
	labelDealersHandValue->setAlignment(Qt::AlignCenter);
	labelDealersHandValue->setVisible(false);

	labelResultsSummary = new QLabel(this);
	labelResultsSummary->setGeometry(35*XScalingFactor, 270*YScalingFactor, 547*XScalingFactor, 315*YScalingFactor);
	labelResultsSummary->setPalette(*TextPalette);
	labelResultsSummary->setFont(ResultsFont);
	labelResultsSummary->setAlignment(Qt::AlignTop);
	//labelResultsSummary->raise();
	labelResultsSummary->setVisible(false);

	labelBustText = new QLabel(this);
	labelBustText->setGeometry(160*XScalingFactor, 330*YScalingFactor, 321*XScalingFactor, 141*YScalingFactor);
	QPixmap BustTextPixMap(":/Images/BustText.gif");
	labelBustText->setPixmap(BustTextPixMap);
	labelBustText->setScaledContents(true);
	labelBustText->setVisible(false);

	labelDealersBustText = new QLabel(this);
	labelDealersBustText->setGeometry(160*XScalingFactor, 120*YScalingFactor, 291*XScalingFactor, 111*YScalingFactor);
	labelDealersBustText->setPixmap(BustTextPixMap);
	labelDealersBustText->setScaledContents(true);
	labelDealersBustText->setVisible(false);

	labelBlackjackText = new QLabel(this);
	labelBlackjackText->setGeometry(100*XScalingFactor, 330*YScalingFactor, 400*XScalingFactor, 227*YScalingFactor);
	QPixmap BlackjackTextPixMap(":/Images/BlackjackText.gif");
	labelBlackjackText->setPixmap(BlackjackTextPixMap);
	labelBlackjackText->setScaledContents(true);
	labelBlackjackText->setVisible(false);

	labelDealersBlackjackText = new QLabel(this);
	labelDealersBlackjackText->setGeometry(140*XScalingFactor, 125*YScalingFactor, 320*XScalingFactor, 168*YScalingFactor);
	labelDealersBlackjackText->setPixmap(BlackjackTextPixMap);
	labelDealersBlackjackText->setScaledContents(true);
	labelDealersBlackjackText->setVisible(false);

    newSWd = new DragWidget(this);
	newSWd->populate(5);
	newSWd->setGeometry(15*XScalingFactor, 690*YScalingFactor, 88*XScalingFactor, 61*YScalingFactor);
	newSWd->raise();

	newSWd2 = new DragWidget(this);
	newSWd2->populate(10);
	newSWd2->setGeometry(135*XScalingFactor, 705*YScalingFactor, 88*XScalingFactor, 61*YScalingFactor);
	newSWd2->raise();

	newSWd3 = new DragWidget(this);	
	newSWd3->populate(25);
	newSWd3->setGeometry(265*XScalingFactor, 715*YScalingFactor, 88*XScalingFactor, 61*YScalingFactor);
	newSWd3->raise();

	newSWd4 = new DragWidget(this);	
	newSWd4->populate(50);
	newSWd4->setGeometry(385*XScalingFactor, 705*YScalingFactor, 88*XScalingFactor, 61*YScalingFactor);
	newSWd4->raise();

	newSWd5 = new DragWidget(this);	
	newSWd5->populate(100);
	newSWd5->setGeometry(500*XScalingFactor, 690*YScalingFactor, 88*XScalingFactor, 61*YScalingFactor);
	newSWd5->raise();

	myDragWidget = new DragWidget(this);
	myDragWidget->populate(200);
//	myDragWidget->setGeometry(267, 414, 88, 200);
	myDragWidget->setGeometry(210*XScalingFactor, 414*YScalingFactor, 200*XScalingFactor, 220*YScalingFactor);

	DoneButton = new ClickableLabel(this);
	DoneButton->setGeometry(300*XScalingFactor, 580*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	QPixmap DoneButtonPixMap(":/Images/DoneGreenButtonSmall.png");
	DoneButton->setScaledContents(true);
	DoneButton->setPixmap(DoneButtonPixMap);
	
	HitButton = new ClickableLabel(this);
	HitButton->setGeometry(335*XScalingFactor, 350*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	QPixmap HitButtonPixMap(":/Images/HitButtonSmall.png");
	HitButton->setScaledContents(true);
	HitButton->setPixmap(HitButtonPixMap);
	HitButton->raise();

	StandButton = new ClickableLabel(this);
	StandButton->setGeometry(345*XScalingFactor, 382*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	QPixmap StandButtonPixMap(":/Images/StandButtonSmall.png");
	StandButton->setScaledContents(true);
	StandButton->setPixmap(StandButtonPixMap);

	YesButton = new ClickableLabel(this);
	YesButton->setGeometry(335*XScalingFactor, 350*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	QPixmap YesButtonPixMap(":/Images/YesButtonSmall.png");
	YesButton->setScaledContents(true);
	YesButton->setPixmap(YesButtonPixMap);

	NoButton = new ClickableLabel(this);
	NoButton->setGeometry(345*XScalingFactor, 382*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	QPixmap NoButtonPixMap(":/Images/NoButtonSmall.png");
	NoButton->setScaledContents(true);
	NoButton->setPixmap(NoButtonPixMap);

	SurrenderButton = new ClickableLabel(this);
	SurrenderButton->setGeometry(355*XScalingFactor, 414*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	QPixmap SurrenderButtonPixMap(":/Images/SurrenderButtonSmall.png");
	SurrenderButton->setScaledContents(true);
	SurrenderButton->setPixmap(SurrenderButtonPixMap);

	SplitButton = new ClickableLabel(this);
	SplitButton->setGeometry(365*XScalingFactor, 446*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	QPixmap SplitButtonPixMap(":/Images/SplitButtonSmall.png");
	SplitButton->setScaledContents(true);
	SplitButton->setPixmap(SplitButtonPixMap);

	DoubleButton = new ClickableLabel(this);
	DoubleButton->setGeometry(375*XScalingFactor, 478*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	QPixmap DoubleButtonPixMap(":/Images/DoubleButtonSmall.png");
	DoubleButton->setScaledContents(true);
	DoubleButton->setPixmap(DoubleButtonPixMap);


//##### func

//	updateStackValue("100");
	myDragWidget->raise();
//	MakeConnections();
	myThread = new GameThread();
	connect(myThread, SIGNAL(updatePlayersHand(QString,int)), this, SLOT(updatePlayersHand(QString,int)));
	connect(myThread, SIGNAL(updateDealersHand(QString,int)), this, SLOT(updateDealersHand(QString,int)));
	connect(myThread, SIGNAL(updateDealersHandValue(QString)), this, SLOT(updateDealersHandValue(QString)));
	connect(myThread, SIGNAL(updatePlayersHandValue(QString)), this, SLOT(updatePlayersHandValue(QString)));
	connect(myThread, SIGNAL(updateStack(QString)), this, SLOT(updateStackValue(QString)));
	connect(myThread, SIGNAL(updateBet(QString)), this, SLOT(updateBetValue(QString)));
	connect(myDragWidget, SIGNAL(AddToBet(float)), myThread, SIGNAL(IncreaseBet(float)));
	connect(myDragWidget, SIGNAL(RemoveFromBet(float)), myThread, SIGNAL(DecreaseBet(float)));
/*	connect(newSWd, SIGNAL(RemoveFromBet(float)), myThread, SIGNAL(DecreaseBet(float)));
	connect(newSWd2, SIGNAL(RemoveFromBet(float)), myThread, SIGNAL(DecreaseBet(float)));
	connect(newSWd3, SIGNAL(RemoveFromBet(float)), myThread, SIGNAL(DecreaseBet(float)));
	connect(newSWd4, SIGNAL(RemoveFromBet(float)), myThread, SIGNAL(DecreaseBet(float)));
	connect(newSWd5, SIGNAL(RemoveFromBet(float)), myThread, SIGNAL(DecreaseBet(float)));*/
	//connect(myThread, SIGNAL(updatePlayersName(QString)), this, SLOT(updatePlayersName(QString)));
	connect(myThread, SIGNAL(clearPlayersHand()), this, SLOT(clearPlayersHand()));
	connect(myThread, SIGNAL(clearDealersHand()), this, SLOT(clearDealersHand()));
	connect(myThread, SIGNAL(updateStatus(QString)), this, SLOT(updateGameStatus(QString)));
	connect(myThread, SIGNAL(updateResultsSummary(QString)), this, SLOT(updateResultsSummary(QString)));
	connect(myThread, SIGNAL(HideResultsSummary()), this, SLOT(HideResultsSummary()));
	connect(myThread, SIGNAL(Clearchips()), myDragWidget, SLOT(ClearChips()));
	connect(myThread, SIGNAL(ButtonVisibility(bool, bool, bool, bool, bool, bool, bool, bool)), this, SLOT(HideButtons(bool, bool, bool, bool, bool, bool, bool, bool)));
	connect(myThread, SIGNAL(ResultTextVisibility(bool, bool, bool, bool)), this, SLOT(ResultText(bool, bool, bool, bool)));
	connect(myThread, SIGNAL(HandValueSpotsVisibility()), this, SLOT(HideHandValueSpots()));
//	connect(myThread, SIGNAL(TriggerRestart()), this, SLOT(Restart()));
	connect(myThread, SIGNAL(DisableChips(bool)), this, SLOT(DisableChips(bool)));
	connect(myThread, SIGNAL(GameOver()), this, SLOT(PositionYesNo()));
	connect(myThread, SIGNAL(PlayWinSound()), this, SLOT(PlayWinSound()));
	connect(myThread, SIGNAL(PlayLoseSound()), this, SLOT(PlayLoseSound()));
	connect(myDragWidget, SIGNAL(PlayChipSound()), this, SLOT(PlayChipSound()));
	connect(newSWd, SIGNAL(PlayChipSound()), this, SLOT(PlayChipSound()));
	connect(newSWd2, SIGNAL(PlayChipSound()), this, SLOT(PlayChipSound()));
	connect(newSWd3, SIGNAL(PlayChipSound()), this, SLOT(PlayChipSound()));
	connect(newSWd4, SIGNAL(PlayChipSound()), this, SLOT(PlayChipSound()));
	connect(newSWd5, SIGNAL(PlayChipSound()), this, SLOT(PlayChipSound()));

	// Placing bet
	/*connect(myDragWidget, SIGNAL(BetPlaced(int)), myThread, SLOT(RemoveFromStack(int)));
	connect(myDragWidget, SIGNAL(BetReturned(int)), myThread, SLOT(ReturnBet(int)));
	connect(newSWd, SIGNAL(BetReturned(int)), myThread, SLOT(ReturnBet(int)));
	connect(newSWd2, SIGNAL(BetReturned(int)), myThread, SLOT(ReturnBet(int)));
	connect(newSWd3, SIGNAL(BetReturned(int)), myThread, SLOT(ReturnBet(int)));
	connect(newSWd4, SIGNAL(BetReturned(int)), myThread, SLOT(ReturnBet(int)));
	connect(newSWd5, SIGNAL(BetReturned(int)), myThread, SLOT(ReturnBet(int)));*/

	// #1
    QSignalMapper *m_sigmapper;
	m_sigmapper = new QSignalMapper();

	// #2

	connect(HitButton, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
	connect(StandButton, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
	connect(DoubleButton, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
	connect(SplitButton, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
	connect(SurrenderButton, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
	connect(YesButton, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
	connect(NoButton, SIGNAL(clicked()), m_sigmapper, SLOT(map()));

	connect(DoneButton, SIGNAL(clicked()), myThread, SLOT(BettingDone()));
/////////////////////////
	connect(NewGame, SIGNAL(triggered()), m_sigmapper, SLOT(map()));
////////////////////////

	// #3
	m_sigmapper->setMapping(HitButton, 1);
	m_sigmapper->setMapping(StandButton, 2);
	m_sigmapper->setMapping(DoubleButton, 3);
	m_sigmapper->setMapping(SplitButton, 4);
	m_sigmapper->setMapping(SurrenderButton, 5);
	m_sigmapper->setMapping(YesButton, 6);
	m_sigmapper->setMapping(NoButton, 7);
	m_sigmapper->setMapping(NewGame, 8);

	// #4
	connect(m_sigmapper, SIGNAL(mapped(int)), myThread, SLOT(ChoiceMade(int)));
	//connect(myThread, SIGNAL(finished()), myThread, SLOT(deleteLater()));
	//connect(this, SIGNAL(threadStop()), myThread, SLOT(deleteLater()));
//	connect(myThread, SIGNAL(finished()), this, SLOT(MakeConnections()));
	connect(myThread, SIGNAL(finished()), this, SLOT(PositionYesNo()));
	
	/*HideResultsSummary();
	updateStackValue("100");
	myThread->start();*/
	MakeConnections();

//	CollectBets();
//	InitialDeal();
//	InsuranceOffers();
}

MainWindow::~MainWindow()
{
	//delete myThread;
    delete ui;
}

void MainWindow::toggleStatusbar()
{
	if (ToggleSound->isChecked())
	{
		printf("IS checked!\n");
	}
	else
	{
		printf("IS NOT checked!\n");
	}
}

void MainWindow::MakeConnections()
{
	HideResultsSummary();
	updateStackValue("100");
	myThread->start();
}

void MainWindow::DisableChips(bool ActiveState)
{
	newSWd->setInactive(ActiveState);
	newSWd2->setInactive(ActiveState);
	newSWd3->setInactive(ActiveState);
	newSWd4->setInactive(ActiveState);
	newSWd5->setInactive(ActiveState);
}

void MainWindow::HideHandValueSpots()
{
	labelHandValueSpot->setVisible(false);
	labelDealersHandValueSpot->setVisible(false);
	labelPlayersHandValue->setVisible(false);
	labelDealersHandValue->setVisible(false);
}

void MainWindow::PositionYesNo()
{
	YesButton->setGeometry(200*XScalingFactor, 360*YScalingFactor, 130*XScalingFactor, 37*YScalingFactor);
	NoButton->setGeometry(320*XScalingFactor, 360*YScalingFactor, 130*XScalingFactor, 37*YScalingFactor);
	YesButton->setVisible(true);
	NoButton->setVisible(true);
	YesButton->raise();
	NoButton->raise();
	connect(YesButton, SIGNAL(clicked()), this, SLOT(MakeConnections()));
	connect(NoButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MainWindow::DisplayAboutBox()
{
	QMessageBox msgBox;
	QPixmap AboutBoxPixMap("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/JimboFace.gif");
	AboutBoxPixMap = AboutBoxPixMap.scaled(100, 100);
	msgBox.setWindowTitle("About Blackjack");
	QString labelText = "<b><i><font size = 4>Blackjack</i></b><br>Another JimboMonkey Production<br>Version 1.0<br><br>Copyright \x00A9 2013 JimboMonkey Productions";
	QString licenseText = "<b><i><font size = 4>License</i></b><br>License blurbbb<br>vlaaahh";
	//labelText.append("Blackjack");
//	labelText.append("</i></b>");
	msgBox.setText(labelText);
	//msgBox.setText("Blackjack\nAnother JimboMonkey Production\nVersion 1.0");
	QSpacerItem* horizontalSpacer = new QSpacerItem(500, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
	QGridLayout* layout = (QGridLayout*)msgBox.layout();
	layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
//	msgBox.setInformativeText("Another JimboMonkey Production");
	msgBox.setIconPixmap(AboutBoxPixMap);
	QPushButton *LicenceButton = msgBox.addButton("&Licence", QMessageBox::ActionRole);
	QPushButton *CreditsButton = msgBox.addButton("&Credits", QMessageBox::AcceptRole);
	QPushButton *OkButton = msgBox.addButton("OK", QMessageBox::AcceptRole);
	LicenceButton->setGeometry(50, 300, 100, 100);
	connect(LicenceButton, SIGNAL(clicked()), this, SLOT(PlayWinSound()));
	msgBox.exec();
	/*if(msgBox.exec() == QMessageBox::Yes)
	{
		// do something
	}
	else
	{
		// do something else
	}*/
}

void MainWindow::HideButtons(bool HitVisible, bool StandVisible, bool SurrenderVisible, bool DoubleVisible, bool SplitVisible, bool YesVisible, bool NoVisible, bool DoneVisible)
{
	HitButton->setVisible(HitVisible);
	StandButton->setVisible(StandVisible);
	SurrenderButton->setVisible(SurrenderVisible);
	DoubleButton->setVisible(DoubleVisible);
	SplitButton->setVisible(SplitVisible);
	YesButton->setVisible(YesVisible);
	NoButton->setVisible(NoVisible);
	DoneButton->setVisible(DoneVisible);
	HitButton->raise();
	StandButton->raise();
	SurrenderButton->raise();
	DoubleButton->raise();
	SplitButton->raise();
	YesButton->raise();
	NoButton->raise();
	DoneButton->raise();


//	myDragWidget->raise();
}

void MainWindow::ResultText(bool BustVisible, bool DealerBustVisible, bool BlackjackVisible, bool DealerBlackjackVisible)
{
	labelBustText->setVisible(BustVisible);
	labelDealersBustText->setVisible(DealerBustVisible);
	labelBustText->raise();
	labelDealersBustText->raise();

	labelBlackjackText->setVisible(BlackjackVisible);
	labelDealersBlackjackText->setVisible(DealerBlackjackVisible);
	labelBlackjackText->raise();
	labelDealersBlackjackText->raise();

	if(BustVisible == true or DealerBustVisible == true)
	{
		media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/Bust.mp3"));
	}
	else if(BlackjackVisible == true)
	{
		media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/Yeah.mp3"));
	}
	else if(DealerBlackjackVisible == true)
	{
		media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/Gasp.mp3"));
	}
	if (ToggleSound->isChecked())
	{
		media->play();
	}
}

void MainWindow::updatePlayersHand(QString LoadCardName, int CardPosition)
{
	QImage myImage;

	myImage.load(LoadCardName);

	if(CardPosition > 1)
	{
		media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/DrawCard.mp3"));
		if (ToggleSound->isChecked())
		{
			media->play();
		}
	}
//	PlayersHand[CardPosition]->setScaledContents(true);
	PlayersHand[CardPosition]->setPixmap(QPixmap::fromImage(myImage).scaledToWidth(161*XScalingFactor));
	PlayersHand[CardPosition]->show();
	PlayersHand[CardPosition]->raise();
	int NewPos = 216 - ((CardPosition + 1) * 12);
	PlayersCards->setGeometry(NewPos*XScalingFactor, 310*YScalingFactor, 541*XScalingFactor, 331*YScalingFactor);

	labelHandValueSpot->setGeometry((238 - (CardPosition + 1) * 12)*XScalingFactor, 470*YScalingFactor, 55*XScalingFactor, 55*YScalingFactor);
	labelPlayersHandValue->setGeometry((210 - (CardPosition + 1) * 12)*XScalingFactor, 482*YScalingFactor, 111*XScalingFactor, 31*YScalingFactor);
	HitButton->setGeometry((315 + (CardPosition + 1) * 10)*XScalingFactor, 350*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	YesButton->setGeometry((315 + (CardPosition + 1) * 10)*XScalingFactor, 350*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	StandButton->setGeometry((325 + (CardPosition + 1) * 10)*XScalingFactor, 382*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	NoButton->setGeometry((325 + (CardPosition + 1) * 10)*XScalingFactor, 382*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	SurrenderButton->setGeometry((335 + (CardPosition + 1) * 10)*XScalingFactor, 414*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	SplitButton->setGeometry((345 + (CardPosition + 1) * 10)*XScalingFactor, 446*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	DoubleButton->setGeometry((355 + (CardPosition + 1) * 10)*XScalingFactor, 478*YScalingFactor, 100*XScalingFactor, 37*YScalingFactor);
	labelHandValueSpot->raise();
	labelPlayersHandValue->raise();
}

void MainWindow::updateDealersHand(QString LoadCardName, int CardPosition)
{
	QImage myImage;

	myImage.load(LoadCardName);	

	if(CardPosition > 0 and LoadCardName != "DealerCards/CardBack.png")
	{
		media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/DrawCard.mp3"));
		if (ToggleSound->isChecked())
		{
			media->play();
		}
	}
//	DealersHand[CardPosition]->setScaledContents(true);
	DealersHand[CardPosition]->setPixmap(QPixmap::fromImage(myImage).scaledToWidth(94*XScalingFactor));
	DealersHand[CardPosition]->show();
	DealersHand[CardPosition]->raise();
	int NewPos = 250 - ((CardPosition + 1) * 10);
	DealersCards->setGeometry(NewPos*XScalingFactor, 50*YScalingFactor, 541*XScalingFactor, 331*YScalingFactor);
	labelDealersHandValueSpot->setGeometry((265 - (CardPosition + 1) * 10)*XScalingFactor, 170*YScalingFactor, 55*XScalingFactor, 55*YScalingFactor);
	labelDealersHandValue->setGeometry((235 - (CardPosition + 1) * 10)*XScalingFactor, 181*YScalingFactor, 111*XScalingFactor, 31*YScalingFactor);
	labelDealersHandValueSpot->raise();
	labelDealersHandValue->raise();
}

void MainWindow::PlayWinSound()
{
	media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/Ching.mp3"));
	if (ToggleSound->isChecked())
	{
		media->play();
	}
}

void MainWindow::PlayLoseSound()
{
	media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/Punch.mp3"));
	if (ToggleSound->isChecked())
	{
		media->play();
	}
}

void MainWindow::PlayChipSound()
{
	int iSecret;

	/* initialize random seed: */
	srand (time(NULL));

	/* generate secret number between 1 and 3: */
	iSecret = rand() % 3 + 1;

	switch (iSecret)
	{
		case 1:
			media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/Chip.mp3"));
			break;
		case 2:
			media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/Chip2.mp3"));
			break;
		case 3:
			media->setCurrentSource(QUrl("/home/jimbo/Dropbox/QtProjects/BlackJackNewGUI/Sounds/Chip3.mp3"));
			break;
	}
	if (ToggleSound->isChecked())
	{
		media->play();
	}
}

void MainWindow::updateGameStatus(QString Status)
{
	labelGameStatus->setText(Status);
}

void MainWindow::updateResultsSummary(QString ResultsSummary)
{
	labelResultsSummary->setVisible(true);
	labelResultsBubble->setVisible(true);
	labelResultsBubble->raise();
	labelResultsSummary->raise();
	labelResultsSummary->setText(ResultsSummary);
	labelResultsSummary->setAlignment(Qt::AlignHCenter);
}

void MainWindow::HideResultsSummary()
{
	labelResultsSummary->setVisible(false);
	labelResultsBubble->setVisible(false);
}

void MainWindow::updatePlayersHandValue(QString HandValue)
{
	labelPlayersHandValue->setText(HandValue);
	labelHandValueSpot->setVisible(true);
	labelPlayersHandValue->setVisible(true);
}

void MainWindow::updateDealersHandValue(QString HandValue)
{
	labelDealersHandValue->setText(HandValue);
	labelDealersHandValueSpot->setVisible(true);
	labelDealersHandValue->setVisible(true);
}

void MainWindow::updateStackValue(QString StackValue)
{
	labelStackValue->setText(StackValue);
	float dec = StackValue.toFloat();

	if(dec >= 5.0)
	{
		newSWd->setVisible(true);
	}
	else
	{
		newSWd->setVisible(false);
	}

	if(dec >= 10.0)
	{
		newSWd2->setVisible(true);
	}
	else
	{
		newSWd2->setVisible(false);
	}

	if(dec >= 25.0)
	{
		newSWd3->setVisible(true);
	}
	else
	{
		newSWd3->setVisible(false);
	}

	if(dec >= 50.0)
	{
		newSWd4->setVisible(true);
	}
	else
	{
		newSWd4->setVisible(false);
	}

	if(dec >= 100.0)
	{
		newSWd5->setVisible(true);
	}	
	else
	{
		newSWd5->setVisible(false);
	}
}

void MainWindow::updateBetValue(QString BetValue)
{
	if(BetValue == "0")
	{
		BetValue = "";
		DoneButton->setVisible(false);
	}
	else
	{
		DoneButton->setVisible(true);
	}
	labelBetValue->setText(BetValue);
}

void MainWindow::clearPlayersHand()
{
	for(int a = 0; a < 11; a++)
	{
		PlayersHand[a]->hide();
	}
}

void MainWindow::clearDealersHand()
{
	for(int a = 0; a < 11; a++)
	{
		DealersHand[a]->hide();
	}
}

void MainWindow::Restart()
{
	myThread->terminate();
	printf("called me\n");
	while(myThread->isFinished() != true)
	{
		//printf("not finished");
	}
	printf("got here\n");
//	MakeConnections();
/*	while (ToggleSound->isChecked())
	{
	}
	printf("boooo!");*/
}



