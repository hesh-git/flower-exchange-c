//
// Created by ASUS on 12/13/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "OrderBook.h"
using namespace std;

OrderBook::OrderBook(std::string &type) {
    this->type = type;
}

void OrderBook::processOrder(Order order, ExecReport &executionReport) {
    int side = order.getSide();

    if (side == 1) {
        processBuyOrder(order, executionReport);
        sortBuyOrdersDescending(buyOrders);
    } else {
        processSellOrder(order, executionReport);
        sortSellOrdersAscending(sellOrders);
    }
}

void OrderBook::processBuyOrder(Order &order, ExecReport &executionReport) {
    if (sellOrders.empty()) {
        addNewBuyOrder(order, executionReport);
    } else {
        processBuyOrderWithSellOrders(order, executionReport);
    }
}

void OrderBook::processSellOrder(Order &order, ExecReport &executionReport) {
    if (buyOrders.empty()) {
        addNewSellOrder(order, executionReport);
    } else {
        processSellOrderWithBuyOrders(order, executionReport);
    }
}

void OrderBook::addNewBuyOrder(Order &order, ExecReport &executionReport) {
    order.setExecStatus("New");
    buyOrders.push_back(order);
    order.setTransactionTime(getTimeStamp());
    executionReport.getExecutionReport().push_back(order);
}

void OrderBook::addNewSellOrder(Order &order, ExecReport &execReport) {
    order.setExecStatus("New");
    sellOrders.push_back(order);
    order.setTransactionTime(getTimeStamp());
    execReport.getExecutionReport().push_back(order);
}

void OrderBook::processBuyOrderWithSellOrders(Order &order, ExecReport &executionReport) {
    for (size_t i = 0; i < sellOrders.size(); i++) {
        int buyPrice = order.getPrice();
        int sellPrice = sellOrders[0].getPrice();

        if (buyPrice < sellPrice) {// If the buy price is less than the sell price, add the order to buy side
            if(i > 0){// If the order is not new
                buyOrders.push_back(order);
                break;
            }
            addNewBuyOrder(order, executionReport);
            break;
        }else{ // If the buy price is higher than or equal to sell price, need to execute accordingly
            int sellQuantity = sellOrders[0].getQuantity();
            int buyQuantity = order.getQuantity();
            int difference = buyQuantity - sellQuantity;

            if (difference == 0) { // Both orders are fully filled
                fullyFillBuyOrder(order, sellPrice, executionReport);
                sellOrders.erase(sellOrders.begin());
                break;
            } else if (difference < 0) { // Sell order is partially filled
                partiallyFillSellOrder(order, sellPrice, executionReport);
                order.setPrice(buyPrice);
                sellOrders[0].setQuantity(sellQuantity - buyQuantity);
                break;
            } else { // Buy order is partially filled
                partiallyFillBuyOrder(order, sellPrice, executionReport);
                order.setPrice(buyPrice);
                sellOrders.erase(sellOrders.begin());
                order.setQuantity(difference);
            }
        }
    }
    // If the order is not fully filled, add it to buy side
    if (order.getExecStatus() == "PFill") {
        buyOrders.push_back(order);
    }
}

void OrderBook::processSellOrderWithBuyOrders(Order &order, ExecReport &execReport) {
    for (size_t i = 0; i < buyOrders.size(); i++) {
        int sellPrice = order.getPrice();
        int buyPrice = buyOrders[0].getPrice();

        if (sellPrice < buyPrice) { // If the sell price is less than the buy price, add the order to sell side
            if(i > 0){ // If the order is not new
                sellOrders.push_back(order);
                break;
            }
            addNewSellOrder(order, execReport);
            break;
        } else { // If the sell price is higher than or equal to buy price, need to execute accordingly
            int buyQuantity = buyOrders[0].getQuantity();
            int sellQuantity = order.getQuantity();
            int difference = sellQuantity - buyQuantity;

            if (difference == 0) { // Both orders are fully filled
                fullyFillSellOrder(order, buyPrice, execReport);
                buyOrders.erase(buyOrders.begin());
                break;
            } else if (difference < 0) { // Buy order is partially filled
                partiallyFillBuyOrder(order, buyPrice, execReport);
                order.setPrice(sellPrice);
                buyOrders[0].setQuantity(buyQuantity - sellQuantity);
                break;
            } else { // Sell order is partially filled
                partiallyFillSellOrder(order, buyPrice, execReport);
                order.setPrice(sellPrice);
                buyOrders.erase(buyOrders.begin());
                order.setQuantity(difference);
            }
        }
    }
    // If the order is not fully filled, add it to sell side
    if (order.getExecStatus() == "PFill") {
        sellOrders.push_back(order);
    }
}


void OrderBook::fullyFillBuyOrder(Order &order, int fillPrice, ExecReport &executionReport) {
    order.setExecStatus("Fill");
    order.setPrice(fillPrice);
    sellOrders[0].setExecStatus("Fill");
    order.setTransactionTime(getTimeStamp());
    sellOrders[0].setTransactionTime(getTimeStamp());
    executionReport.getExecutionReport().push_back(order);
    executionReport.getExecutionReport().push_back(sellOrders[0]);
}

void OrderBook::partiallyFillSellOrder(Order &order, int fillPrice, ExecReport &executionReport) {
    sellOrders[0].setExecStatus("PFill");
    order.setExecStatus("Fill");
    order.setPrice(fillPrice);
    sellOrders[0].setQuantity(order.getQuantity());
    sellOrders[0].setTransactionTime(getTimeStamp());
    order.setTransactionTime(getTimeStamp());
    executionReport.getExecutionReport().push_back(order);
    executionReport.getExecutionReport().push_back(sellOrders[0]);
}

void OrderBook::partiallyFillBuyOrder(Order &order, int fillPrice, ExecReport &executionReport) {
    sellOrders[0].setExecStatus("Fill");
    order.setExecStatus("PFill");
    order.setPrice(fillPrice);
    order.setQuantity(sellOrders[0].getQuantity());
    order.setTransactionTime(getTimeStamp());
    sellOrders[0].setTransactionTime(getTimeStamp());
    executionReport.getExecutionReport().push_back(order);
    executionReport.getExecutionReport().push_back(sellOrders[0]);
}

void OrderBook::sortSellOrdersAscending(std::vector<Order> &orders) {
    std::sort(orders.begin(), orders.end(), [](const Order &a, const Order &b) {
        return a.getPrice() < b.getPrice();
    });
}

void OrderBook::sortBuyOrdersDescending(std::vector<Order> &orders) {
    std::sort(orders.begin(), orders.end(), [](const Order &a, const Order &b) {
        return a.getPrice() > b.getPrice();
    });
}

string OrderBook::getTimeStamp() {
    // Get the current time and format it as needed
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string formattedTime = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    return formattedTime;
}





