//
// Created by tomur on 03.05.2018.
//

#ifndef CARDEALER_TRANSACTION_H
#define CARDEALER_TRANSACTION_H


#include "Car.h"
#include <string>

using namespace std;

class Transaction {
private:
    int id;
    string buyer;
    Car car;
    float money_paid;
    float money_to_pay;
    bool owns_money;
    Transaction *next;
public:
    //getters and setters
    Transaction *getNext() const;

    void setNext(Transaction *next);

    int getId() const;

    void setId(int id);

    const string &getBuyer() const;

    void setBuyer(const string &buyer);

    const Car &getCar() const;

    void setCar(const Car &car);

    float getMoney_paid() const;

    void setMoney_paid(float money_paid);

    float getMoney_to_pay() const;

    void setMoney_to_pay(float money_to_pay);

    bool getOwns_money() const;

    void setOwns_money(bool owns_money);

    void print();//prints every variable of Transaction
    //constructor will assign values given as arguments and create class Car and also assign it
    Transaction(string model, string color, int id, string buyer, float money_paid, float money_to_pay);

    ~Transaction(); //deletes object and its variables;
};


#endif //CARDEALER_TRANSACTION_H
