#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList()
{
    if (this->isEmpty()) {
        return;
    }

    this->deleteAllItems();
}

ListItem* LinkedList::getHead()
{
    return this->head;
}

ListItem* LinkedList::getTail()
{
    return this->tail;
}

void LinkedList::deleteAllItems()
{
    if (this->isEmpty()) {
        return;
    }

    while (!this->isEmpty()) {
        this->deleteFirstItem();
    }
}

void LinkedList::appendItem(ListItem* item)
{
    if (this->isEmpty()) {
        this->head = item;
    }
    else {
        this->getTail()->setNext(item);
    }
    item->setPrev(this->getTail());    

    this->tail = item;
}

void LinkedList::deleteFirstItem()
{
    if (this->isEmpty()) {
        return;
    }

    ListItem* toDelete = this->getHead();

    if (this->getHead()->getNext() == nullptr) {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        this->head = this->getHead()->getNext();
    }

    delete toDelete;
}

bool LinkedList::isEmpty()
{
    return this->head == nullptr && this->tail == nullptr;
}

void LinkedList::print()
{
    ListItem* iterator = this->getHead();
    while (iterator != nullptr) {
        std::cout << iterator->getPayload() << std::endl;
        iterator = iterator->getNext();
    }
}

// Selection sort / tøídìní pøímým výbìrem
void LinkedList::sort()
{
    if (this->isEmpty()) {
        return;
    }

    ListItem* item = this->head;

    while (item != this->tail) {
        ListItem* iterator = item;
        ListItem* minItem = item;
        while (iterator != nullptr) {
            if (iterator->getPayload() != minItem->getPayload()) {
                if (iterator->getPayload() <= minItem->getPayload()) {
                    minItem = iterator;
                }
            }

            iterator = iterator->getNext();
        }

        item->swapPayloadWith(minItem); // prohazovanim hodnot nemusim resit prohazovani celych objektu a pointeru, sice porusuji princip immutability objektu, ale jako prakticke reseni resi mnoho okrajovych pripadu "by design", bez velkeho usili
        item = item->getNext();
    }
}
