//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_ORDERBOOK_H
#define PROJECT_ORDERBOOK_H


#include <vector>
#include "Order.h"
#include "ExecReport.h"

class OrderBook {
private:
    std::vector<Order> orders;
    std::vector<ExecReport> executionReports;

public:
    void readOrders(const std::string& filename);
    void processOrders();
    void writeExecutionReport(const std::string& filename);

};


#endif //PROJECT_ORDERBOOK_H
