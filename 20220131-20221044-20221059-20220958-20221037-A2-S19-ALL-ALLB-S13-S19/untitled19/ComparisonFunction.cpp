// ComparisonFunctions.cpp
#include "ComparisonFunctions.h"
#include <algorithm>

std::string toLower(const std::string& word) {
    std::string result;
    for (char c : word) {
        result += tolower(c);
    }
    return result;
}

bool compareByNameAsc(const Item& a, const Item& b) {
    return toLower(a.itemName) < toLower(b.itemName);
}

bool compareByNameDesc(const Item& a, const Item& b) {
    return toLower(a.itemName) > toLower(b.itemName);
}

bool compareByPriceAsc(const Item& a, const Item& b) {
    return a.price < b.price;
}

bool compareByPriceDesc(const Item& a, const Item& b) {
    return a.price > b.price;
}
