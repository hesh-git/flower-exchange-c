//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_EXECREPORT_H
#define PROJECT_EXECREPORT_H


#include <string>

class ExecReport {
public:
    std::string executionID;
    std::string clientOrderID;
    std::string symbol;
    int quantity{};
    double price{};
    int side{};
    int status{};
    std::string reason;
    std::string transactionTime;

    ExecReport(std::string  executionID, std::string  clientOrderID, std::string  symbol,
                    int quantity, double price, int side, int status, std::string  reason, std::string  transactionTime);
};

};


#endif //PROJECT_EXECREPORT_H
