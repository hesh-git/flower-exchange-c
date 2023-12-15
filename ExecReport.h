//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_EXECREPORT_H
#define PROJECT_EXECREPORT_H


#include <string>
#include <vector>
#include "Order.h"
using namespace std;

class ExecReport {
private:
    vector<Order> executionReport;

public:
    void setExecutionReport(vector<Order> &executionReport);

    vector<Order> &getExecutionReport();

};


#endif //PROJECT_EXECREPORT_H
