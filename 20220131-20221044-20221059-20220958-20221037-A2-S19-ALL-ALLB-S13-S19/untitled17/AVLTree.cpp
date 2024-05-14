#include "AVLTree.h"
#include "AVLNode.h"
#include "ComparisonFunctions.h"
AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::balanceFactor(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* y) {
    AVLNode *x = y->right;
    AVLNode *A = x->left;

    x->left = y;
    y->right = A;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::insertHelper(AVLNode* node, Item item) {
    if (node == nullptr)
        return new AVLNode(item);

    if (item.itemName < node->item.itemName)
        node->left = insertHelper(node->left, item);
    else if (item.itemName > node->item.itemName)
        node->right = insertHelper(node->right, item);
    else // Duplicate not allowed
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && item.itemName < node->left->item.itemName)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && item.itemName > node->right->item.itemName)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && item.itemName > node->left->item.itemName) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && item.itemName < node->right->item.itemName) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::inOrderTraversal(AVLNode* node) {
    if (node) {
        inOrderTraversal(node->left);
        node->item.print();
        inOrderTraversal(node->right);
    }
}

void AVLTree::storeInOrder(AVLNode* node, std::vector<Item>& items) {
    if (node) {
        storeInOrder(node->left, items);
        items.push_back(node->item);
        storeInOrder(node->right, items);
    }
}
void AVLTree:: insert(Item item) {
    insertedItems.push_back(item); // Store the inserted item in the vector
    root = insertHelper(root, item);
}
void AVLTree::remove(Item item) {

}
vector<Item> AVLTree:: getInsertedItems()  {
    return insertedItems;
}
void AVLTree:: display()  {
    vector<Item> items= getInsertedItems();
    for (const auto& item : items) {
        item.print();
    }
}
void AVLTree::displayByNameAscending() {
    cout << "Sorted by name ascending:" << endl;
    vector<Item> items;
    storeInOrder(root, items);
    sort(items.begin(), items.end(), compareByNameAsc); // Pass compareByName function here
    for (const auto& item : items) {
        item.print();
    }
}

void AVLTree::displayByNameDescending() {
    cout << "Sorted by name descending:" << std::endl;
    vector<Item> items;
    storeInOrder(root, items);
    sort(items.begin(), items.end(), compareByNameDesc); // Pass compareByName function here
    for (const auto& item : items) {
        item.print();
    }
}

void AVLTree::displayByPriceAscending() {
    cout << "Sorted by price ascending:" << std::endl;
    vector<Item> items;
    storeInOrder(root, items);
    sort(items.begin(), items.end(), compareByPriceAsc);
    for (const auto& item : items) {
        item.print();
    }
}

void AVLTree::displayByPriceDescending()  {
    cout << "Sorted by price descending:" << std::endl;
    vector<Item> items;
    storeInOrder(root, items);
    sort(items.begin(), items.end(), compareByPriceDesc);
    for (const auto& item : items) {
        item.print();
    }
}