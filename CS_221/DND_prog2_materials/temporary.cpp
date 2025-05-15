//Put these back in after I figure out what is wrong with everything.

// Item *Possessions::dropNode(Item *&currentNode)
// {
//     Item *tempItem;
//     Item *tempPtr = currentNode;

//     if(currentNode->m_pLeft == nullptr) //No left child.
//     {
//         currentNode = currentNode->m_pRight;
//         return tempPtr;
        
//     }else if(currentNode->m_pRight == nullptr) //No right child
//     {
//         currentNode = currentNode->m_pLeft;
//         return tempPtr;
//     }else
//     {  
//         tempItem = getPredecessor(currentNode->m_pLeft);
//         copyItem(currentNode, tempItem);
//         dropItem(currentNode->m_pLeft, tempItem->m_sItemName);
//         return tempPtr;
        
//     }

//     return nullptr;
// }

// Item *Possessions::dropItem(Item *&currentNode, char *itemName)
// {
//     if(strcmp(itemName, currentNode->m_sItemName) < 0)//Move left
//     {
//         dropItem(currentNode->m_pLeft, itemName);
//     }else if(strcmp(itemName, currentNode->m_sItemName) > 0) //move right
//     {
//         dropItem(currentNode->m_pRight, itemName);
//     }else //Gotcha!
//     {
//         return dropNode(currentNode);
//     }

//     return nullptr;
// }