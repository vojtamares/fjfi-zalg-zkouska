#include "ListItem.h"

ListItem::ListItem()
{
    this->next = nullptr;
    this->prev = nullptr;
}

ListItem::ListItem(ListItem* next, ListItem* prev, std::string& payload)
{
    this->next = next;
    this->prev = prev;
    this->payload = payload;
}

ListItem::ListItem(std::string& payload)
{

    this->next = nullptr;
    this->prev = nullptr;
    this->payload = payload;
}

ListItem* ListItem::getNext()
{
    return this->next;
}

ListItem* ListItem::getPrev()
{
    return this->prev;
}

std::string ListItem::getPayload()
{
    return this->payload;
}

void ListItem::setNext(ListItem* next)
{
    this->next = next;
}

void ListItem::setPrev(ListItem* prev)
{
    this->prev = prev;
}

void ListItem::setPayload(std::string& payload)
{
    this->payload = payload;
}

void ListItem::swapPayloadWith(ListItem* with)
{
    std::string tmp = with->getPayload();
    with->setPayload(this->payload);
    this->payload = tmp;
}