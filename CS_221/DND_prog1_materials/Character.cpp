//Hunter Tyler -- CS 221 -- Mazes and Monsters: List Implementation
//First Edit: 10/15/2024
//Last Edit: 10/20/2024 //Finished on 10/18/2024
//Character.cpp

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.

#include "Character.h"

using namespace std;

Character::Character()
{
};

Character::Character(char *name, int cl, int al, int hp, int str, int dex, int con, int inl, int wis, int chr)
{
	setName(name);
	setClass(cl);
	setAlignment(al);
	setHitPoints(hp);	
	setStrength(str);	
	setDexterity(dex);
	setConstitution(con);
	setIntelligence(inl);
	setWisdom(wis);
	setCharisma(chr);
};

Character::~Character()
{

}

char *Character::getName()
{
	return m_sName;
}


void Character::setName(char *name)
{
    strcpy(m_sName, name);
}

int Character::getClass()			        // Get the player's class
{
	return m_iClass;
}

void Character::setClass(int cl)			// Set the player's class
{
	m_iClass = cl;
}

int Character::getAlignment()		        // Get the player's alignment
{
	return m_iAlignment;
}

void Character::setAlignment(int al)		// Set the player's alignment
{
	m_iAlignment = al;
}

int Character::getHitPoints()		        // Get the player's hitpoints
{
	return m_iHitPoints;
}

void Character::setHitPoints(int hp)		// Set the player's hitpoints
{
	m_iHitPoints = hp;
}

int Character::getStrength()		        // Get the player's Strength
{
	return m_iCharacterTraits[0];
}

void Character::setStrength(int str)		// Set the player's Strength
{
	m_iCharacterTraits[0] = str;
}

int Character::getDexterity()	            // Get the player's Dexterity
{
	return m_iCharacterTraits[1];
}

void Character::setDexterity(int dex)		// Set the player's Dexterity
{
	m_iCharacterTraits[1] = dex;
}

int Character::getConstitution()	        // Get the player's Constitution
{ 
	return m_iCharacterTraits[2];
}

void Character::setConstitution(int con)	// Set the player's Constitution
{
	m_iCharacterTraits[2] = con;
}

int Character::getIntelligence()	        // Get the player's Intelligence
{
	return m_iCharacterTraits[3];
}

void Character::setIntelligence(int itl)	// Set the player's Intelligence
{
	m_iCharacterTraits[3] = itl;
}

int Character::getWisdom()		        // Get the player's Wisdom
{
	return m_iCharacterTraits[4];
}

void Character::setWisdom(int wis)		// Set the player's Wisdom
{
	m_iCharacterTraits[4] = wis;
}

int Character::getCharisma()		        // Get the player's Charisma
{
	return m_iCharacterTraits[5];
}

void Character::setCharisma(int chr)		// Set the player's Charisma
{
	m_iCharacterTraits[5] = chr;
}

bool Character::addItem(Item *item)
{
	if(item == nullptr)
	{
		return false;
	}
	if(itemCount < inventory_Size)
	{
		m_Items[itemCount] = *item;
		itemCount++;
		return true;
	}

	return false;

}

Item *Character::getItem(char *itemName)
{
    for (int i = 0; i < itemCount; i++)
    {
        if (strcmp(m_Items[i].m_sItemName, itemName) == 0) //strcmp() is 0 if the two are equal, this confirms the relation.
        {
			   Item *tempPtr =  &m_Items[i];
            return tempPtr;
        }
    }

    return NULL; //if the item is not found, or the inventory is empty, it will throw NULL.
}


Item *Character::dropItem(char *itemName)
{
	for(int i = 0; i < itemCount; i++)
	{
		if(strcmp(m_Items[i].m_sItemName, itemName) == 0)
		{
			Item tempPtr = m_Items[i];
			Item *itemCopy = &tempPtr;
			for (int x = i; x < itemCount - 1; x++) // Stop at itemCount - 1 to avoid out-of-bounds access
			{
				m_Items[x] = m_Items[x+1];
			}
			itemCount--;
			return itemCopy;
		} 
	}

	return NULL;
}


void Character::printAll()
{
	cout << "Character's Name: " << getName() << "\n";
	cout << "Character's Class: " <<  getClass()  << "\n";
	cout << "Character's Alignment: " <<  getAlignment() << "\n";
	cout << "Character's Hitpoints: " <<  getHitPoints() << "\n";
	cout << "Character's Strength: " <<  getStrength() << "\n";
	cout << "Character's Dexterity: " <<  getDexterity() << "\n";
	cout << "Character's Constitution: " <<  getConstitution() << "\n";
	cout << "Character's Intelligence: " <<  getIntelligence() << "\n";
	cout << "Character's Wisdom: " <<  getWisdom() << "\n";
	cout << "Character's Charisma: " <<   getCharisma() << "\n";
	if(itemCount > 0)
	{
		for(int i = 0; i < itemCount; i++)
			{
				cout << "Item Name: " << m_Items[i].m_sItemName << "\n";
				cout << "Value: " << m_Items[i].m_dValue << "GP		" << "Weight: " << m_Items[i].m_dWeight << "lbs" << "\n";
				cout << "------------------------------------------------------------" << "\n";
			}
	}else
	{
		cout << "Inventory is empty. \n";
		cout << "------------------------------------------------------------" << "\n";
	}

}


// int main()
// {

// 	char name[] = "Hunter";
// 	Item testItem1;
// 	Item *itemPtr1 = &testItem1;
// 	Item testItem2;
// 	Item *itemPtr2 = &testItem2;
// 	Item testItem3;
// 	Item *itemPtr3 = &testItem3;
// 	Item testItem4;
// 	Item *itemPtr4 = &testItem4;
// 	Item testItem10;
// 	Item *itemPtr10 = &testItem10;
// 	Item testItem5;
// 	Item *itemPtr5 = &testItem5;
// 	Item testItem6;
// 	Item *itemPtr6 = &testItem6;
// 	Item testItem7;
// 	Item *itemPtr7 = &testItem7;
// 	Item testItem8;
// 	Item *itemPtr8 = &testItem8;
// 	Item testItem9;
// 	Item *itemPtr9 = &testItem9;
// 	Item testItem11;
// 	Item *itemPtr11 = &testItem11;
// 	strcpy(testItem1.m_sItemName, "Ban Hammer");
// 	testItem1.m_dValue = 5.0;
// 	testItem1.m_dWeight = 2.50;
// 	testItem2.m_dValue = 4.0;
// 	testItem2.m_dWeight = 3.50;
// 	testItem3.m_dValue = 3.0;
// 	testItem3.m_dWeight = 4.50;
// 	testItem4.m_dValue = 2.0;
// 	testItem4.m_dWeight = 5;
// 	strcpy(testItem2.m_sItemName, "Unbreakable Rod");
// 	strcpy(testItem3.m_sItemName, "Doubling Rings");
// 	strcpy(testItem4.m_sItemName, "Majestic Glue");
// 	strcpy(testItem5.m_sItemName, "five");
// 	strcpy(testItem6.m_sItemName, "six");
// 	strcpy(testItem7.m_sItemName, "seven");
// 	strcpy(testItem8.m_sItemName, "eight");
// 	strcpy(testItem9.m_sItemName, "nine");
// 	strcpy(testItem10.m_sItemName, "ten");
// 	strcpy(testItem11.m_sItemName, "eleven");
// 	testItem5.m_dValue = 5.0;
// 	testItem5.m_dWeight = 5.50;
// 	testItem6.m_dValue = 6.0;
// 	testItem6.m_dWeight = 6.50;
// 	testItem7.m_dValue = 7.0;
// 	testItem7.m_dWeight = 7.50;
// 	testItem8.m_dValue = 8.0;
// 	testItem8.m_dWeight = 8.50;
// 	testItem9.m_dValue = 15.0;
// 	testItem9.m_dWeight = 13.50;
// 	testItem10.m_dValue = 55.0;
// 	testItem10.m_dWeight = 14.50;
// 	testItem11.m_dValue = 24.0;
// 	testItem11.m_dWeight = 1.50;


// 	Character testCharacter(name, 1, 2, 33, 18, 16, 18, 6, 12, 7);
// 	testCharacter.addItem(itemPtr1);
// 	testCharacter.addItem(itemPtr2);
// 	testCharacter.addItem(itemPtr3);
// 	testCharacter.addItem(itemPtr4);
// 	testCharacter.addItem(itemPtr5);
// 	testCharacter.addItem(itemPtr6);
// 	testCharacter.addItem(itemPtr7);
// 	testCharacter.addItem(itemPtr8);
// 	testCharacter.addItem(itemPtr9);
// 	testCharacter.addItem(itemPtr10);
// 	testCharacter.addItem(itemPtr11);

// 	testCharacter.printAll();
// 	testCharacter.dropItem(testItem3.m_sItemName);
// 	testCharacter.addItem(itemPtr11);
// 	testCharacter.printAll();
// 	testCharacter.getItem(testItem4.m_sItemName);




// 	return 0;
// }