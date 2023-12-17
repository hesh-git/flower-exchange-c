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
    string sideStr;
    string priceStr;
    string quantityStr;

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

    const string &getSideStr() const;
    void setSideStr(const string &sideStr);

    const string &getPriceStr() const;
    void setPriceStr(const string &priceStr);

    const string &getQuantityStr() const;
    void setQuantityStr(const string &quantityStr);


    void validateOrder();
};


#endif //PROJECT_ORDER_H
