#pragma once

#include <iostream>

class ListItem {
public:
    ListItem* getNext();
    ListItem* getPrev();
    std::string getPayload();

    void setNext(ListItem* next);
    void setPrev(ListItem* prev);
    void setPayload(std::string& payload);

    ListItem();
    ListItem(ListItem* next, ListItem* prev, std::string& payload);
    ListItem(std::string& payload);

    void swapPayloadWith(ListItem* with);
private:
    ListItem* next;
    ListItem* prev;
    std::string payload;
};