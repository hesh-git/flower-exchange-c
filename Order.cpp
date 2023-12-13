//
// Created by ASUS on 12/13/2023.
//

#include "Order.h"

#include <utility>

Order::Order(std::string clientOrderID,std::string instrument, int side, double price, int quantity)
    : clientOrderID(std::move(clientOrderID)), instrument(std::move(instrument)), side(side), price(price), quantity(quantity) {}

    //Getters

std::string Order::getClientOrderID() const {
    return clientOrderID;
}

std::string Order::getInstrument() const {
    return instrument;
}

int Order::getSide() const {
    return side;
}

double Order::getPrice() const {
    return price;
}

int Order::getQuantity() const {
    return quantity;
}

// Validating the input orders
bool Order::validateOrder() const {
    // Validation logic
    return true;
}