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

    std::string getClientOrderID() const;
    std::string getOrderID() const;
    std::string getInstrument() const;
    int getQuantity() const;
    double getPrice() const;
    int getSide() const;
    int getStatus() const;
    std::string getReason() const;
    std::string getTransactionTime() const;


};


#endif //PROJECT_EXECREPORT_H
