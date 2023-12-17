//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_ORDER_H
#define PROJECT_ORDER_H

#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    string clientOrderId;
    string instrument;
    int side;
    double price;
    int quantity;
    string status;
    string reason;
    string execStatus;
    string transactionTime;
    string orderId;
    string sideWithRejState;
    string priceWithRejState;
    string quantityWithRejState;

public:
    Order();    //    Default constructor
    Order(string &clientOrderId, string &instrument, int side, double price, int quantity);

    const string &getClientOrderId() const;
    void setClientOrderId(const string &clientOrderId);

    const string &getInstrument() const;
    void setInstrument(const string &instrument);

    int getSide() const;
    void setSide(int side);

    double getPrice() const;
    void setPrice(double price);

    int getQuantity() const;
    void setQuantity(int quantity);

    const string &getStatus() const;
    void setStatus(const string &status);

    const string &getReason() const;
    void setReason(const string &reason);

    const string &getExecStatus() const;
    void setExecStatus(const string &execStatus);

    const string &getTransactionTime() const;
    void setTransactionTime(const string &transactionTime);

    const string &getOrderId() const;
    void setOrderId(const string &orderId);

    const string &getSideWithRejState() const;
    void setSideWithRejState(const string &SideWithRejState);

    const string &getPriceWithRejState() const;
    void setPriceWithRejState(const string &priceWithRejState);

    const string &getQuantityWithRejState() const;
    void setQuantityWithRejState(const string &quantityWithRejState);


    void validateOrder();
};


#endif //PROJECT_ORDER_H
