//
// Created by Mohamed Hela on 5/18/2024.
//
#include <algorithm>
#include <bits/stdc++.h>
#include "BST.h"
#include "ComparisonFunctions.h"

BST::BST() : root(nullptr) {}

void BST::insert(Item item) {
    insert(root, item);
    insertedItems.push_back(item); // Store the inserted item in the vector

}

void BST::insert(BSTNode*& node, Item item) {
    // if node is empty
    if (!node) {
        node = new BSTNode(item);
    }// if less insert in left , if more insert in right
    else if (item < node->data) {
        insert(node->left, item);
    }
    else {
        insert(node->right, item);
    }
}


void BST::remove(const string& itemName) {
    remove(root, itemName);
    insertedItems.erase(
            remove_if(insertedItems.begin(), insertedItems.end(),
                      [&itemName](const Item& item) { return item.itemName == itemName; }),
            insertedItems.end()
    );
    display();

}
void BST::remove(BSTNode*& node, const string& itemName) {
    // if node is empty
    if (!node) return;
    // search till you find the element to delete it
    if (itemName < node->data.itemName) {
        remove(node->left, itemName);
    }
    else if (itemName > node->data.itemName) {
        remove(node->right, itemName);
    }

    else { // found then do one of the next

        //If the node to be removed (node) doesn't have a left child (node->left is nullptr),
        // it means that the right subtree (node->right) should replace the current node.
        // We update node to point to its right child, effectively removing it from the tree.
        /*
         (8)     or      (6)
           \             /
            (12)        (3)
         */
        if (!node->left) {
            BSTNode* temp = node;
            node = node->right;
            delete temp;
        }
            // same like left
        else if (!node->right) {
            BSTNode* temp = node;
            node = node->left;
            delete temp;
        }
            //If the node to be removed has both left and right subtrees,
            // we need to find the minimum node in the right subtree
            // (the node with the smallest value greater than the current node) to replace the current node.
        else {
            BSTNode* minNode = findMin(node->right);
            node->data = minNode->data;
            remove(node->right, minNode->data.itemName);
        }
    }
}

vector<Item> BST:: getInsertedItems()  {
    return insertedItems;
}
// find min in right subtree to know the node to be replaced in the remove if it has both subtrees
BSTNode* BST::findMin(BSTNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

//display items normally
void BST:: display()  {
    vector<Item> items= getInsertedItems();
    for (const auto& item : items) {
        item.print();
    }
}

// the vector is where the items will be sorted
void BST::storeinOrder(BSTNode *node, vector<Item> &items) const {
    if (node) {
        // it will make recursion till it reaches the minimum element to push it
        storeinOrder(node->left, items);
        items.push_back(node->data);
        storeinOrder(node->right, items);
    }
}

// display functions
void BST::displayByNameAscending() {
    cout << "Sorted by name ascending:" << endl ;
    vector<Item> items;
    storeinOrder(root, items);
    sort(items.begin(), items.end(),compareByNameAsc);
    for (const auto& item : items) {
        item.print();
    }
}

void BST::displayByNameDescending() {
    cout << "Sorted by name descending:" << endl;
    vector<Item> items;
    storeinOrder(root, items);
    sort(items.begin(), items.end(), compareByNameDesc);
    for (const auto& item : items) {
        item.print();
    }
}

void BST::displayByPriceAscending() {
    cout << "Sorted by price ascending:" << endl;
    vector<Item> items;
    storeinOrder(root, items);
    sort(items.begin(), items.end(),compareByPriceAsc );
    for (const auto& item : items) {
        item.print();
    }
}

void BST::displayByPriceDescending() {
    cout << "Sorted by price descending:" << endl;
    vector<Item> items;
    storeinOrder(root, items);
    sort(items.begin(), items.end(), compareByPriceDesc);
    for (const auto& item : items) {
        item.print();
    }
}