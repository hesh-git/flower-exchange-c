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

    //check it contain required fields
    if (clientOrderID.empty() || instrument.empty()) {
        return false;
    }

    //check for invalid instrument
    if (!(instrument == "Rose" || instrument == "Lavender" || instrument == "Lotus" || instrument == "Tulip" || instrument == "Orchid")) {
        return false;
    }

    //check for invalid side
    if (!(side == 1 || side == 2)) {
        return false;
    }

    //check prize is greater than 0
    if (price <= 0.0) {
        return false;
    }

    //is quantity multiple of 10
    if (quantity % 10 != 0) {
        return false;
    }

    // Check if quantity is within the range [10, 1000]
    if (quantity < 10 || quantity > 1000) {
        return false;
    }

    //check if clientOrderID is unique

    return true;
}