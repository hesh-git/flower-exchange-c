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
    static std::vector<std::map<std::string, std::string>> readOrdersFromFile(const std::string& filename);

    // Method to write execution reports to execution_report.csv
    static void writeExecutionReportsToFile(const std::vector<ExecReport>& reports, const std::string& filename);
};

#endif