//
// Created by ASUS on 12/13/2023.
//

#include <iostream>
#include <algorithm>
#include "OrderBook.h"

using namespace std;

OrderBook::OrderBook(string &type) {
    type = type;
}

void OrderBook::processOrder(Order order, ExecReport &executionReport) {
    int side = order.getSide();

    if (side == 1) { // Buy order
        processBuyOrder(order, executionReport);
    } else { // Sell order
        //processSellOrder(order, executionReport);
        if (buyOrders.empty()) {    // If there are no buy orders, add the order directly to sell side as a new order
            order.setExecStatus("New");
            sellOrders.push_back(order);
            order.setTransactionTime(getTimeStamp());
            executionReport.getExecReport().push_back(order);
        } else {
            int buyOrderSize = buyOrders.size();
            for (size_t i = 0; i < buyOrderSize; i++) {
                int sellPrice = order.getPrice();
                int buyPrice = buyOrders[0].getPrice();
                if (sellPrice > buyPrice) { // If the sell price is greater than the buy price, add the order to sell side
                    if (i > 0) {    // If the order is not a new one
                        sellOrders.push_back(order);
                        break;
                    }
                    // If the order is a new one
                    addNewSellOrder(order, executionReport);
                    break;
                } else {
                    int buyQuantity = buyOrders[0].getQuantity();
                    int sellQuantity = order.getQuantity();
                    int difference = sellQuantity - buyQuantity;
                    if (difference == 0) { // Both orders are fully filled
                        fullyFillSellOrder(order, buyPrice, executionReport);
                        order.setPrice(sellPrice);
                        buyOrders.erase(buyOrders.begin());
                        break;
                    } else if (difference < 0) {    // The buy order is partially filled
                        partiallyFillBuyOrderSellSide(order, buyPrice, executionReport);
                        order.setPrice(sellPrice);
                        buyOrders[0].setQuantity(buyQuantity - sellQuantity);
                        break;
                    } else {    // The sell order is partially filled
                        partiallyFillSellOrderSellSide(order, buyPrice, executionReport);
                        order.setPrice(sellPrice);
                        buyOrders.erase(buyOrders.begin());
                        order.setQuantity(difference);
                    }
                }
            }

            // After iterating through all the buy orders, if the order is still partially filled, add it to sell side
            if (order.getExecStatus() == "PFill") {
                sellOrders.push_back(order);
            }
        }
        sortSellOrdersAscending(sellOrders);
    }
}


void OrderBook::processBuyOrder(Order &order, ExecReport &executionReport) {
    if (sellOrders.empty()) {
        addNewBuyOrder(order, executionReport);
    } else {
        processBuyOrderWithSellOrders(order, executionReport);
    }
    sortBuyOrdersDescending(buyOrders);
}

//void OrderBook::processSellOrder(Order &order, ExecReport &executionReport) {
//    if (buyOrders.empty()) {
//        addNewSellOrder(order, executionReport);
//    } else {
//        processSellOrderWithBuyOrders(order, executionReport);
//    }
//    sortSellOrdersAscending(sellOrders);
//}

void OrderBook::addNewBuyOrder(Order &order, ExecReport &executionReport) {
    order.setExecStatus("New");
    buyOrders.push_back(order);
    order.setTransactionTime(getTimeStamp());
    executionReport.getExecReport().push_back(order);
}

void OrderBook::addNewSellOrder(Order &order, ExecReport &execReport) {
    order.setExecStatus("New");
    sellOrders.push_back(order);
    order.setTransactionTime(getTimeStamp());
    execReport.getExecReport().push_back(order);
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
                order.setPrice(buyPrice);
                sellOrders.erase(sellOrders.begin());
                break;
            } else if (difference < 0) { // Sell order is partially filled
                partiallyFillSellOrderBuySide(order, sellPrice, executionReport);
                order.setPrice(buyPrice);
                sellOrders[0].setQuantity(sellQuantity - buyQuantity);
                break;
            } else { // Buy order is partially filled
                partiallyFillBuyOrderBuySide(order, sellPrice, executionReport);
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

//void OrderBook::processSellOrderWithBuyOrders(Order &order, ExecReport &execReport) {
//    for (size_t i = 0; i < buyOrders.size(); i++) {
//        int sellPrice = order.getPrice();
//        int buyPrice = buyOrders[0].getPrice();
//
//        if (sellPrice > buyPrice) { // If the sell price is greater than the buy price, add the order to sell side
//            if(i > 0){ // If the order is not new
//                sellOrders.push_back(order);
//                break;
//            }
//            addNewSellOrder(order, execReport);
//            break;
//        } else { // If the sell price is higher than or equal to buy price, need to execute accordingly
//            int buyQuantity = buyOrders[0].getQuantity();
//            int sellQuantity = order.getQuantity();
//            int difference = sellQuantity - buyQuantity;
//
//            if (difference == 0) { // Both orders are fully filled
//                fullyFillSellOrder(order, buyPrice, execReport);
//                order.setPrice(sellPrice);
//                buyOrders.erase(buyOrders.begin());
//                break;
//            } else if (difference < 0) { // Buy order is partially filled
//                partiallyFillBuyOrderSellSide(order, buyPrice, execReport);
//                order.setPrice(sellPrice);
//                buyOrders[0].setQuantity(buyQuantity - sellQuantity);
//                break;
//            } else { // Sell order is partially filled
//                partiallyFillSellOrderSellSide(order, buyPrice, execReport);
//                order.setPrice(sellPrice);
//                buyOrders.erase(buyOrders.begin());
//                order.setQuantity(difference);
//            }
//        }
//    }
//    // If the order is not fully filled, add it to sell side
//    if (order.getExecStatus() == "PFill") {
//        sellOrders.push_back(order);
//    }
//}


void OrderBook::fullyFillBuyOrder(Order &order, int fillPrice, ExecReport &executionReport) {
    order.setExecStatus("Fill");
    order.setPrice(fillPrice);
    sellOrders[0].setExecStatus("Fill");
    order.setTransactionTime(getTimeStamp());
    sellOrders[0].setTransactionTime(getTimeStamp());
    executionReport.getExecReport().push_back(order);
    executionReport.getExecReport().push_back(sellOrders[0]);
}

void OrderBook::fullyFillSellOrder(Order &order, int fillPrice, ExecReport &executionReport) {
    order.setExecStatus("Fill");
    order.setPrice(fillPrice);
    buyOrders[0].setExecStatus("Fill");
    order.setTransactionTime(getTimeStamp());
    buyOrders[0].setTransactionTime(getTimeStamp());
    executionReport.getExecReport().push_back(order);
    executionReport.getExecReport().push_back(buyOrders[0]);
}

void OrderBook::partiallyFillSellOrderBuySide(Order &order, int fillPrice, ExecReport &executionReport) {
    sellOrders[0].setExecStatus("PFill");
    order.setExecStatus("Fill");
    order.setPrice(fillPrice);
    sellOrders[0].setQuantity(order.getQuantity());
    sellOrders[0].setTransactionTime(getTimeStamp());
    order.setTransactionTime(getTimeStamp());
    executionReport.getExecReport().push_back(order);
    executionReport.getExecReport().push_back(sellOrders[0]);
}

void OrderBook::partiallyFillBuyOrderBuySide(Order &order, int fillPrice, ExecReport &executionReport) {
    sellOrders[0].setExecStatus("Fill");
    order.setExecStatus("PFill");
    order.setPrice(fillPrice);
    order.setQuantity(sellOrders[0].getQuantity());
    order.setTransactionTime(getTimeStamp());
    sellOrders[0].setTransactionTime(getTimeStamp());
    executionReport.getExecReport().push_back(order);
    executionReport.getExecReport().push_back(sellOrders[0]);
}

void OrderBook::partiallyFillSellOrderSellSide(Order &order, int fillPrice, ExecReport &execReport) {
    buyOrders[0].setExecStatus("Fill");
    order.setExecStatus("PFill");
    order.setPrice(fillPrice);
    order.setQuantity(buyOrders[0].getQuantity());
    order.setTransactionTime(getTimeStamp());
    buyOrders[0].setTransactionTime(getTimeStamp());
    execReport.getExecReport().push_back(order);
    execReport.getExecReport().push_back(buyOrders[0]);
}

void OrderBook::partiallyFillBuyOrderSellSide(Order &order, int fillPrice, ExecReport &execReport) {
    buyOrders[0].setExecStatus("PFill");
    order.setExecStatus("Fill");
    order.setPrice(fillPrice);
    buyOrders[0].setQuantity(order.getQuantity());
    buyOrders[0].setTransactionTime(getTimeStamp());
    order.setTransactionTime(getTimeStamp());
    execReport.getExecReport().push_back(order);
    execReport.getExecReport().push_back(buyOrders[0]);
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






