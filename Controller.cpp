//
// Created by tomur on 03.05.2018.
//

#include "Controller.h"


Transaction *Controller::modifyTransaction(int id) {
    return listOfTransactions->modifyTransaction(id);
}

void
Controller::addTransaction(string model, string color, int id, string buyer, float money_paid, float money_to_pay) {
    if (checkIfInDebt(buyer)) {
        cout << "Buyer has already 3 or more unpaid cars so he cannot buy another" << endl;
        return;
    }
    listOfTransactions->AddTransaction(model, color, id, buyer, money_paid, money_to_pay);
    updateBuyers();
}

void Controller::removeTransaction(int id) {
    ListOfBuyers *tmp = firstListOfBuyers;
    while (tmp) //set tmp to proper buyer
    {
        if (tmp->getName() == listOfTransactions->modifyTransaction(id)->getBuyer()) {
            break;
        }
        tmp = tmp->getNext();
    }
    vector<Transaction *> list = tmp->getTransactionPointers();
    for (int i = 0; i < list.size(); i++) //removes transaction and resets pointer
    {
        if (list.at(i) == modifyTransaction(id)) {
            listOfTransactions->removeTransaction(id);
            tmp->setPointer(i, nullptr);
        }
    }
    updateBuyers();
}

void Controller::findBuyer(string buyer) {
    ListOfBuyers *tmp = firstListOfBuyers;
    bool found = false;
    while (tmp) {
        if (tmp->getName() == buyer) {
            tmp->printTransactions();
            found = true;
        }
        tmp = tmp->getNext();
    }
    if (!found) {
        cout << "no transaction of buyer: " << buyer << " found" << endl;
    }
}


void Controller::removeBuyer(string buyer) {
    ListOfBuyers *tmp = firstListOfBuyers;
    ListOfBuyers *previousTmp = firstListOfBuyers;
    bool advancePrevious = false;
    while (tmp) {
        if (tmp->getName() == buyer) //we want to delete this guy
        {
            if (tmp == firstListOfBuyers) //if deleteing first
            {
                ListOfBuyers *deleteMe = tmp;
                firstListOfBuyers = tmp->getNext();
                delete deleteMe;
                return;
            } else {
                ListOfBuyers *deleteMe = tmp;
                previousTmp->setNext(tmp->getNext());
                delete deleteMe;
                return;
            }
        }
        tmp = tmp->getNext();
        if (advancePrevious) {
            previousTmp = previousTmp->getNext();
        }
        advancePrevious = true;
    }
}

void Controller::printAllTransactions() {
    listOfTransactions->printAllTransactions();
}

void Controller::printSingleTransaction(int id) {
    listOfTransactions->printSingleTransaction(id);
}

void Controller::changeMoneyPaid(int id, float moneyPaid) {
    if (modifyTransaction(id) != nullptr) {
        modifyTransaction(id)->setMoney_paid(moneyPaid);
        if (moneyPaid < modifyTransaction(id)->getMoney_to_pay()) {
            modifyTransaction(id)->setOwns_money(true);
        } else {
            modifyTransaction(id)->setOwns_money(false);
        }
    } else {
        cout << "pointer is NULL" << endl;
    }

}

void Controller::changeBuyer(int id, string buyer) {
    if (modifyTransaction(id) != nullptr) {
        modifyTransaction(id)->setBuyer(buyer);
        updateBuyers();
    } else {
        cout << "pointer is NULL" << endl;
    }
}

void Controller::changeMoneyToPay(int id, float moneyToPay) {
    if (modifyTransaction(id) != nullptr) {
        modifyTransaction(id)->setMoney_to_pay(moneyToPay);
    } else {
        cout << "pointer is NULL" << endl;
    }

}

Controller::Controller() {
    cout << "Controller constructor called" << endl;
    listOfTransactions = new ListOfTransactions;
    firstListOfBuyers = nullptr;
}

Controller::~Controller() {
    cout << "Controller destructor called" << endl;
    delete firstListOfBuyers;
    delete listOfTransactions;
}

void Controller::updateBuyers() {
    ListOfBuyers *tmp = firstListOfBuyers;
    Transaction *tmpTrans = listOfTransactions->getFirst();
    while (tmpTrans) //checks if new buyer needs to be created
    {
        bool repeats = false;
        tmp = firstListOfBuyers;
        while (tmp) {
            if (tmpTrans->getBuyer() == tmp->getName()) {
                repeats = true;
                break;
            }
            tmp = tmp->getNext();
        }
        if (!repeats) {
            addBuyer(tmpTrans->getBuyer());
            break;
        }
        tmpTrans = tmpTrans->getNext();
    }
    tmp = firstListOfBuyers;
    bool deleted;
    while (tmp) {
        deleted = false;
        tmp->update(listOfTransactions);
        if (tmp->vectorSize() == 0) {
            const string &deleteHim = tmp->getName();
            tmp = tmp->getNext();
            removeBuyer(deleteHim);
            deleted = true;

        }
        if (!deleted) {
            tmp = tmp->getNext();
        }
    }
}

void Controller::addBuyer(string buyer) { //adds new buyer at the end of the list
    ListOfBuyers *newBuyer = new ListOfBuyers(buyer);
    ListOfBuyers *tmp = firstListOfBuyers;
    if (firstListOfBuyers == nullptr) {
        firstListOfBuyers = newBuyer;
        return;
    }
    while (tmp) {
        if (tmp->getNext() == nullptr) {
            tmp->setNext(newBuyer);
            return;
        }
        tmp = tmp->getNext();
    }
}

void Controller::removeBuyerAndTransactions(string buyer) {
    if (listOfTransactions->getFirst() == nullptr) {
        cout << "list is empty cannot remove" << endl;
        return;
    }
    ListOfBuyers *tmp = firstListOfBuyers;
    bool found = false;

    while (tmp) {
        if (tmp->getName() == buyer) {
            found = true;
            break;
        }
        tmp = tmp->getNext();
    }
    vector<Transaction *> list = tmp->getTransactionPointers();
    for (int i = 0; i < list.size(); i++) {
        removeTransaction(list.at(i)->getId());
        tmp->setPointer(i, nullptr);
    }
    updateBuyers();
    if (!found) {
        cout << "no transaction of buyer: " << buyer << " found" << endl;
    }

}

bool Controller::checkIfInDebt(string buyer) {
    bool result = false;
    if (listOfTransactions->getFirst() != nullptr) {
        bool found = false;
        ListOfBuyers *tmp = firstListOfBuyers;
        while (tmp) {
            if (tmp->getName() == buyer) {
                found = true;
                break;
            }
            tmp = tmp->getNext();
        }
        if (!found) {
            return false;
        }
        vector<Transaction *> list = tmp->getTransactionPointers();
        int counter = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list.at(i)->getOwns_money()) {
                counter++;
            }
        }
        if (counter > 2) {
            result = true;
        }

    }
    return result;
}
