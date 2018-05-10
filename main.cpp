#include <iostream>
#include "Controller.h"

int main() {
    Controller controller;
    /*
    // removing from empty
    controller.removeTransaction(1);
    controller.removeTransaction(2);
    controller.removeTransaction(3);
    controller.removeTransaction(4);
    controller.printAllTransactions();
    */

    /*
    //removing first element of transactions
    controller.addTransaction("Ferrari","Red",1,"Tomek",2000,2000);
    controller.addTransaction("Ferrari","Red",2,"Czesiek",2000,2000);
    controller.addTransaction("Ferrari","Red",3,"Franek",2000,2000);
    controller.removeTransaction(1);
    controller.printAllTransactions();
    */

    /*
    //removing last element of transactions
    controller.addTransaction("Ferrari","Red",1,"Tomek",2000,2000);
    controller.addTransaction("Ferrari","Red",2,"Czesiek",2000,2000);
    controller.addTransaction("Ferrari","Red",3,"Franek",2000,2000);
    controller.removeTransaction(3);
    controller.printAllTransactions();
    */

    /*
    //adding multiple transactions of the same ID
    controller.addTransaction("Ferrari","Red",1,"Tomek",2000,2000);
    controller.addTransaction("Ferrari","Red",1,"Czesiek",2000,2000);
    controller.addTransaction("Ferrari","Red",1,"Franek",2000,2000);
    controller.printAllTransactions();
    */

    /*
    //modifying nonresistant transaction
    controller.changeBuyer(1,"Pies");
    controller.changeMoneyPaid(2,200);
    controller.changeMoneyToPay(3,300);
    controller.printAllTransactions();
    */

    /*
    //modifying existing transaction
    controller.addTransaction("Ferrari","Red",1,"Tomek",5000,5000);
    controller.changeBuyer(1,"Pies");
    controller.changeMoneyPaid(1,200);
    controller.changeMoneyToPay(1,300);
    controller.printAllTransactions();
    */

    /*
    //adding transactions in not ordered ID
    controller.addTransaction("Ferrari","Red",5,"Tomek",2000,2000);
    controller.addTransaction("Ferrari","Red",3,"Czesiek",2000,2000);
    controller.addTransaction("Ferrari","Red",4,"Franek",2000,2000);
    controller.addTransaction("Ferrari","Red",1,"Beniek",2000,2000);
    controller.addTransaction("Ferrari","Red",2,"Heniek",2000,2000);
    controller.printAllTransactions();
    */

    /*
    //removing buyer that dosn't exist
    controller.removeBuyerAndTransactions("Pies");
    */

    /*
    //removing buyer that exists
    controller.addTransaction("Ferrari","Red",5,"Tomek",2000,2000);
    controller.removeBuyerAndTransactions("Tomek");
    controller.printAllTransactions();
    */

    /*
    //adding transaction with buyer that has more than 2 unpaid transactions already
    controller.addTransaction("Ferrari","Red",1,"Tomek",0,2000);
    controller.addTransaction("Ferrari","Red",2,"Tomek",0,2000);
    controller.addTransaction("Ferrari","Red",3,"Tomek",0,2000);
    controller.addTransaction("Ferrari","Red",4,"Tomek",0,2000);
    controller.printAllTransactions();
     */

    /*
    //checking to see if finding buyers prints correctly
    controller.addTransaction("Ferrari","Red",1,"Tomek",2000,2000);
    controller.addTransaction("Ferrari","Red",2,"Czesiek",2000,2000);
    controller.addTransaction("Ferrari","Blue",3,"Czesiek",2000,2000);
    controller.addTransaction("Ferrari","Red",4,"Franek",2000,2000);
    controller.addTransaction("Ferrari","Red",5,"Beniek",2000,2000);
    controller.addTransaction("Ferrari","Red",6,"Heniek",2000,2000);
    controller.findBuyer("Tomek");
    cout<<"--------------------"<<endl;
    controller.findBuyer("Franek");
    cout<<"--------------------"<<endl;
    controller.findBuyer("Heniek");
    cout<<"--------------------"<<endl;
    controller.findBuyer("Beniek");
    cout<<"--------------------"<<endl;
    controller.findBuyer("Czesiek");
    cout<<"--------------------"<<endl;
    */

    /*
    //removing transaction by ID and checking if ListOfBuyers is correct
    controller.addTransaction("Ferrari","Red",1,"Tomek",2000,2000);
    controller.addTransaction("Ferrari","Red",2,"Czesiek",2000,2000);
    controller.addTransaction("Ferrari","Red",3,"Franek",2000,2000);
    controller.removeTransaction(1);
    controller.findBuyer("Tomek");
    controller.printAllTransactions();
    */

    /*
    //testing prints on no transactions
    controller.printAllTransactions();
    controller.printSingleTransaction(1);
    controller.findBuyer("Ktos");
    */

    return 0;
}