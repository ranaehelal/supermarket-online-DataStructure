//
// Created by Mohamed Hela on 5/18/2024.
//

#ifndef ASSIGNMENT2_BST_H
#define ASSIGNMENT2_BST_H

#include "Tree.h"
#include "BSTNode.h"
#include "Item.h"
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std ;

class BST : public Tree {
public:
    BSTNode* root;
    BST();
    void insert(Item item) override;
    void display() override;
    void remove(const string& itemName) override;
    void displayByNameAscending() override;
    void displayByNameDescending() override;
    void displayByPriceAscending() override;
    void displayByPriceDescending() override;

private:
    vector<Item> insertedItems; // Vector to store inserted items
    vector<Item> getInsertedItems() ;
    void insert(BSTNode*& node, Item item);
    void remove(BSTNode*& node, const std::string& itemName);
    BSTNode* findMin(BSTNode* node);
    void storeinOrder(BSTNode* node, std::vector<Item>& items) const;
};


#endif //ASSIGNMENT2_BST_H