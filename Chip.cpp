
#include "Chip.h"

#include <iostream>

// Constructor for Chip object
Chip::Chip(QWidget* parent): QLabel(parent)
{
	// Mark new chips as unplayed
	ChipUsed = false;
}

// Set the value of the chip
void Chip::SetValue(int NewValue)
{
	ChipValue = NewValue;
}

// Get the value of the chip
int Chip::GetValue()
{
	return ChipValue;
}

// Mark the chip as played
void Chip::SetUsed()
{
	ChipUsed = true;
}

// Check whether the chip has been played
bool Chip::CheckChipUsed()
{
	return ChipUsed;
}

