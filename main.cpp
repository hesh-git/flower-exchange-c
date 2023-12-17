//
// Created by USER on 12/16/2023.
//

#include <iostream>
#include "fileService.h"
#include "Order.h"
#include "ExecReport.h"
#include "OrderBook.h"

int main() {
    string ordersFile = R"(..\OrdersFiles\example_6.csv)";
    string execReportFile = R"(..\ExecReportFiles\example_6.csv)";

    vector<Order> ordersVector =  FileService::readAndProcessOrders(ordersFile);

    // Validate each order in orders vector using validate method in Order class
    for (Order &order : ordersVector) {
        order.validateOrder();
    }

    ExecReport execReport;

    // Create separate order book for each instrument type
    OrderBook roseOrderBook((string &) "Rose");
    OrderBook lavenderOrderBook((string &) "Lavender");
    OrderBook lotusOrderBook((string &) "Lotus");
    OrderBook tulipOrderBook((string &) "Tulip");
    OrderBook orchidOrderBook((string &) "Orchid");

    // Execute each order
    for (size_t i = 0; i < ordersVector.size(); i++) {
        std::string strNumber = std::to_string(i+1);    // Generate a unique order ID for each order
        ordersVector[i].setOrderId("ord" + strNumber);
        if (ordersVector[i].getStatus() == "Accepted"){
            std::string instrument = ordersVector[i].getInstrument();
            if (instrument == "Rose") {
                roseOrderBook.processOrder(ordersVector[i], execReport);
            } else if (instrument == "Lavender") {
                lavenderOrderBook.processOrder(ordersVector[i], execReport);
            } else if (instrument == "Lotus") {
                lotusOrderBook.processOrder(ordersVector[i], execReport);
            } else if (instrument == "Tulip") {
                tulipOrderBook.processOrder(ordersVector[i], execReport);
            } else if (instrument == "Orchid") {
                orchidOrderBook.processOrder(ordersVector[i], execReport);
            }
        } else {
            ordersVector[i].setExecStatus("Reject");
            execReport.getExecReport().push_back(ordersVector[i]);
        }
    }

    cout << "Execution list size: " << execReport.getExecReport().size() << "\n" << endl;
    cout << "----------------- Execution List -----------------------" << endl;
    for (size_t i = 0; i < execReport.getExecReport().size(); i++) {
        cout << execReport.getExecReport()[i].getOrderId() << " "<< execReport.getExecReport()[i].getClientOrderId() << " " << execReport.getExecReport()[i].getInstrument() << " " << execReport.getExecReport()[i].getSide() << " " << execReport.getExecReport()[i].getExecStatus() << " " << execReport.getExecReport()[i].getQuantity() << " " << execReport.getExecReport()[i].getPrice() << " " << execReport.getExecReport()[i].getReason() << " " << execReport.getExecReport()[i].getTransactionTime() << endl;
    }
    cout << "--------------------------------------------------------\n" << endl;

    // Write CSV file
    cout << "Writing CSV file..." << endl;
    FileService::writeExecutionReportToFile(execReportFile, execReport.getExecReport());
    cout << "CSV file written successfully!\n" << endl;

    cout << "============Exchange App Ended!============\n" << endl;

    return 0;

}
