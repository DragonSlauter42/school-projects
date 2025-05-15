//Hunter Tyler -- CS 221 -- Mazes and Monsters: Tree Implementation
//First Edit: 10/15/2024 //Taken from Lists Project
//Last Edit: 11/2/2024 //Finished on 10/31/2024
//Character.cpp

//Abbreviations: class = cl, alignment = al, hitpoints = hp, strength = str, constitution = con, intelligence = inl, wisdom = wis, charisma = chr.

#include "Character.h"

using namespace std;

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

	m_pBattleItems = new Possessions();
	m_pTreasureItems = new Possessions();
};

Character::~Character()
{
	delete m_pBattleItems;
	delete m_pTreasureItems;
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
	if(item->m_iType == 1)
	{
		return m_pBattleItems->addItem(item);
	}
	if(item->m_iType == 2)
	{
		return m_pTreasureItems->addItem(item);
	}

	return false;

}


Item *Character::getItem(char *itemName)
{
	if(m_pBattleItems->getItem(itemName)) //try to see if the item is inside battleitems.
	{
		return m_pBattleItems->getItem(itemName);
	}else //it must be in treasure items, but it might not be...
	{
		return m_pTreasureItems->getItem(itemName);
	}
    return nullptr;
}


Item *Character::dropItem(char *itemName)
{
	if(m_pBattleItems->getItem(itemName))
	{
		return m_pBattleItems->dropItem(itemName);
	}else
	{
		return m_pTreasureItems->dropItem(itemName);
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
	m_pBattleItems->printTree();
	cout << "\n";
	m_pTreasureItems->printTree();

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