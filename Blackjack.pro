#-------------------------------------------------
#
# Project created by QtCreator 2010-05-25T22:26:36
#
#-------------------------------------------------

TARGET = blackjack
TEMPLATE = app

# Comment out the line below to enable debugging
DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += main.cpp\
        mainwindow.cpp\
		Table.cpp\
		Croupier.cpp\
		Player.cpp\
		Card.cpp\
		Participant.cpp\
		Box.cpp \
		GameThread.cpp\
		ChipPile.cpp\
		Chip.cpp\
		ClickableLabel.cpp

HEADERS  += mainwindow.h\
			Table.hpp\
			Croupier.hpp\
			Player.hpp\
			Card.hpp\
			Participant.hpp\
			Box.hpp\
			GameThread.hpp\
			ChipPile.hpp\
			Chip.h\
			ClickableLabel.hpp

QT += widgets
QT += multimedia

RESOURCES = Blackjack.qrc
