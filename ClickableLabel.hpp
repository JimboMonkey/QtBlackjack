
#ifndef CLICKABLELABEL_HPP
#define CLICKABLELABEL_HPP

#include <QLabel>
#include <QDebug>

class ClickableLabel: public QLabel
{
	Q_OBJECT

	public:
		ClickableLabel(QWidget *parent = 0); 

	protected:
		void mousePressEvent(QMouseEvent* event);

	signals:
		void clicked();
};

#endif

