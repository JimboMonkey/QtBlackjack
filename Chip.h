
#include <QLabel>
#include <QEvent>

class Chip: public QLabel
{
	Q_OBJECT

	public:
		Chip(QWidget *parent = 0); 
		void SetValue(int);
		int GetValue();
		void SetUsed();
		bool CheckChipUsed();

	private:
		int ChipValue;
		bool ChipUsed;
};


