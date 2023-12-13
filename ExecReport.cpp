//
// Created by ASUS on 12/13/2023.
//

#include "ExecReport.h"

#include <utility>

ExecReport::ExecReport(std::string  executionID, std::string  clientOrderID, std::string  symbol,
                       int quantity, double price, int side, int status, std::string  reason, std::string  transactionTime)
        : executionID(std::move(executionID)), clientOrderID(std::move(clientOrderID)), symbol(std::move(symbol)), quantity(quantity),
          price(price), side(side), status(status), reason(std::move(reason)), transactionTime(std::move(transactionTime)) {}
