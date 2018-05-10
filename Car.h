//
// Created by tomur on 03.05.2018.
//

#ifndef CARDEALER_CAR_H
#define CARDEALER_CAR_H

#include <iostream>

using namespace std;

class Car {
private:
    string model;
    string color;
public:
    //getters and setter
    const string &getModel() const;

    void setModel(const string &model);

    const string &getColor() const;

    void setColor(const string &color);

    void print();

    Car(string model, string color); //constructor will assign values to model and color
    ~Car(); //destructor
};


#endif //CARDEALER_CAR_H
