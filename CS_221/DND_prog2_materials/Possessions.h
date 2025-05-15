//Hunter Tyler -- CS 221 -- Mazes and Monsters: Tree Implementation
//First Edit: 10/28/2024
//Last Edit: 11/2/2024 //Finished on 10/31/2024
//Possession.h

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
        void printAll(Item *root); //Calls printOne a bunch of times
        void destroyTree(Item *currentNode);
        void copyItem(Item *currentItem, Item *ItemCopied);
        bool addNode(Item *&currentNode, Item *newItem);
        Item *dropItem(Item *&currentNode, char *itemName);
        Item* dropItem(Item* currentNode, Item* parentNode, char* itemName);
        
    public:
        Possessions();
        ~Possessions(); // calls destoryTrees
        bool addItem(Item *newItem);
        Item *dropItem(char *itemName);
        Item *getItem(char *itemName);
        void printTree();

};




#endif