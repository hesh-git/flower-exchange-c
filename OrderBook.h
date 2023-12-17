//
// Created by ASUS on 12/13/2023.
//

#ifndef PROJECT_ORDERBOOK_H
#define PROJECT_ORDERBOOK_H


#include <vector>
#include "Order.h"
#include "ExecReport.h"

class OrderBook {
private:
    std::string type;
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;
    std::vector<ExecReport> executionReports;

public:
    OrderBook(std::string &type);
    void processOrder(Order order, ExecReport &execReport);
    void processBuyOrder(Order &order, ExecReport &execReport);
    void processBuyOrderWithSellOrders(Order &order, ExecReport &execReport);
    void addNewBuyOrder(Order &order, ExecReport &execReport);
    void fullyFillBuyOrder(Order &order, int sellPrice, ExecReport &execReport);
    void partiallyFillBuyOrderBuySide(Order &order, int fillPrice, ExecReport &execReport);
    void partiallyFillBuyOrderSellSide(Order &order, int fillPrice, ExecReport &execReport);
    void processSellOrder(Order &order, ExecReport &execReport);
    void processSellOrderWithBuyOrders(Order &order, ExecReport &execReport);
    void addNewSellOrder(Order &order, ExecReport &execReport);
    void fullyFillSellOrder(Order &order, int buyPrice, ExecReport &execReport);
    void partiallyFillSellOrderBuySide(Order &order, int fillPrice, ExecReport &execReport);
    void partiallyFillSellOrderSellSide(Order &order, int fillPrice, ExecReport &execReport);
    static void sortBuyOrdersDescending(std::vector<Order> &orders);
    static void sortSellOrdersAscending(std::vector<Order> &orders);
    string getTimeStamp();
};


#endif //PROJECT_ORDERBOOK_H
