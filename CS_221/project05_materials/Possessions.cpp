//Hunter Tyler -- CS 221 -- Mazes and Monsters: Tree Implementation
//First Edit: 10/24/2024
//Last Edit: 10/24/2024 //Finished on 10/18/2024
//Possessions.cpp

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.
#include "Possessions.h"

using namespace std;

Possessions::Possessions()
{

}

Possessions::~Possessions()
{

}

//Private Functions
void printOne(Item *item)
{

}

void destroyTree(Item *rt)
{

}

//Public Functions

bool Possessions::addItem(Item *newItem)
{
    if(newItem == nullptr) //Item doesn't exist or is somehow empty.
    {
        return false;
    }

    Item *currentNode = m_pRoot;
    
    if(m_pRoot == nullptr) //if the root is empty.
    {
        m_pRoot = newItem; //may have to add a check to see if the inventory is full. Maybe not.
        return true;
    }

    while(strcmp(newItem->m_sItemName,currentNode->m_sItemName) == 0)
    {
        if()
        {

        }
    }
    return false;
}

Item *Possessions::dropItem(char *itemName)
{
}

Item *Possessions::getItem(char *itemName)
{

}

void Possessions::printTree()
{

}

void Possessions::printAll(Item *rt)
{

}