//
// Created by Mohamed Hela on 5/18/2024.
//

#ifndef ASSIGNMENT2_BSTNODE_H
#define ASSIGNMENT2_BSTNODE_H
#include "Item.h"

class BSTNode {
public:
    Item data;
    BSTNode* left;
    BSTNode* right;


    BSTNode(Item item);

};


#endif //ASSIGNMENT2_BSTNODE_H