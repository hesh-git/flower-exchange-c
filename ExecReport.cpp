//
// Created by ASUS on 12/13/2023.
//

#include "ExecReport.h"


void ExecReport::setExecReport(vector<Order> &execReport) {
    ExecReport::execReport = execReport;
}

vector<Order> &ExecReport::getExecReport() {
    return execReport;
}
