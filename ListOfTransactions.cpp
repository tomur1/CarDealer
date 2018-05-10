//
// Created by tomur on 03.05.2018.
//

#include "ListOfTransactions.h"


Transaction *ListOfTransactions::getFirst() const {
    return first;
}

void ListOfTransactions::setFirst(Transaction *first) {
    ListOfTransactions::first = first;
}

ListOfTransactions::ListOfTransactions() {
    cout << "ListOfTransactions constructor called" << endl;
    first = nullptr;
}

ListOfTransactions::~ListOfTransactions() {
    cout << "ListOfTransactions destructor called" << endl;
    Transaction *tmp = first;
    while (tmp) {
        Transaction *deleteMe = tmp;
        tmp = tmp->getNext();
        delete deleteMe;
    }
}

void ListOfTransactions::AddTransaction(string model, string color, int id, string buyer, float money_paid,
                                        float money_to_pay) {
    Transaction *tmp = first;
    while (tmp) {
        if (id == tmp->getId()) {
            cout << "ID repeat" << endl;
            return;
        }
        tmp = tmp->getNext();
    }
    Transaction *newTransaction = new Transaction(model, color, id, buyer, money_paid, money_to_pay);
    if (first == nullptr) {
        first = newTransaction;
        newTransaction->setNext(nullptr);
        cout << "added first element" << endl;
        return;
    } else {
        tmp = first;
        if (tmp->getId() > newTransaction->getId()) {
            newTransaction->setNext(tmp);
            first = newTransaction;
            cout << "added as first in not empty list" << endl;
            return;
        }
        while (tmp->getNext() != nullptr) {
            if (newTransaction->getId() < tmp->getNext()->getId()) {
                newTransaction->setNext(tmp->getNext());
                tmp->setNext(newTransaction);
                cout << "added element in between" << endl;
                return;
            }
            tmp = tmp->getNext();
        }
        tmp->setNext(newTransaction);
        newTransaction->setNext(nullptr);
        cout << "added element as last" << endl;
    }
}

void ListOfTransactions::removeTransaction(int id) {
    if (first == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Transaction *tmp = first;
    bool deleted;
    while (tmp->getNext() != nullptr) {
        deleted = false;
        if (tmp->getNext()->getId() == id) //DESTROY HIM
        {
            Transaction *deleteMe = tmp->getNext();
            if (tmp->getNext()->getNext() != nullptr) {
                tmp->setNext(tmp->getNext()->getNext());
            } else {
                tmp->setNext(nullptr);
            }

            delete deleteMe;
            deleted = true;
        }
        if (!deleted) {
            tmp = tmp->getNext();
        }

    }
    if (first->getId() == id) {
        if (first->getNext() != nullptr) {
            Transaction *deleteMe = first;
            first = first->getNext();
            delete deleteMe;
        } else {
            delete first;
            first = nullptr;
        }
    }
}

void ListOfTransactions::printAllTransactions() {
    Transaction *tmp = first;
    while (tmp) {
        tmp->print();
        printf("\n");
        tmp = tmp->getNext();
    }

}

void ListOfTransactions::printSingleTransaction(int id) {
    Transaction *tmp = first;
    while (tmp) {
        if (tmp->getId() == id) {
            tmp->print();
            return;
        }
        tmp = tmp->getNext();
    }
    cout << "no transaction of ID: " << id << " found" << endl;
}

Transaction *ListOfTransactions::modifyTransaction(int id) {
    Transaction *tmp = first;
    while (tmp) {
        if (tmp->getId() == id) {
            return tmp;
        }
        tmp = tmp->getNext();
    }
    cout << "Transaction of that ID doesn't exist" << endl;
    return nullptr;
}


