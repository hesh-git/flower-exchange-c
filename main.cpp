//
// Created by USER on 12/16/2023.
//

#include <iostream>
#include "fileService.h"
#include "Order.h"

int main() {
    string ordersFile = R"(..\OrdersFiles\example_8.csv)";
    string execReportFile = R"(..\ExecReportFiles\example_8.csv)";

    vector<Order> ordersVector =  FileService::readAndProcessOrders(ordersFile);

    // Validate each order in orders vector using validate method in Order class
    for (Order &order : ordersVector) {
        order.validateOrder();
    }



    return 0;

}
