//Hunter Tyler -- CS 221 -- Mazes and Monsters: List Implementation
//First Edit: 10/17/2024
//Last Edit: 10/20/2024 //Finished on 10/19/2024
//CharacterList.cpp

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.

#include "CharacterList.h"

using namespace std;

CharacterList::CharacterList()
{
    m_pHead = NULL;
}

CharacterList::~CharacterList()
{

}

bool CharacterList::addCharacter(Character *newCharacter)
    {
        if (m_pHead == nullptr) //if no character exists
        {
            m_pHead = newCharacter;
            newCharacter->m_pNext = nullptr;
        }else //if there is already a character, go to character.m_sNext until nullptr is found. Add the new character there.
        {
            Character *currentNode = m_pHead;
            if(strcmp(newCharacter->getName(), currentNode->getName()) < 0)
            {
                newCharacter->m_pNext = m_pHead;
                m_pHead = newCharacter;
                return true;
            }
            while (currentNode->m_pNext != nullptr && strcmp(newCharacter->getName(), currentNode->m_pNext->getName()) > 0) //Sorts Alphabetically & Ascending.
            {
                currentNode = currentNode->m_pNext;
            }
            if(currentNode->m_pNext != nullptr && strcmp(newCharacter->getName(), currentNode->m_pNext->getName()) == 0)//stops duplicates from being added.
            {
                return false;
            }
               newCharacter->m_pNext = currentNode->m_pNext;
               currentNode->m_pNext = newCharacter;
        }
        return true;
    }

        
Character *CharacterList::deleteCharacter(char *characterName) //Goes through the list, finds the desired one makes its m_sNext the previous's m_sNext. Then makes the m_sNext of desired one NULL.
    {
        Character *currentNode = m_pHead;
        Character *previousNode = NULL;

        if(m_pHead == nullptr) //if the head is null, there is no character/
        {
            return NULL;
        }

        if(strcmp(currentNode->getName(), characterName) == 0) //if the head is the node your looking for.
        {
            if(currentNode->m_pNext == nullptr) //If there is only one node in the list.
            {
                m_pHead = NULL;
                return currentNode;
                
            }
            m_pHead = currentNode->m_pNext; //if there are more nodes in the list.
            currentNode->m_pNext = NULL; //Seperating the node
            return currentNode;          
        }

        while (currentNode != nullptr && strcmp(currentNode->getName(), characterName) != 0) //if the head is not the node your looking for.
            {
                previousNode = currentNode;
                currentNode = currentNode->m_pNext;
            }      
        if (currentNode == nullptr) //Character not found.
            {
                return NULL;
            }

    
        previousNode->m_pNext = currentNode->m_pNext; //Sets the previousNode's m_sNext to desiredNode's 
        currentNode->m_pNext = NULL;
        return currentNode;

    }

    

bool CharacterList::addItem(char *characterName, Item *newItem)
    {
        Character *currentNode = m_pHead;
        if(m_pHead == nullptr)//if the head is null, there is no character and thus no items
        {
            return false;
        }        
        while(currentNode != nullptr)
        {
            if(strcmp(currentNode->getName(), characterName) == 0)
            {
                if(currentNode->itemCount == currentNode->inventory_Size) //Inventory isn't free real estate now is it?
                {
                    return false;
                }
                currentNode->addItem(newItem);
                return true;
            }
            currentNode = currentNode->m_pNext;
        }
        
        return false;
    }

Item *CharacterList::getItem(char *characterName, char *itemName)
    {
        Character *currentNode = m_pHead;
        if(m_pHead == nullptr) //if the head is null, there is no character and thus no items
        {
            return NULL;
        }
        while(currentNode != nullptr)// While there are characters in the list.
        {
            if(strcmp(currentNode->getName(), characterName) == 0)
            {
                return currentNode->getItem(itemName);
            }
            currentNode = currentNode->m_pNext;
        }
        
        return NULL;
    }


Item *CharacterList::dropItem(char *characterName, char *itemName)
    {
        Character *currentNode = m_pHead;
        if(m_pHead == nullptr) //if the head is null, there is no character and thus no items
        {
            return NULL;
        }
        while(currentNode != nullptr)
        {
            if(strcmp(currentNode->getName(), characterName) == 0)
            {
                Item *tempPtr = currentNode->getItem(itemName);
                currentNode->dropItem(itemName);
                return tempPtr; 
            }
            currentNode = currentNode->m_pNext;
        }
        
        return NULL;
    }

void CharacterList::printCharacters()
    {
        Character *currentNode = m_pHead;
        
        if (currentNode == nullptr) // No characters in the list
        {
            cout << "No Characters Available." << endl;
            return;
        }
        
        // Traverse the list and print all characters
        while (currentNode != nullptr)
        {
            currentNode->printAll();  // Assuming printAll() prints the character details
            currentNode = currentNode->m_pNext;
        }
    }

// int main()
// {
//     // Create a CharacterList object
//     CharacterList characterList;

//     // Create three Character objects
//     char name2[] = "Alice";
//     char name1[] = "Cob";
//     char name3[] = "Bharlie";
    
//     Character character1(name1, 1, 2, 33, 18, 16, 18, 6, 12, 7);
//     Character character2(name2, 2, 1, 28, 15, 14, 17, 8, 10, 9);
//     Character character3(name3, 3, 3, 25, 13, 18, 16, 10, 9, 6);

//     // Add characters to the list
//     characterList.addCharacter(&character1);
//     characterList.addCharacter(&character2);
//     characterList.addCharacter(&character3);

//     // Print characters before deletion
//     std::cout << "Characters before deletion:\n";
//     characterList.printCharacters();

//     // Delete the third character
//     characterList.deleteCharacter(name2);

//     // Print characters after deletion
//     std::cout << "\nCharacters after deletion:\n";
//     characterList.printCharacters();

//     return 0;
// }