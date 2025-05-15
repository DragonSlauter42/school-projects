//Hunter Tyler -- CS 221 -- Mazes and Monsters: Stack Implementation
//First Edit: 10/24/2024
//Last Edit: 10/24/2024 //Finished on 10/18/2024
//Possessions.h

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.

#pragma once
#ifndef POSSESSIONS_H
#define POSSESSIONS_H
#include <iostream>
#include <string.h.>
#include "Item.h"

class Possessions
{
    private:
        Item *m_pRoot = NULL;
        void printOne(Item *item); //Calls printALL from Character
        void destroyTree(Item *rt);

    public:
        Possessions();
        ~Possessions(); // calls destoryTree
        bool addItem(Item *newItem);
        Item *dropItem(char *itemName);
        Item *getItem(char *itemName);
        void printTree();
        void printAll(Item *rt); //Calls printOne a bunch of times
};




#endif POSSESSIONS_H