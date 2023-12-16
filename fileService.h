#ifndef FILE_SERVICE_H
#define FILE_SERVICE_H

#include <vector>
#include <map>
#include <string>
#include "Order.h"
#include "ExecReport.h"

class FileService {
public:
    // Method to read orders from orders.csv
    static vector<Order> readAndProcessOrders(const string &filename);

    // Method to write execution reports to execution_report.csv
    static void writeExecutionReportToFile(const string &fileName, const vector<Order> &orders);
};

#endif