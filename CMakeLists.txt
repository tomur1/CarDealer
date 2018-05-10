cmake_minimum_required(VERSION 3.10)
project(CarDealer)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(CarDealer
        Car.cpp
        Car.h
        Controller.cpp
        Controller.h
        ListOfBuyers.cpp
        ListOfBuyers.h
        ListOfTransactions.cpp
        ListOfTransactions.h
        main.cpp
        Transaction.cpp
        Transaction.h)
