//CS 221 - spade.cpp
//Hunter Tyler
//First Edit: 9/12/2024 // Did all of the coding except finalizing desciption. On 9/13/2024, I worked on getting the program to compile.
//Last Edit: 9/15/2024 //Made sure to include all the Get functions since there was no need to make them, but not use them.

//Include Files: I just copy and pasted from card.cpp, modifying card.h to whatever needed// please let me know if this is useless or not.
#include <iostream>
#include <cstdlib>
#include "spade.h"

Spade::Spade(int v):BlackCard(v) //Creating this class's base class by inheriting from the parent class.
{
  SetSuit('S');
}



string Spade::Description() const   
// Outputs card characteristics - value as a string //Add suit and Color to the very end with each only 
{
  string d;    // temporary variable used to accumulate result 
  d = BlackCard::Description();
  d= d + " Suit: " + GetSuit(); //Using the GetSuit() function from the Card class, description() outputs the suit of the card.
  return d;                 // Return string describing card value
}