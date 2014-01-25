
#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QStackedWidget>
#include <vector>
#include "Chip.h"

class QDragEnterEvent;
class QDropEvent;

class DragWidget: public QStackedWidget
{
	Q_OBJECT

	public:
		DragWidget(QWidget *parent=0, bool=false);
		int pos;
		void populate(int);
		void AddChip(Chip* MyChip);
		void RemoveChip();
		void setInactive(bool activeState);
		float XScalingFactor;
		float YScalingFactor;

	private:
		std::vector<Chip*> ListChips;
		bool Active;
		

	protected:
		void dragEnterEvent(QDragEnterEvent *event);
	    void dragMoveEvent(QDragMoveEvent *event);
	    void dropEvent(QDropEvent *event);
	    void mousePressEvent(QMouseEvent *event);

	signals:
		void AddToBet(float);
		void RemoveFromBet(float);
		void PlayChipSound();

	private slots:
		void ClearChips();


};

#endif
