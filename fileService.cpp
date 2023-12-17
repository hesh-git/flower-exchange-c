// fileService.cpp
#include "FileService.h"
#include <fstream>
#include <sstream>
#include "ExecReport.h"

vector<Order> FileService::readAndProcessOrders(const std::string &filename){
    vector<Order> ordersVector;
    ifstream file(filename);
    if (file.is_open()){
        string line;

        // Read header and skip it
        getline(file, line);

        // Read data and process it
        while (getline(file, line)){
            // define a Order object for each line
            Order order;
            // define a string stream object for each line
            stringstream ss(line);

            string clientOrderID;
            string instrument;
            int side = -1;
            double price = 0.0;
            int quantity = -1;

            string sideRej;
            string priceRej;
            string quantityRej;

            // Read data from each line and assign it to the Order object
            getline(ss, clientOrderID, ',');
            getline(ss, instrument, ',');
            getline(ss, sideRej, ',');
            getline(ss,quantityRej, ',');
            getline(ss, priceRej, ',');

            if(!sideRej.empty()){
                side = stoi(sideRej);
            }
            if(!priceRej.empty()){
                price = stod(priceRej);
            }
            if(!quantityRej.empty()){
                quantity = stoi(quantityRej);
            }

            //Set the Order object attributes
            order.setClientOrderId(clientOrderID);
            order.setInstrument(instrument);
            order.setSide(side);
            order.setPrice(price);
            order.setQuantity(quantity);

            order.setSideRej(sideRej);
            order.setPriceRej(priceRej);
            order.setQuantityRej(quantityRej);


            // Add the Order object to the vector
            ordersVector.push_back(order);
        }

        // Close the file
        file.close();

    }
    // Return the vector
    return ordersVector;
}

void FileService::writeExecutionReportToFile(const string &fileName, const vector<Order> &orders){
    ofstream file(fileName);
    cout << "6. Writing to file: " << fileName << endl;
    if (file.is_open()){
        // Write header
        file << "ClientOrderId, OrderID, Instrument, Side, Price, Quantity, ExecStatus, Reason, TransactionTime" << endl;

        // Write data
        for (const auto &order : orders){
            file
            << order.getClientOrderId() << ","
            << order.getOrderId() << ","
            << order.getInstrument() << ","
            << ((order.getExecStatus() == "Reject") ? order.getSideRej() : to_string(order.getSide())) << ","
            << ((order.getExecStatus() == "Reject") ? order.getPriceRej() : to_string(order.getPrice())) << ","
            << ((order.getExecStatus() == "Reject") ? order.getQuantityRej() : to_string(order.getQuantity())) << ","
            << order.getExecStatus() << ","
            << order.getReason() << ","
            << order.getTransactionTime() << ","
            << endl;
        }

        // Close the file
        file.close();
    }
}
