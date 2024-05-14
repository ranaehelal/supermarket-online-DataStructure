//
// Created by Access on 5/14/2024.
//
#pragma once // This pragma ensures that the header is included only once

#ifndef UNTITLED17_AVLNODE_H
#define UNTITLED17_AVLNODE_H


#include "Item.h"

class AVLNode {
public:
    Item item;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Item i);
};

#endif //UNTITLED17_AVLNODE_H
