
#ifndef CLICKABLELABEL_HPP
#define CLICKABLELABEL_HPP

#include <QLabel>

class ClickableLabel: public QLabel
{
	Q_OBJECT

	public:
		ClickableLabel(QWidget *parent = 0); 

	protected:
		void mousePressEvent();

	signals:
		void clicked();
};

#endif

