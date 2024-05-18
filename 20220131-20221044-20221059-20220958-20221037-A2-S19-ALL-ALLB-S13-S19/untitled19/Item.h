//
// Created by Access on 5/14/2024.
//
#pragma once // This pragma ensures that the header is included only once

#ifndef UNTITLED17_ITEM_H
#define UNTITLED17_ITEM_H
#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    string itemName;
    string category;
    int price;

    Item(string name, string cat, int p);

    bool operator<(const Item& other) const;

    string getItemName();

    string getCategory();

    int getPrice();

    void print() const;
};
#endif //UNTITLED17_ITEM_H
