//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_ORDER_H
#define PROJECT_ORDER_H


#include <string>

class Order {
private:
    std::string clientOrderID;
    std::string instrument;
    int side;
    double price;
    int quantity;

public:

    Order(std::string  clientOrderID, std::string  instrument, int side, double price, int quantity);

    //Getters

    std::string getClientOrderID() const;
    std::string getInstrument() const;
    int getSide() const;
    double getPrice() const;
    int getQuantity() const;

    // Validating the input orders
    bool validateOrder() const;

};


#endif //PROJECT_ORDER_H
