//
// Created by tomur on 03.05.2018.
//

#ifndef CARDEALER_CONTROLLER_H
#define CARDEALER_CONTROLLER_H


#include "ListOfBuyers.h"
#include "Transaction.h"
#include "ListOfTransactions.h"
#include <iostream>

using namespace std;

class Controller {
private:
    ListOfTransactions *listOfTransactions;
    ListOfBuyers *firstListOfBuyers;

    Transaction *modifyTransaction(int id); //returns reference to transaction enabling value modification
    void addBuyer(string buyer); //adds new list of buyers and to the list !Should not be used directly by user
    void removeBuyer(
            string buyer); //deletes ListOfBuyers object associated with given name. Does not delete transactions !Should not be used directly by user
public:
    //adds transaction to the list if id does not repeat and buyer owns money 2 times or less Also will create new ListOfBuyers if the buyer is new
    void addTransaction(string model, string color, int id, string buyer, float money_paid, float money_to_pay);

    void removeTransaction(int id); //Removes transaction of given ID
    void findBuyer(string buyer); //prints all transactions concerning given buyer
    void removeBuyerAndTransactions(string buyer); //deletes ListOfBuyers object and his transactions
    void printAllTransactions(); //prints all information in all transactions
    void printSingleTransaction(
            int id); //prints single transaction for given ID if dosn't exist the printTransactions that dosn't exist
    void changeMoneyPaid(int id, float moneyPaid);

    void changeBuyer(int id, string buyer);

    void changeMoneyToPay(int id, float moneyToPay);

    void
    updateBuyers(); //iterates through every buyer and executes check if there are any new buyers that need to be added or removed
    bool checkIfInDebt(string buyer); //returns true if buyer has already
    Controller(); //constructor sets listOfTransaction and firstListOfBuyers pointers to NULL
    ~Controller(); //destructor iterates through firstListOfBuyers and ListOfTransactions and deallocates memory
};


#endif //CARDEALER_CONTROLLER_H
