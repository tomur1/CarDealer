//
// Created by tomur on 03.05.2018.
//

#ifndef CARDEALER_LISTOFTRANSACTIONS_H
#define CARDEALER_LISTOFTRANSACTIONS_H


#include "Transaction.h"

class ListOfTransactions {
private:
    Transaction *first;

public:
    //get and set
    Transaction *getFirst() const;

    void setFirst(Transaction *first);

    //adds transaction to the list if id does not repeat and buyer owns money 2 times or less Also will create new ListOfBuyers if the buyer is new
    void AddTransaction(string model, string color, int id, string buyer, float money_paid, float money_to_pay);

    void removeTransaction(int id); //Removes transaction of given ID
    void printAllTransactions(); //prints all information in all transactions
    void printSingleTransaction(
            int id); //prints single transaction for given ID if dosn't exist the printTransactions that dosn't exist
    Transaction *modifyTransaction(int id); //returns reference to transaction enabling value modification
    ListOfTransactions(); //constructor will assign first to null
    ~ListOfTransactions(); //destructor will go through all list and delete every Transaction
};


#endif //CARDEALER_LISTOFTRANSACTIONS_H
