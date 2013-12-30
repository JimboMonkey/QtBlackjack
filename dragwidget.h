
#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QStackedWidget>
#include <vector>
#include "mylabel.h"

class QDragEnterEvent;
class QDropEvent;

class DragWidget: public QStackedWidget
{
	Q_OBJECT

	public:
		DragWidget(QWidget *parent=0);
		int pos;
		void populate(int);
		void AddChip(MyLabel* MyChip);
		void RemoveChip();
		void setInactive(bool activeState);
//		void ClearChips();
		float XScalingFactor;
		float YScalingFactor;

	private:
		std::vector<MyLabel*> ListChips;
		bool Active;
		

	protected:
		void dragEnterEvent(QDragEnterEvent *event);
	    void dragMoveEvent(QDragMoveEvent *event);
	    void dropEvent(QDropEvent *event);
	    void mousePressEvent(QMouseEvent *event);

	signals:
		void BetPlaced(int);
		void BetReturned(int);
		void AddToBet(float);
		void RemoveFromBet(float);
		void PlayChipSound();

	private slots:
		void ClearChips();


};

#endif
