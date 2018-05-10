//
// Created by tomur on 03.05.2018.
//

#include "ListOfBuyers.h"
#include "ListOfTransactions.h"

void ListOfBuyers::addPointer(Transaction *transaction) {
    for (int i = 0; i < pointers.size(); i++) //adds pointer to vector if it not already added
    {
        if (pointers.at(i) == transaction) {
            cout << "buyer pointer repeat" << endl;
            return;
        }
    }
    pointers.push_back(transaction);
}

unsigned long long int ListOfBuyers::vectorSize() {
    return pointers.size();
}

ListOfBuyers *ListOfBuyers::getNext() const {
    return next;
}

void ListOfBuyers::setNext(ListOfBuyers *next) {
    ListOfBuyers::next = next;
}

const string &ListOfBuyers::getName() const {
    return name;
}

void ListOfBuyers::setName(const string &name) {
    ListOfBuyers::name = name;
}

void ListOfBuyers::printTransactions() {
    for (int i = 0; i < pointers.size(); i++) {
        pointers.at(i)->print();
        printf("\n");
    }
}

ListOfBuyers::ListOfBuyers(string name) {
    cout << "ListOfBuyers constructor called" << endl;
    ListOfBuyers::name = name;
    next = nullptr;
}

ListOfBuyers::~ListOfBuyers() {
    cout << "ListOfBuyers destructor called" << endl;
}

void ListOfBuyers::update(ListOfTransactions *first) {
    Transaction *tmp = first->getFirst();
    while (tmp) {
        if (tmp->getBuyer() == name) {
            addPointer(tmp);
        }
        tmp = tmp->getNext();
    }
    tmp = first->getFirst();
    for (int i = 0; i < pointers.size(); i++) {
        if (pointers.at(i) == nullptr) {
            pointers.erase(pointers.begin() + i); //deletes pointers at position 'i'
            continue;
        }
        if (pointers.at(i)->getBuyer() != name) //if name is no longer matching
        {
            pointers.erase(pointers.begin() + i); //deletes pointers at position 'i'
        }
    }

}

vector<Transaction *> ListOfBuyers::getTransactionPointers() {
    return pointers;
}

void ListOfBuyers::setPointer(int position, Transaction *address) {
    pointers.at(position) = address;
}
