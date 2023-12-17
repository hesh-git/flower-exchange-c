//
// Created by USER on 12/16/2023.
//

#include <iostream>
#include "fileService.h"
#include "Order.h"
#include "ExecReport.h"
#include "OrderBook.h"

void printExecutionList(ExecReport execReport) {
    cout << "Execution list size: " << execReport.getExecReport().size() << "\n" << endl;
    cout << "----------------- Execution List -----------------------" << endl;
    for (size_t i = 0; i < execReport.getExecReport().size(); i++) {
        const auto& order = execReport.getExecReport()[i];
        cout << order.getOrderId() << " " << order.getClientOrderId() << " "
             << order.getInstrument() << " " << order.getSide() << " "
             << order.getExecStatus() << " " << order.getQuantity() << " "
             << order.getPrice() << " " << order.getReason() << " "
             << order.getTransactionTime() << endl;
    }
    cout << "--------------------------------------------------------\n" << endl;
}

int main() {
    cout << "===================Exchange App Started!===================\n" << endl;
    cout << "Reading Orders.csv file..." << endl;

    string ordersFile = R"(..\OrdersFiles\example_7.csv)";
    string execReportFile = R"(..\ExecReportFiles\example_7.csv)";

    cout << "Creating Orders Vector" << endl;
    vector<Order> ordersVector =  FileService::readAndProcessOrders(ordersFile);

    cout << "Validating orders" << endl;
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

    cout << "Processing orders\n" << endl;
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

    printExecutionList(execReport);

    // Write CSV file
    cout << "Writing CSV file..." << endl;
    FileService::writeExecutionReportToFile(execReportFile, execReport.getExecReport());
    cout << "CSV file written successfully!\n" << endl;

    cout << "============Exchange App Ended!============\n" << endl;

    return 0;

}
