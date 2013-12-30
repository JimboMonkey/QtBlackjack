
#include <QLabel>
#include <QEvent>

class MyLabel: public QLabel
{
	Q_OBJECT

	public:
		MyLabel(QWidget *parent = 0); 
		void SetValue(int);
		int GetValue();
		int myvalue;
		bool ChipUsed;
		bool CheckChipUsed();
		void SetUsed();
		void changeEvent(QEvent * event);
};


