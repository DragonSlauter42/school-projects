//CS 221 - card.h
//Hunter Tyler
//First Edit: 9/12/2024 // Did all of the coding except finalizing desciption. On 9/13/2024, I worked on getting the program to compile.
//Last Edit: 9/15/2024 //Added this header

#include <string>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card                      // Class modeling Card ADT
{
 private:
  int value;			        // Card value: 2-10 for number cards, 11-14 for JQKA; 0 for unknown
  string color;			        // Card color: "red", "black", or "unknown"
  char suit;			        // Card suit: 'H' for hearts, 'D' for diamonds, 'C' for clubs, 'S' for spades or 'U' for unknown

 public:

//Constructor Prototypes
	Card();// Default constructor prototype: creates card with value v, color unknown, and suit U 

	Card(int v);// Parameterized constructor prototype: creates card with value v, color unknown, and suit U


//Transformeer Prototypes
  
	void SetValue(int v);// SetValue prototype: Sets card value equal to v
    
	void SetColor(string c);// SetColor prototype: Sets color value equal to c

	void SetSuit(char s);     // SetSuit prototype:  Sets suit value equal to s
	
//Observer Prototypes
	int GetValue() const;// GetValue prototype: Returns current value of value
	
	string GetColor() const;// GetColor prototype: Returns current value of color

	char GetSuit() const;// GetSuit prototype:  Returns current value of suit

 // Description prototype: Polymorphic Function!!!
	                            // Outputs card characteristics - value as a string (see sample output from p01input1.txt)
  	virtual string Description() const;

};


#endif


