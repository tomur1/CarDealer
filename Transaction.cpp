//
// Created by tomur on 03.05.2018.
//

#include "Transaction.h"

Transaction *Transaction::getNext() const {
    return next;
}

void Transaction::setNext(Transaction *next) {
    Transaction::next = next;
}

int Transaction::getId() const {
    return id;
}

void Transaction::setId(int id) {
    Transaction::id = id;
}

const string &Transaction::getBuyer() const {
    return buyer;
}

void Transaction::setBuyer(const string &buyer) {
    Transaction::buyer = buyer;
}

const Car &Transaction::getCar() const {
    return car;
}

void Transaction::setCar(const Car &car) {
    Transaction::car = car;
}

float Transaction::getMoney_paid() const {
    return money_paid;
}

void Transaction::setMoney_paid(float money_paid) {
    Transaction::money_paid = money_paid;
}

float Transaction::getMoney_to_pay() const {
    return money_to_pay;
}

void Transaction::setMoney_to_pay(float money_to_pay) {
    Transaction::money_to_pay = money_to_pay;
}

bool Transaction::getOwns_money() const {
    return owns_money;
}

void Transaction::setOwns_money(bool owns_money) {
    Transaction::owns_money = owns_money;
}

void Transaction::print() {
    cout << "id: " << id << endl;
    cout << "model: " << car.getModel() << endl;
    cout << "color: " << car.getColor() << endl;
    cout << "buyer: " << buyer << endl;
    cout << "money_paid: " << money_paid << endl;
    cout << "money_to_pay: " << money_to_pay << endl;
    if (owns_money) {
        cout << "owns money: TRUE" << endl;
    } else {
        cout << "owns money: FALSE" << endl;
    }
}

Transaction::Transaction(string model, string color, int id, string buyer, float money_paid, float money_to_pay) : car(
        model, color) {
    cout << "Transaction constructor called" << endl;
    Transaction::id = id;
    Transaction::buyer = buyer;
    Transaction::money_paid = money_paid;
    Transaction::money_to_pay = money_to_pay;
    owns_money = money_paid < money_to_pay;
    Transaction::next = nullptr;
}

Transaction::~Transaction() {
    cout << "Transaction destructor called" << endl;
}


