//
// Created by Access on 5/14/2024.
//
#pragma once // This pragma ensures that the header is included only once

#ifndef UNTITLED17_HEAP_H
#define UNTITLED17_HEAP_H
#include "Item.h"

class Heap {
private:
    vector<Item> heap;
    string toLower(const string& word) {
        string result;
        for (char c : word) {
            result += tolower(c);
        }
        return result;
    }

    void maxHeapifyprice(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left].getPrice() > heap[largest].getPrice())
            largest = left;
        if (right < n && heap[right].getPrice() > heap[largest].getPrice())
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapifyprice(n, largest);
        }
    }

    void minHeapifyprice(int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left].getPrice() < heap[smallest].getPrice())
            smallest = left;
        if (right < n && heap[right].getPrice() < heap[smallest].getPrice())
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapifyprice(n, smallest);
        }
    }

    //Max heapify function
    void maxHeapifyName(vector<Item>& items, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && toLower(items[left].itemName) >toLower(items[largest].itemName))
            largest = left;
        if (right < n &&toLower(items[right].itemName) > toLower(items[largest].itemName))
            largest = right;

        if (largest != i) {
            swap(items[i], items[largest]);
            maxHeapifyName(items, n, largest);
        }
    }

// min heapify function
    void minHeapifyName(vector<Item>& items, int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && toLower(items[left].itemName) < toLower(items[smallest].itemName))
            smallest = left;
        if (right < n && toLower(items[right].itemName)<toLower(items[smallest].itemName))
            smallest = right;

        if (smallest != i) {
            swap(items[i], items[smallest]);
            minHeapifyName(items, n, smallest);
        }
    }


public:
    Heap() {}

    void buildMaxHeap() {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; --i)
            maxHeapifyprice(n, i);
    }

    void buildMinHeap() {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; --i)
            minHeapifyprice(n, i);
    }

    void heapSortAscending() {
        int n = heap.size();
        buildMaxHeap();
        for (int i = n - 1; i > 0; --i) {
            swap(heap[0], heap[i]);
            maxHeapifyprice(i, 0);
        }
        displayItems();
    }

    void heapSortDescending() {
        int n = heap.size();
        buildMinHeap();
        for (int i = n - 1; i > 0; --i) {
            swap(heap[0], heap[i]);
            minHeapifyprice(i, 0);
        }
        displayItems();
    }

// Heap sort function
    void heapSortbyNameasc() {
        int n = heap.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; --i)
            maxHeapifyName(heap, n, i);
        // Extract items one by one
        for (int i = n - 1; i > 0; --i) {
            swap(heap[0], heap[i]);
            maxHeapifyName(heap, i, 0);
        }
        displayItems();

    }
// Heap sort function (ascending order)
    void heapSortbyNamedec() {
        int n = heap.size();

        // Build min heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; --i)
            minHeapifyName(heap, n, i);

        // Extract items one by one
        for (int i = n - 1; i > 0; --i) {
            swap(heap[0], heap[i]);
            minHeapifyName(heap, i, 0); // You need to implement minHeapify
        }
        displayItems();

    }

    void addItem( const Item& newItem) {
        heap.push_back(newItem);
    }

    void removeItemByName( string& itemName) {
        heap.erase(remove_if(heap.begin(), heap.end(), [&]( Item& item) {
            return item.getItemName() == itemName;
        }), heap.end());
        displayItems();
    }

    const vector<Item>& getItems()  {
        return heap;
    }
    void displayItems(){
        vector<Item> items= getItems();
        for (const auto& item : items) {
            item.print();
        }
    }

};


#endif //UNTITLED17_HEAP_H
