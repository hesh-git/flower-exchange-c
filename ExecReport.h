//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_EXECREPORT_H
#define PROJECT_EXECREPORT_H


#include <string>

class ExecReport {
private:
    std::string clientOrderID;
    std::string orderID;
    std::string instrument;
    int quantity{};
    double price{};
    int side{};
    int status{};
    std::string reason;
    std::string transactionTime;

public:

    ExecReport(std::string  orderID, std::string  clientOrderID, std::string  instrument,
                    int quantity, double price, int side, int status, std::string  reason, std::string  transactionTime);

    //Getters
    const std::string &getClientOrderId() const;

    void setClientOrderId(const std::string &clientOrderId);

    const std::string &getOrderId() const;

    void setOrderId(const std::string &orderId);

    const std::string &getInstrument() const;

    void setInstrument(const std::string &instrument);

    int getQuantity() const;

    void setQuantity(int quantity);

    double getPrice() const;

    void setPrice(double price);

    int getSide() const;

    void setSide(int side);

    int getStatus() const;

    void setStatus(int status);

    const std::string &getReason() const;

    void setReason(const std::string &reason);

    const std::string &getTransactionTime() const;

    void setTransactionTime(const std::string &transactionTime);

};


#endif //PROJECT_EXECREPORT_H
