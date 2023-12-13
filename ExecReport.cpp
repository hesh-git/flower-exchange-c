//
// Created by ASUS on 12/13/2023.
//

#include "ExecReport.h"

#include <utility>

ExecReport::ExecReport(std::string  orderID, std::string  clientOrderID, std::string instrument,
                       int quantity, double price, int side, int status, std::string  reason, std::string  transactionTime)
        : orderID(std::move(orderID)), clientOrderID(std::move(clientOrderID)), instrument(std::move(instrument)), quantity(quantity),
          price(price), side(side), status(status), reason(std::move(reason)), transactionTime(std::move(transactionTime)) {}

//Getters

std::string ExecReport::getClientOrderID() const {
    return clientOrderID;
}

std::string ExecReport::getOrderID() const {
    return orderID;
}

std::string ExecReport::getInstrument() const {
    return instrument;
}

int ExecReport::getQuantity() const {
    return quantity;
}

double ExecReport::getPrice() const {
    return price;
}

int ExecReport::getSide() const {
    return side;
}

int ExecReport::getStatus() const {
    return status;
}

std::string ExecReport::getReason() const {
    return reason;
}

std::string ExecReport::getTransactionTime() const {
    return transactionTime;
}


