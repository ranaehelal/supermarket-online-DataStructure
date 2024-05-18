#include <bits/stdc++.h>
#include "Item.h"
#include "AVLTree.h"
#include "BST.h"
#include "Heap.h"
#include "Menu.h"
using namespace std;

// Function to read items.txt
void readItems(ifstream& MyReadFile, BST& bst, Heap& Heap, AVLTree& avl) {
    if (!MyReadFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    int numOfItems;
    MyReadFile >> numOfItems;
    MyReadFile.ignore(); // Consume newline character

    string itemName, category;
    int price;

    for (int i = 0; i < numOfItems; i++) {
        getline(MyReadFile, itemName);
        getline(MyReadFile, category);
        MyReadFile >> price;
        MyReadFile.ignore(); // Consume newline character

        Item item(itemName, category, price);
         bst.insert(item);
         Heap.addItem(item);
        avl.insert(item);
    }

    MyReadFile.close();
}






int main() {
    // Initialize trees
    BST bst;
    Heap Heap; // Min Heap
    AVLTree avl; // AVLTree Tree
    Menu menu;
    // Read items.txt from file
    ifstream MyReadFile ("items.txt");
    readItems( MyReadFile,bst, Heap, avl);
    menu.processMainMenu(bst, Heap, avl); // Call processMainMenu on the menu instance




    return 0;
}
