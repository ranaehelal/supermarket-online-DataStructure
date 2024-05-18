//
// Created by Access on 5/14/2024.
//
#include <bits/stdc++.h>
using namespace std;

#include "Item.h"
Item::Item(string name, string cat, int p) : itemName(name), category(cat), price(p) {}

bool Item::operator<(const Item& other) const {
    return itemName < other.itemName;
}

string Item::getItemName() {
    return itemName;
}

string Item::getCategory() {
    return category;
}

int Item::getPrice() {
    return price;
}

void Item::print() const {
    cout << "Item: " << itemName << ", Category: " << category << ", Price: " << price << '\n';
}