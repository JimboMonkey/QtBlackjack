
#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>

#include "Box.hpp"

class Table
{
	public:
		void AddBox(Box* NewBox, const int BoxIndex);
		void RemoveBox(const int BoxIndex);
		void ListPlayers() const;
		int CountBoxes() const;
		Box* GetBox(const int BoxIndex);
		void RemoveSplits();
		void Clear();

	private:
		vector<Box*> Boxes;
};

#endif
