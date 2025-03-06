/****************************************************************************
* @file calculator.cpp
 * @author Sarah Gäumann <sarah.gaeumann@edu.hefr.ch>
 *
 * @brief Calculator class
 *
 * @date 2025-03-05
 * @version 0.1.0
 ***************************************************************************/

#include <iostream>
#include "calculator.h"
using namespace std;



int Calculator::run(){
    // declare variables
    double operand;
    double& ref = operand; // reference on operand
    Operation operation;
    cout << "\n\n------------ Calculator ------------\n\n\n";
    cout << "Warning: operation entered must match exactly one of the operations available.\n\n";
    getFirstOperand();
    while(true){
        operation = bindToOperation();
        if (operation == Operation::EXIT) break;
        while(operation == Operation::UNKNOWN) {
            operation = bindToOperation();
        }
        ref = getOperand();
        operate(operation,ref);
    }
    cout << "Exiting program...";
    return 0;
}
