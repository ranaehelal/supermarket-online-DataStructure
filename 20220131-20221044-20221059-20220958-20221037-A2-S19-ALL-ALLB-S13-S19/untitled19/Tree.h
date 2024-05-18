//
// Created by Access on 5/14/2024.
//
#pragma once

#ifndef UNTITLED17_TREE_H
#define UNTITLED17_TREE_H
#include "Item.h"


class Tree {
public:

    virtual ~Tree() ;

    virtual void insert(Item item) = 0;
    virtual void display()  =0;
    virtual void remove(const string& itemName) = 0;
    virtual void displayByNameAscending() = 0;
    virtual void displayByNameDescending() = 0;
    virtual void displayByPriceAscending() = 0;
    virtual void displayByPriceDescending() = 0;

};


#endif //UNTITLED17_TREE_H
