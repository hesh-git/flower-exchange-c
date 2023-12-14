//
// Created by ASUS on 12/13/2023.
//

#include "Order.h"

#include <utility>

Order::Order(std::string clientOrderID,std::string instrument, int side, double price, int quantity)
    : clientOrderID(std::move(clientOrderID)), instrument(std::move(instrument)), side(side), price(price), quantity(quantity) {}

    //Getters Setters

int Order::getSide() const {
    return side;
}

double Order::getPrice() const {
    return price;
}

int Order::getQuantity() const {
    return quantity;
}

const std::string &Order::getClientOrderId() const {
    return clientOrderID;
}

void Order::setClientOrderId(const std::string &clientOrderId) {
    clientOrderID = clientOrderId;
}

const std::string &Order::getInstrument() const {
    return instrument;
}

void Order::setInstrument(const std::string &instrument) {
    Order::instrument = instrument;
}

void Order::setSide(int side) {
    Order::side = side;
}

void Order::setQuantity(int quantity) {

}

void Order::setPrice(double price) {

}

// Validating the input orders
bool Order::validateOrder() const {
    // Validation logic
    return true;
}




