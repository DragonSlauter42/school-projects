#include <iostream>
#include "Character.h"
#include "CharacterList.h"
#include "Item.h"
using namespace std;

int main()
{

	char name[] = "Hunter";
	Item testItem1;
	Item *itemPtr1 = &testItem1;
	Item testItem2;
	Item *itemPtr2 = &testItem2;
	Item testItem3;
	Item *itemPtr3 = &testItem3;
	Item testItem4;
	Item *itemPtr4 = &testItem4;
	Item testItem10;
	Item *itemPtr10 = &testItem10;
	Item testItem5;
	Item *itemPtr5 = &testItem5;
	Item testItem6;
	Item *itemPtr6 = &testItem6;
	Item testItem7;
	Item *itemPtr7 = &testItem7;
	Item testItem8;
	Item *itemPtr8 = &testItem8;
	Item testItem9;
	Item *itemPtr9 = &testItem9;
	Item testItem11;
	Item *itemPtr11 = &testItem11;
	strcpy(testItem1.m_sItemName, "Ban Hammer");
	testItem1.m_dValue = 5.0;
	testItem1.m_dWeight = 2.50;
	testItem2.m_dValue = 4.0;
	testItem2.m_dWeight = 3.50;
	testItem3.m_dValue = 3.0;
	testItem3.m_dWeight = 4.50;
	testItem4.m_dValue = 2.0;
	testItem4.m_dWeight = 5;
	strcpy(testItem2.m_sItemName, "Unbreakable Rod");
	strcpy(testItem3.m_sItemName, "Doubling Rings");
	strcpy(testItem4.m_sItemName, "Majestic Glue");
	strcpy(testItem5.m_sItemName, "five");
	strcpy(testItem6.m_sItemName, "six");
	strcpy(testItem7.m_sItemName, "seven");
	strcpy(testItem8.m_sItemName, "eight");
	strcpy(testItem9.m_sItemName, "nine");
	strcpy(testItem10.m_sItemName, "ten");
	strcpy(testItem11.m_sItemName, "eleven");
	testItem5.m_dValue = 5.0;
	testItem5.m_dWeight = 5.50;
	testItem6.m_dValue = 6.0;
	testItem6.m_dWeight = 6.50;
	testItem7.m_dValue = 7.0;
	testItem7.m_dWeight = 7.50;
	testItem8.m_dValue = 8.0;
	testItem8.m_dWeight = 8.50;
	testItem9.m_dValue = 15.0;
	testItem9.m_dWeight = 13.50;
	testItem10.m_dValue = 55.0;
	testItem10.m_dWeight = 14.50;
	testItem11.m_dValue = 24.0;
	testItem11.m_dWeight = 1.50;


	Character testCharacter(name, 1, 2, 33, 18, 16, 18, 6, 12, 7);
	testCharacter.addItem(itemPtr1);
	testCharacter.addItem(itemPtr2);
	testCharacter.addItem(itemPtr3);
	testCharacter.addItem(itemPtr4);
	testCharacter.addItem(itemPtr5);
	testCharacter.addItem(itemPtr6);
	testCharacter.addItem(itemPtr7);
	testCharacter.addItem(itemPtr8);
	testCharacter.addItem(itemPtr9);
	testCharacter.addItem(itemPtr10);
	testCharacter.addItem(itemPtr11);

	testCharacter.printAll();
	testCharacter.dropItem(testItem3.m_sItemName);
	testCharacter.addItem(itemPtr11);
	testCharacter.printAll();
	testCharacter.getItem(testItem4.m_sItemName);

    // Create a CharacterList object
    CharacterList characterList;

    // Create three Character objects
    char name1[] = "Alice";
    char name2[] = "Bob";
    char name3[] = "Charlie";
    
    Character character1(name1, 1, 2, 33, 18, 16, 18, 6, 12, 7);
    Character character2(name2, 2, 1, 28, 15, 14, 17, 8, 10, 9);
    Character character3(name3, 3, 3, 25, 13, 18, 16, 10, 9, 6);

    // Add characters to the list
    characterList.addNewCharacter(&character1);
    characterList.addNewCharacter(&character2);
    characterList.addNewCharacter(&character3);

    // Print characters before deletion
    std::cout << "Characters before deletion:\n";
    characterList.printCharacters();

    // Delete the third character
    characterList.deleteCharacter(name2);

    // Print characters after deletion
    std::cout << "\nCharacters after deletion:\n";
    characterList.printCharacters();

    return 0;


	return 0;
}