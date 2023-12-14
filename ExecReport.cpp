//
// Created by ASUS on 12/13/2023.
//

#include "ExecReport.h"

#include <utility>

ExecReport::ExecReport(std::string  orderID, std::string  clientOrderID, std::string instrument,
                       int quantity, double price, int side, int status, std::string  reason, std::string  transactionTime)
        : orderID(std::move(orderID)), clientOrderID(std::move(clientOrderID)), instrument(std::move(instrument)), quantity(quantity),
          price(price), side(side), status(status), reason(std::move(reason)), transactionTime(std::move(transactionTime)) {}

const std::string &ExecReport::getClientOrderId() const {
    return clientOrderID;
}

void ExecReport::setClientOrderId(const std::string &clientOrderId) {
    clientOrderID = clientOrderId;
}

const std::string &ExecReport::getOrderId() const {
    return orderID;
}

void ExecReport::setOrderId(const std::string &orderId) {
    orderID = orderId;
}

const std::string &ExecReport::getInstrument() const {
    return instrument;
}

void ExecReport::setInstrument(const std::string &instrument) {
    ExecReport::instrument = instrument;
}

int ExecReport::getQuantity() const {
    return quantity;
}

void ExecReport::setQuantity(int quantity) {
    ExecReport::quantity = quantity;
}

double ExecReport::getPrice() const {
    return price;
}

void ExecReport::setPrice(double price) {
    ExecReport::price = price;
}

int ExecReport::getSide() const {
    return side;
}

void ExecReport::setSide(int side) {
    ExecReport::side = side;
}

int ExecReport::getStatus() const {
    return status;
}

void ExecReport::setStatus(int status) {
    ExecReport::status = status;
}

const std::string &ExecReport::getReason() const {
    return reason;
}

void ExecReport::setReason(const std::string &reason) {
    ExecReport::reason = reason;
}

const std::string &ExecReport::getTransactionTime() const {
    return transactionTime;
}

void ExecReport::setTransactionTime(const std::string &transactionTime) {
    ExecReport::transactionTime = transactionTime;
}




