
#ifndef ChipPile_H
#define ChipPile_H

#include <QFrame>
#include <QStackedWidget>
#include <vector>
#include "Chip.h"

class QDragEnterEvent;
class QDropEvent;

class ChipPile: public QStackedWidget
{
	Q_OBJECT

	public:
		ChipPile(QWidget *parent=0, bool=false);
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
		void IncreaseBet(float);
		void DecreaseBet(float);
		void PlayChipSound();

	private slots:
		void ClearChips();


};

#endif
