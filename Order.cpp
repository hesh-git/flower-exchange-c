//
// Created by ASUS on 12/13/2023.
//

#include "Order.h"
using namespace std;
#include <utility>

Order::Order() = default;

Order::Order(string &clientOrderId, string &instrument, int side, double price, int quantity) {
    this->clientOrderId = clientOrderId;
    this->instrument = instrument;
    this->side = side;
    this->price = price;
    this->quantity = quantity;
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


// Validating the input orders
void Order::validateOrder(){

    //check it contain required fields
    if (clientOrderId.empty()) {
        setStatus("Rejected");
        setReason("Incorrect clientOrderId");
    }

    else if (instrument.empty()) {
        setStatus("Rejected");
        setReason("Instrument is missing");
    }

    //check for invalid instrument
    else if(!(instrument == "Rose" || instrument == "Lavender" || instrument == "Lotus" || instrument == "Tulip" || instrument == "Orchid")) {
        setStatus("Rejected");
        setReason("Invalid instrument");
    }

    //check for invalid side
    else if (!(side == 1 || side == 2)) {
        setStatus("Rejected");
        setReason("Invalid side");
    }

    //check prize is greater than 0
    else if (price <= 0.0) {
        setStatus("Rejected");
        setReason("Invalid price");
    }

    //is quantity multiple of 10
    else if (quantity % 10 != 0) {
        setStatus("Rejected");
        setReason("Invalid quantity");
    }

    // Check if quantity is within the range [10, 1000]
    else if (quantity < 10 || quantity > 1000) {
        setStatus("Rejected");
        setReason("Invalid quantity");
    }

    else {
        setStatus("Accepted");
        setReason("");
    }
}

