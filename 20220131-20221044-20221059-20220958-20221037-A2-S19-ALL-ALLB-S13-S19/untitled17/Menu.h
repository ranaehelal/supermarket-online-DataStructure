//
// Created by Access on 5/14/2024.
//
#pragma once // This pragma ensures that the header is included only once

#ifndef UNTITLED17_MENU_H
#define UNTITLED17_MENU_H

#include "Tree.h"
#include "Item.h"
#include "AVLTree.h"
#include "BST.h"
#include "Heap.h"
class Menu {
public:
    static void displayMainMenu();
    static void displayTreeMenu();
    static void displayHeapMenu();
    static int readChoice();
    void processMainMenu(BST bst, Heap minHeap, Heap maxHeap,AVLTree avl);
    void processTreeMenu(Tree& tree);
    //   void processHeapMenu(Heap& heap);
};


#endif //UNTITLED17_MENU_H
