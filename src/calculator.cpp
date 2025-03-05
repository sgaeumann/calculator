/****************************************************************************
* @file calculator.cpp
 * @author Sarah Gäumann <sarah.gaeumann@edu.hefr.ch>
 *
 * @brief Calculator class
 *
 * @date 2025-03-05
 * @version 0.1.0
 ***************************************************************************/

#include <stdio.h>
#include "calculator.h"



int Calculator::run(){
    char operation;
    double operand;
    printf("\n\n------------ Calculator ------------\n\n\n");
    getFirstOperand();
    while(true){
        operation = getOperation();
        Operation op = bindToOperation(operation);
        operand = getOperand();
        operate(op,operand);
    }
    return 0;
} // end run()
