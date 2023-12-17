//
// Created by USER on 12/16/2023.
//

#include <iostream>
#include "fileService.h"
#include "Order.h"
#include "ExecReport.h"
#include "OrderBook.h"


int main() {
    cout << "*********************** START **************************\n" << endl;
    cout << "1. Reading orders.csv file...\n" << endl;

    string ordersFile = R"(..\OrdersFiles\example_8.csv)";
    string execReportFile = R"(..\ExecReportFiles\example_8.csv)";

    cout << "2. Creating Orders Vector\n" << endl;
    vector<Order> ordersVector =  FileService::readAndProcessOrders(ordersFile);

    cout << "3. Validating orders\n" << endl;
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

    cout << "4. Matching orders\n" << endl;
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

    cout << "5. Writing Execution Report Details into CSV file...\n" << endl;
    FileService::writeExecutionReportToFile(execReportFile, execReport.getExecReport());
    cout << "Final execution reports can be inspected in ExecReportFiles folder in the project directory!\n" << endl;

    cout << "*********************** END **************************" << endl;

    return 0;

}
