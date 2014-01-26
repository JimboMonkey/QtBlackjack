
#include "ClickableLabel.hpp"

ClickableLabel::ClickableLabel(QWidget* parent): QLabel(parent)
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
	qDebug() << event;	
	emit clicked();
}

