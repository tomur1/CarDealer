//
// Created by tomur on 03.05.2018.
//

#ifndef CARDEALER_LISTOFBUYERS_H
#define CARDEALER_LISTOFBUYERS_H


#include <c++/4.8.3/vector>
#include "Transaction.h"
#include "ListOfTransactions.h"
#include <iostream>

using namespace std;

class ListOfBuyers {
private:
    string name;
    ListOfBuyers *next;
    std::vector<Transaction *> pointers;
public:

    void addPointer(Transaction *transaction);

    unsigned long long int vectorSize();

    vector<Transaction *> getTransactionPointers();

    void setPointer(int position, Transaction *address); //sets pointer at position in vector
    ListOfBuyers *getNext() const; //getter for *next
    void setNext(ListOfBuyers *next); //setter for *next
    const string &getName() const; //getter for name
    void setName(const string &name); //setter for name
    void printTransactions(); //prints every Transaction that pointers are pointing to
    void update(ListOfTransactions *);

    //constructor will assign lowest free ID value, assign next and scan for name occurrences in transactions and add pointers to them to vector if it finds them.
    ListOfBuyers(string name);

    ~ListOfBuyers(); //destructor will delete ListOfBuyers variables. It will not delete the Transaction objects

};


#endif //CARDEALER_LISTOFBUYERS_H
