//
// Created by Access on 5/14/2024.
//

#include "Menu.h"
void Menu::displayMainMenu() {
    cout << "Main Menu\n";
    cout << "1. Binary Search Trees (BST)\n";
    cout << "2. Heaps\n";
    cout << "3. AVLTree Trees\n";
    cout << "4. Exit\n";
}
void Menu::displayTreeMenu() {
    cout << "Tree Menu\n";
    cout << "1. Add item data\n";
    cout << "2. Remove item data\n";
    cout << "3. Display item data normally\n";
    cout << "4. Display all items sorted by name ascending\n";
    cout << "5. Display all items sorted by name descending\n";
    cout << "6. Display all items sorted by prices ascending\n";
    cout << "7. Display all items sorted by prices descending\n";
    cout << "8. Back to Main Menu\n";
}
void Menu::displayHeapMenu(){
    cout << "1. Add item data\n";
    cout << "2. Remove item data\n";
    cout << "3. Display item data normally\n";
    cout << "4. Display all items sorted by name ascending\n";
    cout << "5. Display all items sorted by name descending\n";
    cout << "6. Display all items sorted by prices ascending\n";
    cout << "7. Display all items sorted by prices descending\n";
    cout << "8. Back to Main Menu\n";
}

int Menu::readChoice() {
    int choice;
    cin >> choice;
    return choice;
}
void Menu::processMainMenu(BST bst, Heap Heap,AVLTree avl) {
    int mainChoice;
    do {
        Menu::displayMainMenu();
        cout << "Enter your choice: ";

        mainChoice = Menu::readChoice();
        switch (mainChoice) {
            case 1:
                processTreeMenu(bst);
                break;
            case 2:
          processHeapMenu( Heap);
                break;
            case 3:
                processTreeMenu(avl);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (mainChoice != 4);


}
void Menu::processTreeMenu(Tree &tree) {
    int treeChoice;
    do {
        Menu::displayTreeMenu();
        cout << "Enter your choice (1-8): ";
        treeChoice = Menu::readChoice();
        // Process user choice for the tree menu
        switch (treeChoice) {
            case 1: {
                cout << "Please enter the details of the new item (name category price): ";
                string name, cateogry;
                int price;
                cin >> name >> cateogry >> price;
                Item newitem(name, cateogry, price);

                tree.insert(newitem);
            }
                break;
            case 2: {
                cout << "Please enter the name of the item to remove : ";
                string itemName;
                cin >> itemName;
                tree.remove(itemName);
                break;
            }
            case 3:
                tree.display();
                break;
            case 4:
                tree.displayByNameAscending();
                break;
            case 5:
                tree.displayByNameDescending();
                break;
            case 6:
                tree.displayByPriceAscending();
                break;
            case 7:
                tree.displayByPriceDescending();
                break;
            case 8:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (treeChoice != 8);
}
void Menu::processHeapMenu(Heap& Heap) {
    while (true) {
        displayHeapMenu();
        int choice;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

       switch (choice) {
            case 1: {
                cout << "Please enter the details of the new item (name category price): ";
                string name, cateogry;
                int price;
                cin >> name >> cateogry >> price;
                Item newitem(name, cateogry, price);
               Heap.addItem(newitem);
                break;
            }
            case 2: {
                cout << "Please enter the name of the item to remove : ";
                string itemName;
                cin >> itemName;
                Heap.removeItemByName( itemName);
            }
                break;
            case 3:
              Heap.displayItems();
                break;
           case 4:
               Heap. heapSortbyNameasc();
               break;
           case 5:
               Heap. heapSortbyNamedec();
               break;

            case 6:
                 Heap.heapSortAscending();
                break;
            case 7:
                Heap.heapSortDescending();
                break;
           case 8:
               cout << "Returning to Main Menu...\n";
               break;
           default:
               cout << "Invalid choice! Please try again.\n";
               break;
       }


    }
}
