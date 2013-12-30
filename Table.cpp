
#include "Table.hpp"

/* List all players still in the game and their stack value */
void Table::ListPlayers() const
{
	int i;

	cout << endl << "There are " << Boxes.size() << " players sat at the table: " << endl << endl;

	for (i = 0; i < Boxes.size(); i++)
	{
		cout << "  " << Boxes.at(i)->GetOwner() << " with a stack of " << Boxes.at(i)->CountStack() << endl;
	}
	cout << endl;
}

/* Add box to table list (covers both initial additions and split inserts) */
void Table::AddBox(Box* NewBox, const int BoxIndex = 0)
{
	/* BoxIndex defaults to zero for initial additions or is over ridden for split card additions */
	Boxes.insert((Boxes.begin() + BoxIndex), NewBox);
}

/* Remove chosen box from table when split play is over or player goes bust */
void Table::RemoveBox(const int BoxIndex)
{
	/* If the box isn't a temporary split card box... */
	if(Boxes.at(BoxIndex)->CheckSplit() == false)
	{
		/* delete the Player object referenced in the box object */
		delete Boxes.at(BoxIndex)->GetOwnerObj();
	}
	/* Remove the box from the list */
	delete Boxes[BoxIndex];
	Boxes.erase(Boxes.begin() + BoxIndex);
}

void Table::Clear()
{
	cout << "Boxes = " << Boxes.size() << endl;
	Boxes.clear();
	cout << "Boxes = " << Boxes.size() << endl;
}

/* Count the number of boxes in use at the table (including split boxes) */
const int Table::CountBoxes() const
{
	return Boxes.size();
}

/* Retrieve a chosen box from the list */
Box* Table::GetBox(const int BoxIndex)
{
	return Boxes[BoxIndex];
}

/* Remove all the temporary boxes used for split play */
void Table::RemoveSplits()
{
	int BoxIndex = 0;	

	/* Cycle through all the boxes */
	while(BoxIndex != Boxes.size())	
	{
		Box *BoxPointer;
		BoxPointer = Boxes.at(BoxIndex);
		/* If a box is from split play... */
		if (BoxPointer->CheckSplit() == true)
		{
			/* ...remove it */
			RemoveBox(BoxIndex);
		}
		/* Otherwise skip over it */
		else
		{
			BoxIndex++;
		}
	}
}
