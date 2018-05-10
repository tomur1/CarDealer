//
// Created by tomur on 03.05.2018.
//

#include "Car.h"

const string &Car::getModel() const {
    return Car::model;
}

void Car::setModel(const string &model) {
    Car::model = model;
}

const string &Car::getColor() const {
    return Car::color;
}

void Car::setColor(const string &color) {
    Car::color = color;
}

Car::Car(string model, string color) {
    cout << "Car constructor called" << endl;
    Car::color = color;
    Car::model = model;
}

Car::~Car() {
    cout << "Car destructor called" << endl;
}

void Car::print() {
    cout << "model: " << model << endl;
    cout << "color: " << color << endl;
}
