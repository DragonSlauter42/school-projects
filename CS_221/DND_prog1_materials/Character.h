//Hunter Tyler -- CS 221 -- Mazes and Monsters: List Implementation
//First Edit: 10/15/2024
//Last Edit: 10/20/2024 //Finished on 10/18/2024
//Character.h

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.

#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string.h.>
#include "Item.h"

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.

class Character
{
	private:
		char	m_sName[65];
		int		m_iClass;
		int		m_iAlignment;
		int		m_iHitPoints;
		int		m_iCharacterTraits[6];			// Strength, Dexterity, Constitution,Intelligence, Wisdom, Charisma

		Item m_Items[10];


	public:
		int itemCount = 0;
		int inventory_Size = 10;
		Character	*m_pNext;

		Character();					// Class constructor
		// Do not include in project for students
		Character(char *name, int cl, int al, int hp, int str, int dex, int con, int inl, int wis, int chr);
		~Character();					// Class destructor
		char *getName();		        // Get the player's name
		void setName(char *name);		// Set the player's name
	
		// The get functions for Class, Alignment, and Hit Points are reference functions.
		int getClass();			        // Get the player's class
		void setClass(int cl);			// Set the player's class
		int getAlignment();		        // Get the player's alignment
		void setAlignment(int al);		// Set the player's alignment
		int getHitPoints();		        // Get the player's class
		void setHitPoints(int hp);		// Set the player's class

		// Char traits get/set methods
		// The get functions for each character trait are pointer functions
		int getStrength();		        // Get the player's Strength
		void setStrength(int str);		// Set the player's Strength
		int getDexterity();	            // Get the player's Dexterity
		void setDexterity(int dex);		// Set the player's Dexterity
		int getConstitution();	        // Get the player's Constitution
		void setConstitution(int cn);	// Set the player's Constitution
		int getIntelligence();	        // Get the player's Intelligence
		void setIntelligence(int itl);	// Set the player's Intelligence
		int getWisdom();		        // Get the player's Wisdom
		void setWisdom(int wis);		// Set the player's Wisdom
		int getCharisma();		        // Get the player's Charisma
		void setCharisma(int chr);		// Set the player's Charisma

		bool addItem(Item *item);		// Add an item to the list of items
		Item *getItem(char *itemName);
		Item *dropItem(char *itemName);

		void printAll();				// Print everything about this character
};

#endif