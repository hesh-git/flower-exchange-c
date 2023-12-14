//
// Created by ASUS on 12/13/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "OrderBook.h"

void OrderBook::readOrders(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string clientOrderID, instrument, sideStr;
        int side, quantity;
        double price;

        if (!(iss >> clientOrderID >> instrument >> sideStr >> price >> quantity)) {
            // Handle error while reading the line
            continue;
        }

        // Convert side from string to integer
        if (sideStr == "1") {
            side = 1;  // Buy
        } else if (sideStr == "2") {
            side = 2;  // Sell
        } else {
            // Handle invalid side value
            continue;
        }

        Order order(clientOrderID, instrument, side, price, quantity);
        orders.push_back(order);
    }
}

void OrderBook::processOrders() {
    for (const auto& order : orders) {

        // Process orders
        if (order.getSide() == 1) {
            // Buy order
            std::cout << "Processing buy order - Client Order ID: " << order.getClientOrderId()
                      << ", Instrument: " << order.getInstrument()
                      << ", Quantity: " << order.getQuantity()
                      << ", Price: " << order.getPrice()
                      << std::endl;
        } else if (order.getSide() == 2) {
            // Sell order
            std::cout << "Processing sell order - Client Order ID: " << order.getClientOrderId()
                      << ", Instrument: " << order.getInstrument()
                      << ", Quantity: " << order.getQuantity()
                      << ", Price: " << order.getPrice()
                      << std::endl;
        }

        // Perform processing and generate execution report
        ExecReport report{
                "ExecID123", // Replace with your logic to generate ExecutionID
                order.getClientOrderId(),
                order.getInstrument(),
                order.getQuantity(),
                order.getPrice(),
                order.getSide(),
                2, // Assuming the order is filled
                "", // No reason for success
                "20231210-120000.000" // Replace with your logic to generate transaction time
        };

        executionReports.push_back(report);
    }
}

void OrderBook::writeExecutionReport(const std::string& filename) {
    std::ofstream file(filename);

    file << "Name,Type,Possible Values,Mandatory,Notes\n";
    file << "Client Order ID,String,,Yes,This is the Client Order ID of the submitted order\n";
    file << "Order ID,String,,Yes,System generated unique order ID\n";
    file << "Instrument,String,(Rose, Lavender, Lotus, Tulip, Orchid),Yes,We will limit the instruments for these 5 types only\n";
    file << "Side,Int,1: Buy 2: Sell,Yes,Specifies if the order is a buy order or a sell order\n";
    file << "Price,Double,Price > 0.0,Yes,Price of one unit\n";
    file << "Quantity,Int,(10, 20, 30, 1000),Yes,Quantity of the order\n";
    file << "Status,Int,0-New 1- Rejected 3-Pfill 2-Fill,Yes,The status of the execution report\n";
    file << "Reason,String,,No,Contains the reject reason, when an order is not accepted into the system due to validation failure\n";
    file << "Transaction Time,String,YYYYMMDD-HHMMSS.sss,Yes,Every execution report should have the transaction time in the given format. This data can be used to check the speed and optimize your code\n";

    for (const auto& report : executionReports) {
        file << report.getClientOrderId() << ","
             << report.getOrderId() << ","
             << report.getInstrument() << ","
             << report.getSide() << ","
             << std::fixed << std::setprecision(2) << report.getPrice() << ","
             << report.getQuantity() << ","
             << report.getStatus() << ","
             << report.getReason() << ","
             << report.getTransactionTime() << "\n";
    }
}

void OrderBook::processSellOrders(const Order &order) {


}

void OrderBook::processBuyOrders(const Order &order) {

}

