//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_ORDER_H
#define PROJECT_ORDER_H


#include <string>

class Order {
private:
    std::string clientOrderID;
    std::string instrument;
    int side;
    double price;
    int quantity;

public:

    Order(std::string  clientOrderID, std::string  instrument, int side, double price, int quantity);

    //Getters Setters
    const std::string &getClientOrderId() const;

    void setClientOrderId(const std::string &clientOrderId);

    const std::string &getInstrument() const;

    void setInstrument(const std::string &instrument);

    int getSide() const;

    void setSide(int side);

    double getPrice() const;

    void setPrice(double price);

    int getQuantity() const;

    void setQuantity(int quantity);

    // Validating the input orders
    bool validateOrder() const;

};


#endif //PROJECT_ORDER_H
