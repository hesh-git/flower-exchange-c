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
            string side;
            string price;
            string quantity;

            // Read data from each line and assign it to the Order object
            getline(ss, clientOrderID, ',');
            getline(ss, instrument, ',');
            getline(ss, side, ',');
            getline(ss,quantity, ',');
            getline(ss, price, ',');

            //Set the Order object attributes
            order.setClientOrderId(clientOrderID);
            order.setInstrument(instrument);

            if (side.empty()){
                order.setSide(-1);
            }
            else{
                order.setSide(stoi(side));
            }

            if (price.empty()){
                order.setPrice(-1);
            }
            else{
                order.setPrice(stod(price));
            }

            if (quantity.empty()){
                order.setQuantity(-1);
            }
            else {
                order.setQuantity(stoi(quantity));
            }

            // Add the Order object to the vector
            ordersVector.push_back(order);
        }

        // Close the file
        file.close();

        // Return the vector
        return ordersVector;
    }
}

void FileService::writeExecutionReportToFile(const string &fileName, const vector<Order> &orders){
    ofstream file(fileName);
    cout << "Writing to file: " << fileName << endl;
    if (file.is_open()){
        // Write header
        file << "ClientOrderId, OrderID, Instrument, Side, Price, Quantity, ExecStatus, Reason, TransactionTime" << endl;

        // Write data
        for (const auto &order : orders){
            file
            << order.getClientOrderId() << ","
            << order.getOrderId() << ","
            << order.getInstrument() << ","
            << order.getSide() << ","
            << order.getPrice() << ","
            << order.getQuantity() << ","
            << order.getExecStatus() << ","
            << order.getReason() << ","
            << order.getTransactionTime() << ","
            << endl;
        }

        // Close the file
        file.close();
    }
}
