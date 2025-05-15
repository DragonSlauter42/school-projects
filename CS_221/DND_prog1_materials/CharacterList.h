//Hunter Tyler -- CS 221 -- Mazes and Monsters: List Implementation
//First Edit: 10/15/2024
//Last Edit: 10/20/2024 //Finished 10/19/2024
//CharacterList.h

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.

#ifndef CHARACTERLIST_H
#define CHARACTERLIST_H
#include <iostream>
#include "Character.h"


class CharacterList
{
    private:
        Character  *m_pHead;

    public: 
        CharacterList();
        ~CharacterList();
        bool addCharacter(Character *newCharacter);
        
        Character *deleteCharacter(char *characterName);

        bool addItem(char *characterName, Item *newItem);

        Item *getItem(char *characterName, char *itemName);

        Item *dropItem(char *characterName, char *itemName);

        void printCharacters();

};



#endif
