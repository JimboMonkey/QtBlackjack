#-------------------------------------------------
#
# Project created by QtCreator 2010-05-25T22:26:36
#
#-------------------------------------------------

TARGET = Example
TEMPLATE = app

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
		dragwidget.cpp\
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
			dragwidget.h\
			Chip.h\
			ClickableLabel.hpp

#FORMS    += mainwindow.ui

QT += phonon

RESOURCES = Blackjack.qrc
