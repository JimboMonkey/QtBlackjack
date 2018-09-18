QtBlackjack
===========

A blackjack game with a Qt GUI. This game aims to mimic the version played at casinos, allowing you to double, split (infinitely), surrender, and place insurance bets.

To build, just run qmake from within the directory, followed by make. To run, just enter ./blackjack

You start with 100 units in your stack and drag and drop chips to place your bet.

The game will let you know what options you have at every stage of play.

After your turn, the dealer plays, before a summary of the scores is displayed. The dealer will keep drawing to 17 or higher.

If you run out of money, the game will end (with an option to start again).

Hitting will draw another card for your hand. If you draw over 21 you will go bust for that hand.

Aces are valued as either 1 or 11 to the player's convenience. If you are holding ace/s the game will automatically adjust your hand value to your advantage.

Standing will end your play on a round. You will stand automatically if you draw to 21.

Doubling will double your bet and will draw one more card only. It can only be chosen on the initial play of a hand.

Splitting is possible if you have two cards of the same value. Splitting will separate these two cards and will draw a new card against each one, creating 2 hands from one. This game allows for infinite splits, so if you keep drawing the same value cards, you can keep splitting (as long as you can afford it!) It can only be chosen on the initial play of a hand.

Surrendering returns half of your bet to the dealer and you skip the round.

If the dealer is showing an ace on their initial hand, and you can afford it, you will be offered insurance. This is a side bet of half of your original bet. If you accept this offer, and the dealer has blackjack, you win this insurance bet. If the dealer doesn't have blackjack, you lose this insurance bet.

Sound FX can be toggled on or off from the menu.

Enjoy!

JimboMonkey
