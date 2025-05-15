//Hunter Tyler -- CS 221 -- Mazes and Monsters: Tree Implementation
//First Edit: 10/28/2024
//Last Edit: 11/2/2024 //Finished on 10/31/2024
//Possession.cpp

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.

#include "Possessions.h"

using namespace std;

//Constructor & Destructor
Possessions::Possessions()
{
    m_pRoot = nullptr;
}

Possessions::~Possessions()
{
    Item *currentNode = m_pRoot;
    destroyTree(currentNode);
}

//Private Functions
void Possessions::printOne(Item *item) //Prints Item name, description, weight and value. Possibly whether its for battle or for treasure.
{
    if(item == nullptr)
    {
        return;
    }

    cout << "Item Name: " << item->m_sItemName << "\n";
    cout << "------------------------------------------------------------" << "\n";
    cout << "Decription: " << item->m_sDesc << "\n";
    cout << "Value: " << item->m_dValue << "GP		" << "Weight: " << item->m_dWeight << "lbs" << "\n";
	cout << "------------------------------------------------------------" << "\n";
    cout << " " << endl;
}

void Possessions::printAll(Item *root) //calls printOne() a bunch of times. called by printTree().
{
    if(root != nullptr)
    {
        printAll(root->m_pLeft);
        printOne(root);
        printAll(root->m_pRight);

    }
}

void Possessions::destroyTree(Item *currentNode)
{ 
    if (currentNode == nullptr) 
    {
        return;
    } 
    
    destroyTree(currentNode->m_pLeft); 
    destroyTree(currentNode->m_pRight); 

    delete currentNode;
} 

void Possessions::copyItem(Item *currentItem, Item *ItemCopied)
{
    strcpy(currentItem->m_sItemName, ItemCopied->m_sItemName);
    strcpy(currentItem->m_sDesc, ItemCopied->m_sDesc);
    currentItem->m_iType = ItemCopied->m_iType;
    currentItem->m_dValue = ItemCopied->m_dValue;
    currentItem->m_dWeight = ItemCopied->m_dWeight;
}

bool Possessions::addNode(Item *&currentNode, Item *newItem)
{
    if(currentNode == nullptr) //We made it boys! Hurrah!
    {
        currentNode = new Item;
        currentNode->m_pLeft = nullptr;
        currentNode->m_pRight = nullptr;
        copyItem(currentNode, newItem);
        return true;
    }else if(strcmp(newItem->m_sItemName, currentNode->m_sItemName) < 0) //move left
    {
        return addNode(currentNode->m_pLeft, newItem);
    }else //move right
    {
        return addNode(currentNode->m_pRight, newItem);
    }
    return false;
    
}

Item* Possessions::dropItem(Item* currentNode, Item* parentNode, char* itemName) //I hate this function so much...
{
    if (currentNode == nullptr) 
    {
        return nullptr;  // Item don't exist
    }

    if (strcmp(itemName, currentNode->m_sItemName) == 0) 
    {
        Item* droppedItem = nullptr;

        if (currentNode->m_pLeft == nullptr && currentNode->m_pRight == nullptr) // no children :)
        {
            droppedItem = currentNode;
            if (parentNode != nullptr) 
            {
                if (parentNode->m_pLeft == currentNode) 
                {
                    parentNode->m_pLeft = nullptr;
                } 
                else 
                {
                    parentNode->m_pRight = nullptr;
                }
            } 
            else 
            {
                m_pRoot = nullptr;  //TIMBER!
            }
            return droppedItem;
        }

        if (currentNode->m_pLeft == nullptr || currentNode->m_pRight == nullptr) //One child :|
        {
            droppedItem = currentNode;
            Item* childNode = (currentNode->m_pLeft != nullptr) ? currentNode->m_pLeft : currentNode->m_pRight;
            if (parentNode != nullptr) 
            {
                if (parentNode->m_pLeft == currentNode) 
                {
                    parentNode->m_pLeft = childNode;
                } 
                else 
                {
                    parentNode->m_pRight = childNode;
                }
            } 
            else 
            {
                m_pRoot = childNode;  // I guess we can't have an orphan. Unfortunately...
            }
            droppedItem->m_pLeft = droppedItem->m_pRight = nullptr;
            return droppedItem;
        }

        //Two children. :(
        Item* successorParent = currentNode;                //All of this was really stupid. I get why it is the way it is, but 
        Item* successor = currentNode->m_pRight;            //why can't machines just be smarter. I mean bro, just stop thinking in 1's nad 2's.
        while (successor->m_pLeft != nullptr) 
        {
            successorParent = successor;
            successor = successor->m_pLeft;
        }

        droppedItem = new Item(*currentNode);
        droppedItem->m_pLeft = droppedItem->m_pRight = nullptr;

        if (successorParent != currentNode) 
        {
            successorParent->m_pLeft = successor->m_pRight;
            successor->m_pRight = currentNode->m_pRight;
        }
        successor->m_pLeft = currentNode->m_pLeft;

        if (parentNode != nullptr) 
        {
            if (parentNode->m_pLeft == currentNode) 
            {
                parentNode->m_pLeft = successor;
            } 
            else 
            {
                parentNode->m_pRight = successor;
            }
        } 
        else 
        {
            m_pRoot = successor;
        }

        delete currentNode;
        return droppedItem;
    }

    //If it aint where we was lookin'
    if (strcmp(itemName, currentNode->m_sItemName) < 0) 
    {
        return dropItem(currentNode->m_pLeft, currentNode, itemName);
    } 
    else 
    {
        return dropItem(currentNode->m_pRight, currentNode, itemName);
    }
}

//Public Functions
bool Possessions::addItem(Item *newItem)
{
    return addNode(m_pRoot, newItem);
}




Item* Possessions::dropItem(char* itemName) 
{
    if (m_pRoot == nullptr || itemName == nullptr) 
    {
        return nullptr;  
    }
    return dropItem(m_pRoot, nullptr, itemName);
}

Item *Possessions::getItem(char *itemName)
{
    Item *currentNode = m_pRoot;
    while(currentNode != nullptr)
    {   
        if(strcmp(itemName, currentNode->m_sItemName) == 0) 
        {
            return currentNode;

        }else if(strcmp(itemName, currentNode->m_sItemName) < 0) //Move left.
        {
            currentNode = currentNode->m_pLeft;

        }else if(strcmp(itemName, currentNode->m_sItemName) > 0) //Move right
        {
            currentNode = currentNode->m_pRight;

        }
    }
    return nullptr;
}

void Possessions::printTree()
{
    Item *currentNode = m_pRoot;
    printAll(currentNode);
}
