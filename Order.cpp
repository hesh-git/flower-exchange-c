//
// Created by ASUS on 12/13/2023.
//

#include "Order.h"

#include <utility>

Order::Order(std::string clientOrderID, std::string instrument, int side, double price, int quantity)
    : clientOrderID(std::move(clientOrderID)), instrument(std::move(instrument)), side(side), price(price), quantity(quantity) {}
