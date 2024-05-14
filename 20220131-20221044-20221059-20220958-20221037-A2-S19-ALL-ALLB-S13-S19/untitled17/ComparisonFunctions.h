//
// Created by Access on 5/14/2024.
//

#ifndef UNTITLED17_COMPARISONFUNCTIONS_H
#define UNTITLED17_COMPARISONFUNCTIONS_H
#include "Item.h"
string toLower(const string& word) {
    string result;
    for (char c : word) {
        result += tolower(c);
    }
    return result;
}

bool compareByNameAsc(const Item& a, const Item& b) {
    return toLower(a.itemName) < toLower(b.itemName);
}

bool compareByNameDesc(const Item& a, const Item& b) {
    return toLower(a.itemName)  > toLower(b.itemName);
}

bool compareByPriceAsc(const Item& a, const Item& b) {
    return a.price < b.price;
}

bool compareByPriceDesc(const Item& a, const Item& b) {
    return a.price > b.price;
}
#endif //UNTITLED17_COMPARISONFUNCTIONS_H
