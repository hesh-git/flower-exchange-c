// fileService.cpp
#include "FileService.h"
#include <fstream>
#include <sstream>
#include "ExecReport.h"

std::vector<std::map<std::string, std::string>> FileService::readOrdersFromFile(const std::string& filename) {
    std::vector<std::map<std::string, std::string>> orders;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string header;
        if (std::getline(file, header)) {
            std::istringstream headerStream(header);
            std::vector<std::string> columns;
            std::string column;
            while (std::getline(headerStream, column, ',')) {
                columns.push_back(column);
            }

            std::string line;
            while (std::getline(file, line)) {
                std::istringstream lineStream(line);
                std::vector<std::string> values;
                std::string value;
                while (std::getline(lineStream, value, ',')) {
                    values.push_back(value);
                }

                if (values.size() == columns.size()) {
                    std::map<std::string, std::string> order;
                    for (size_t i = 0; i < columns.size(); ++i) {
                        order[columns[i]] = values[i];
                    }
                    orders.push_back(order);
                }
            }
        }
        file.close();
    }
    return orders;
}

void FileService::writeExecutionReportsToFile(const std::vector<ExecReport>& reports, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        // Write header
        file << "Client Order ID,Order ID,Instrument,Side,Price,Quantity,Status,Reason,Transaction Time\n";

        // Write data
        for (const auto& report : reports) {
            file << report.getClientOrderID() << ","
                 << report.getOrderID() << ","
                 << report.getInstrument() << ","
                 << report.getSide() << ","
                 << report.getPrice() << ","
                 << report.getQuantity() << ","
                 << report.getStatus() << ","
                 << report.getReason() << ","
                 << report.getTransactionTime() << "\n";
        }
        file.close();
    }
}
