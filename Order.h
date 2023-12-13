//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_ORDER_H
#define PROJECT_ORDER_H


#include <string>

class Order {
public:
    std::string clientOrderID;
    std::string instrument;
    int side{};
    double price{};
    int quantity{};

    Order(std::string  clientOrderID, std::string  instrument, int side, double price, int quantity);

};


#endif //PROJECT_ORDER_H
