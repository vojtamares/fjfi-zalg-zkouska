#pragma once

#include "ListItem.h"

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void print();
    void sort(); // selection sort

    ListItem* getHead();
    ListItem* getTail();

    void appendItem(ListItem* item);

    void swapItems(ListItem* which, ListItem* with);

private:
    ListItem* head;
    ListItem* tail;

    bool isEmpty();
    void deleteAllItems();
    void deleteFirstItem();
};
