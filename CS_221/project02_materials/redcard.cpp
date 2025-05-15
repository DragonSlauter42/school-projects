//CS 221 - redcard.cpp
//Hunter Tyler
//First Edit: 9/12/2024 // Did all of the coding except finalizing desciption. On 9/13/2024, I worked on getting the program to compile.
//Last Edit: 9/15/2024 //Made sure to include all the Get functions since there was no need to make them, but not use them.

//Include Files: I just copy and pasted from card.cpp, modifying card.h to whatever needed// please let me know if this is useless or not.
#include <iostream>
#include <cstdlib>
#include "redcard.h"

 
RedCard::RedCard(int v):Card(v) //Creating this class's base class by inheriting from the parent class.
{

  SetColor("red"); //Sets the color to red.
}

string RedCard::Description() const   
// Outputs card characteristics - value as a string //Add suit and Color to the very end with each only 
{
  string d;    // temporary variable used to accumulate result 
  d = Card::Description();
  d= d + " Color: " + GetColor() + " "; //Using the GetColor() function from the Card class, description() outputs the color of the card.
  return d;                 // Return string describing card value
}