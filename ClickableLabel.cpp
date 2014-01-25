
#include "ClickableLabel.hpp"

ClickableLabel::ClickableLabel(QWidget* parent): QLabel(parent)
{
}

void ClickableLabel::mousePressEvent()
{
	  emit clicked();
}

