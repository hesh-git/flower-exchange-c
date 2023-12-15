//
// Created by ASUS on 12/13/2023.
//

#include "Order.h"
using namespace std;
#include <utility>

Order::Order() = default;

Order::Order(string &clientOrderId, string &instrument, int side, double price, int quantity) {
    clientOrderId = clientOrderId;
    instrument = instrument;
    side = side;
    price = price;
    quantity = quantity;
}

const string &Order::getClientOrderId() const {
    return clientOrderId;
}

void Order::setClientOrderId(const string &clientOrderId) {
    Order::clientOrderId = clientOrderId;
}

const string &Order::getInstrument() const {
    return instrument;
}

void Order::setInstrument(const string &instrument) {
    Order::instrument = instrument;
}

int Order::getSide() const {
    return side;
}

void Order::setSide(int side) {
    Order::side = side;
}

double Order::getPrice() const {
    return price;
}

void Order::setPrice(double price) {
    Order::price = price;
}

int Order::getQuantity() const {
    return quantity;
}

void Order::setQuantity(int quantity) {
    Order::quantity = quantity;
}

const string &Order::getStatus() const {
    return status;
}

void Order::setStatus(const string &status) {
    Order::status = status;
}

const string &Order::getReason() const {
    return reason;
}

void Order::setReason(const string &reason) {
    Order::reason = reason;
}

const string &Order::getExecStatus() const {
    return execStatus;
}

void Order::setExecStatus(const string &execStatus) {
    Order::execStatus = execStatus;
}

const string &Order::getTransactionTime() const {
    return transactionTime;
}

void Order::setTransactionTime(const string &transactionTime) {
    Order::transactionTime = transactionTime;
}

const string &Order::getOrderId() const {
    return orderId;
}

void Order::setOrderId(const string &orderId) {
    Order::orderId = orderId;
}

const string &Order::getSideStr() const {
    return sideStr;
}

void Order::setSideStr(const string &sideStr) {
    Order::sideStr = sideStr;
}

const string &Order::getPriceStr() const {
    return priceStr;
}

void Order::setPriceStr(const string &priceStr) {
    Order::priceStr = priceStr;
}

const string &Order::getQuantityStr() const {
    return quantityStr;
}

void Order::setQuantityStr(const string &quantityStr) {
    Order::quantityStr = quantityStr;
}










