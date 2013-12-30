
#include "mylabel.h"

#include <iostream>
using namespace std;


MyLabel::MyLabel(QWidget* parent): QLabel(parent)
{
	cout << "oh hello! chip created!!!" << endl;
	ChipUsed = false;
}

void MyLabel::SetValue(int newValue)
{
	myvalue = newValue;
}

int MyLabel::GetValue()
{
	return myvalue;
}

bool MyLabel::CheckChipUsed()
{
	return ChipUsed;
}

void MyLabel::SetUsed()
{
	ChipUsed = true;
}

void MyLabel::changeEvent(QEvent * event)
{
	if(event->type()==QEvent::EnabledChange)
	{ 
		cout << "ohhhhhhhh who is changing my enabled setting?!" << endl;

	}

}
