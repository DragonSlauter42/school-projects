
#include <iostream>
#include "Possessions.h"
#include <cstring>

int main() {
    // Item names
    char Amulet[] = "Amulet";
    char Potion[] = "Potion";
    char Book[] = "Book";
    char Staff[] = "Staff";
    char Robe[] = "Robe";
    
    // Create items and initialize their properties
    Item* item1 = new Item;
    strcpy(item1->m_sItemName, Amulet);
    strcpy(item1->m_sDesc, "A magical amulet.");
    item1->m_iType = TREASURE_ITEM;  // Use appropriate type
    item1->m_dValue = 10;
    item1->m_dWeight = 0.5;

    Item* item2 = new Item;
    strcpy(item2->m_sItemName, Potion);
    strcpy(item2->m_sDesc, "A healing potion.");
    item2->m_iType = BATTLE_ITEM;  // Use appropriate type
    item2->m_dValue = 5;
    item2->m_dWeight = 0.2;

    Item* item3 = new Item;
    strcpy(item3->m_sItemName, Book);
    strcpy(item3->m_sDesc, "A book of spells.");
    item3->m_iType = TREASURE_ITEM;  // Use appropriate type
    item3->m_dValue = 15;
    item3->m_dWeight = 3;

    Item* item4 = new Item;
    strcpy(item4->m_sItemName, Staff);
    strcpy(item4->m_sDesc, "A magical staff.");
    item4->m_iType = BATTLE_ITEM;  // Use appropriate type
    item4->m_dValue = 5;
    item4->m_dWeight = 1;

    Item* item5 = new Item;
    strcpy(item5->m_sItemName, Robe);
    strcpy(item5->m_sDesc, "A wizard's robe.");
    item5->m_iType = TREASURE_ITEM;  // Use appropriate type
    item5->m_dValue = 20;
    item5->m_dWeight = 1.5;

    // Create possessions instance and add items
    Possessions* possessions = new Possessions();
    possessions->addItem(item1);
    possessions->addItem(item2);
    possessions->addItem(item3);
    possessions->addItem(item4);
    possessions->addItem(item5);

    // Print all items (in-order traversal)
    std::cout << "In-order traversal of possessions:\n";
    possessions->printTree();

    // Drop the Amulet
    Item* droppedAmulet = possessions->dropItem(Amulet);
    if (droppedAmulet) {
        std::cout << "\nDropped Item: " << droppedAmulet->m_sItemName << "\n";
        delete droppedAmulet; // free memory after dropping
    }

    // Drop the Potion
    Item* droppedPotion = possessions->dropItem(Potion);
    if (droppedPotion) {
        std::cout << "\nDropped Item: " << droppedPotion->m_sItemName << "\n";
        delete droppedPotion; // free memory after dropping
    }

    // Print all items after dropping
    std::cout << "\nIn-order traversal after dropping items:\n";
    possessions->printTree();

    // Clean up
    delete possessions;

    return 0;
}
