#include <QtGui>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "dragwidget.h"

#include <iostream>

/*#define XScalingFactor 0.533
#define YScalingFactor 0.711

#define XScalingFactor 1
#define YScalingFactor 1*/

DragWidget::DragWidget(QWidget *parent): QStackedWidget(parent)
{

	QRect Screen = QApplication::desktop()->screenGeometry();

	float wScale = Screen.width() / 1920.0;
	float hScale = Screen.height() / 1080.0;

	XScalingFactor = wScale;
	YScalingFactor = hScale;

	setMinimumSize(200, 220);
	setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
	setAcceptDrops(true);
	setFrameShape (NoFrame);
	Active = true;

	pos = 125;
}

void DragWidget::setInactive(bool activeState)
{
	Active = activeState;
}

void DragWidget::populate(int ChipValue)
{
//     QLabel *boatIcon = new QLabel(this);
	MyLabel *boatIcon = new MyLabel(this);
	
	switch (ChipValue)
	{
		case 5:
			boatIcon->setPixmap(QPixmap("images/RedChipCroppedSmall.gif").scaledToWidth(88*XScalingFactor));
			break;
		case 10:
			boatIcon->setPixmap(QPixmap("images/BlueChipCroppedSmall.gif").scaledToWidth(88*XScalingFactor));
			break;
		case 25:
			boatIcon->setPixmap(QPixmap("images/GreenChipCroppedSmall.gif").scaledToWidth(88*XScalingFactor));
			break;
		case 50:
			boatIcon->setPixmap(QPixmap("images/OrangeChipCroppedSmall.gif").scaledToWidth(88*XScalingFactor));
			break;
		case 100:
			boatIcon->setPixmap(QPixmap("images/BlackChipCroppedSmall.gif").scaledToWidth(88*XScalingFactor));
			break;
	}	

	boatIcon->setEnabled(true);
	boatIcon->show();
	boatIcon->setAttribute(Qt::WA_DeleteOnClose);
	boatIcon->setGeometry(0, 0, 88*XScalingFactor, 61*YScalingFactor);
	// boatIcon->setScaledContents(true);
	boatIcon->SetValue(ChipValue);
}

void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("application/x-dnditemdata"))
	{
		if (event->source() == this)
		{
			event->setDropAction(Qt::MoveAction);
			event->accept();
		}
		else
		{
			event->acceptProposedAction();
		}
	}
	else
	{
		event->ignore();
	}
}

void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{
	if (event->mimeData()->hasFormat("application/x-dnditemdata")) 
	{
		if (event->source() == this) 
		{
			event->setDropAction(Qt::MoveAction);
			event->accept();
		}
		else
		{
			event->acceptProposedAction();
		}
	}
	else
	{
		event->ignore();
	}
}

void DragWidget::AddChip(MyLabel* MyChip)
{
	ListChips.push_back(MyChip);
}

void DragWidget::RemoveChip()
{
	ListChips.pop_back();
}

void DragWidget::ClearChips()
{
	unsigned int i;

	printf("List is %d in size\n", ListChips.size());

	for (i = 0; i < ListChips.size(); i++)
	{
		ListChips.at(i)->close();
	}
	ListChips.clear();
	printf("List is %d in size\n", ListChips.size());
    pos = 125;
	emit BetPlaced(0);
}

void DragWidget::dropEvent(QDropEvent *event)
{
	printf("\n\npos = %d\n\n", pos);
	if (event->mimeData()->hasFormat("application/x-dnditemdata")) 
	{
		QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
		QDataStream dataStream(&itemData, QIODevice::ReadOnly);

		QPixmap pixmap;
		QPoint offset;
		int myvalue, valuetopass;
		bool UsedValue;
		dataStream >> pixmap >> offset >> myvalue >> valuetopass >> UsedValue;

		if(UsedValue == true)
		{
			printf("Came from bet box with a value of %d\n",valuetopass);
			printf("\n\n\nNumber of chips in pile = %d\n\n\n", ListChips.size());
			//pos = 280 - (ListChips.size() * 8);
			//emit BetReturned(valuetopass);
			//RemoveFromBet(valuetopass);
		}
		else
		{
			printf("Came from a stack box\n");
			if (event->source() == this) 
			{
				printf("Icon dropped into the same box!\n");
           /*  event->setDropAction(Qt::MoveAction);
             event->accept();
			 pos -= 8;
			 newIcon->setGeometry(20, pos, 100,72);*/
			} 
			else 
			{

/*  Limit the chip stack to 15 */

				if(ListChips.size() < 15)
				{
					AddToBet(valuetopass);
					MyLabel *newIcon = new MyLabel(this);
					newIcon->setPixmap(pixmap);
					newIcon->move(event->pos() - offset);
					newIcon->show();
					newIcon->raise();
					newIcon->setAttribute(Qt::WA_DeleteOnClose);
					newIcon->SetValue(valuetopass);
					newIcon->SetUsed();
					printf("Icon dropped into a different box!\n");
					event->acceptProposedAction();
					pos -= 8*YScalingFactor;
	/* The value of pos in the line below needs to start at 20 to sit on the wooden sill */

					/********************** rand **********************/

					int iSecret, yPos;

					/* initialize random seed: */
					srand (time(NULL));

					/* generate secret number between 1 and 10: */
					iSecret = rand() % 5;
					yPos = rand() % 2;

					/***************************************************/

					newIcon->setGeometry((56 +iSecret)*XScalingFactor, (pos+yPos)*YScalingFactor, 88*XScalingFactor,61*YScalingFactor);
					//newIcon->setScaledContents(true);
	//			 newIcon->setGeometry(0, 0, 100,72);
					printf("Icon contained value %d\n", valuetopass);
					emit BetPlaced(valuetopass);
					AddChip(newIcon);
					if(valuetopass == 20)
					{
						//ClearChips();
					}
				}
			}
		} 
	}
	else 
	{
		event->ignore();
	}
	printf("\n\n\nNumber of chips in pile = %d\n\n\n", ListChips.size());
}

void DragWidget::mousePressEvent(QMouseEvent *event)
{
	int betstackvalue =0;
	setCursor(Qt::ClosedHandCursor);
//     QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
	MyLabel *child = static_cast<MyLabel*>(childAt(event->pos()));
	// child->setScaledContents(true);
//	 child->setGeometry(0, 0, 88*XScalingFactor, 61*YScalingFactor);
	if (!child)
		return;

	if(Active == false)
	{
		printf("DISABLED!!!!\n");
		return;
	}
	else
	{
		printf("ENABLED!!!!\n");
	}

	QPixmap pixmap = *child->pixmap();
	int myvalue = 5;

	int valuetopass = 0;
	valuetopass = child->GetValue();
	bool UsedValue = child->CheckChipUsed();
	//printf("value to pass = %d\n", valuetopass);

	printf("Used Value = %d\n", UsedValue);
	printf("\n\nNumber of chips in pile = %d", ListChips.size());
	if((ListChips.size() - 1) != -1)
	{
		//Clicked on chip in the bet pile
		pos = (125 - ((ListChips.size() - 1) * (8*YScalingFactor)));

		std::cout << "\nThe chip on the top of the betting pile is a " << ListChips.back()->GetValue() << "\n";

		if(child == ListChips.back())
		{
			std::cout << "You clicked on the chip at the top of the betting pile\n\n";			
		}
		else
		{
			std::cout << "You clicked on a chip within the betting pile\n\n";
			return;			
		}

		std::cout << "\nThe betting chip pile contains:\n\n";

	   	for (unsigned i=0; i<ListChips.size(); i++)
		{
		    std::cout << "A " << ListChips.at(i)->GetValue() << " chip";
			if(ListChips.at(i) == child)
			{
				printf(" that you clicked on\n");
			}
			else
			{
				printf("\n");
			}
		}
	}

/***********************************************/
	QByteArray itemData;
	QDataStream dataStream(&itemData, QIODevice::WriteOnly);
	dataStream << pixmap << QPoint(event->pos() - child->pos()) << myvalue << valuetopass << UsedValue;

	QMimeData *mimeData = new QMimeData;
	mimeData->setData("application/x-dnditemdata", itemData);

	QDrag *drag = new QDrag(this);
	drag->setMimeData(mimeData);
	QPixmap scaledPixmap = pixmap.scaledToWidth(88*XScalingFactor, Qt::SmoothTransformation);
	drag->setPixmap(scaledPixmap);
	drag->setHotSpot(event->pos() - child->pos());

	/* Comment next 6 lines to stop auto-regeneration */
	QPixmap tempPixmap = scaledPixmap;
    /* QPainter painter;
     painter.begin(&tempPixmap);
     painter.fillRect(pixmap.rect(), QColor(148, 0, 241, 127));
     painter.end();*/
	child->setPixmap(tempPixmap);

	if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
	{
		//  child->close();
		printf("im here dumbass!\n");
	}
	else
	{
		//	child->close();
		/* Comment next 2 lines to stop auto-regeneration */
		//child->show();
		//child->setPixmap(pixmap);
		printf("or here! deal with it!\n");
		////////////////////////////////////////////////////
		if(UsedValue == false)
		{
			printf("woo woo!\n");
				
			//	child->close();
			/* Comment next 2 lines to stop auto-regeneration */
			child->show();
			child->setPixmap(scaledPixmap);
		}
		else
		{
			printf("poo poo!\n");
			RemoveChip();				
			child->close();
		}
		///////////////////////////////////////////////
		emit PlayChipSound();
	}
/*********************************************/
	if(UsedValue == true)
	{
		// Clicked on bet pile
		printf("you clicked on the bet pile\n");
		printf("there are %d chips in this pile\n", ListChips.size());
		if(ListChips.size() == 0)	
		{
			//RemoveFromBet(valuetopass);
			//updateBet(0.0);
		}
		else
		{
			for (unsigned ji=0; ji<ListChips.size(); ji++)
			{
			    betstackvalue += ListChips.at(ji)->GetValue();
			}
			
		//	updateBet(betstackvalue);
		}
	//	printf("REMOVE %d !!!!!!!!!!!!\n", valuetopass);
		RemoveFromBet(valuetopass);
	}
	setCursor(Qt::OpenHandCursor);
}


