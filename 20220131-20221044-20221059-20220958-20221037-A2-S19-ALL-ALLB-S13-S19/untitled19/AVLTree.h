//
// Created by Access on 5/14/2024.
//
#pragma once // This pragma ensures that the header is included only once

#ifndef UNTITLED17_AVLTREE_H
#define UNTITLED17_AVLTREE_H

#include "Tree.h"
#include "AVLNode.h"
#include "Item.h"
#include <vector>
#include <algorithm>

class AVLTree : public Tree {
private:
    AVLNode* root;
    vector<Item> insertedItems; // Vector to store inserted items


    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* y);
    AVLNode* insertHelper(AVLNode* node, Item item);
    void inOrderTraversal(AVLNode* node);
    void storeInOrder(AVLNode* node, std::vector<Item>& items);
     vector<Item> getInsertedItems() ;
    AVLNode* removeHelper(AVLNode* root, const std::string& itemName);
    AVLNode* minValueNode(AVLNode* node);
public:
    AVLTree();
    void remove(const string& itemName)override;
    void insert(Item item) override;
    void display() override;
    void displayByNameAscending() override;
    void displayByNameDescending() override;
    void displayByPriceAscending() override;
    void displayByPriceDescending() override;
};


#endif //UNTITLED17_AVLTREE_H
