// ComparisonFunctions.h
#ifndef UNTITLED17_COMPARISONFUNCTIONS_H
#define UNTITLED17_COMPARISONFUNCTIONS_H

#include "Item.h"
#include <string>

std::string toLower(const std::string& word);

bool compareByNameAsc(const Item& a, const Item& b);
bool compareByNameDesc(const Item& a, const Item& b);
bool compareByPriceAsc(const Item& a, const Item& b);
bool compareByPriceDesc(const Item& a, const Item& b);

#endif // UNTITLED17_COMPARISONFUNCTIONS_H
