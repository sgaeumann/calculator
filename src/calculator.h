/****************************************************************************
* @file calculator.hpp
 * @author Sarah Gäumann <sarah.gaeumann@edu.hefr.ch>
 *
 * @brief Calculator class header
 *
 * @date 2025-03-05
 * @version 0.1.0
 ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

enum class Operation : char {
  ADD=(int)'+',SUB=(int)'-',MULT=(int)'*',DIV=(int)'/',EXIT=(int)'#',UNKNOWN
};

class Calculator{
  private:
    double operand = 1.0; // default value
  public:
    ~Calculator();
    int run();

    void add(const double x){
      operand = operand+x;
      printf("%f\n",operand);
    }

    void subtract(const double x){
      operand = operand-x;
      printf("%f\n",operand);
    }

    void multiply(const double x){
      operand = operand*x;
      printf("%f\n",operand);
    }

    void divide(const double x){
      if(x==0) {
        printf("Error: division by 0! Skipped\n");
        return;
      }
      operand = operand / x;
      printf("%f\n",operand);
    }

    void getFirstOperand() {
        double op;
        printf("Enter the first operand: ");
        scanf("%lf",&op);
        getchar(); // remove newline
        operand = op;
      }

    /**
     *
     * @return char corresponding to operation
     */
    char getOperation() {
      char operation;
      printf("Enter the operation:\n");
      printf("+ \t- \t* \t/ \t# to exit\n");
      scanf("%c",&operation);
      getchar(); // remove newline
      return operation;
    }

    /**
     * gets the user's input and binds it to operand
     * @return operand
     */
    double getOperand() {
      double operand;
      printf("Enter the operand: ");
      scanf("%lf",&operand);
      getchar(); // remove newline
      return operand;
    }

    /**
     * binds user's input to an operation
     * @param c input from user
     * @return corresponding operation
     */
    Operation bindToOperation(char c) {
      switch(c) {
        case('+'):
          return Operation::ADD;
        case('-'):
          return Operation::SUB;
        case('*'):
          return Operation::MULT;
        case('/'):
          return Operation::DIV;
        case('#'):
          printf("Exiting program...");
          exit(0);
        default:
          printf("Unknown operator.\n");
          return Operation::UNKNOWN;
      }
      return Operation::UNKNOWN;
    }

    /**
     * calls the corresponding operation with the operand
     * @param op operation to make
     * @param operand
     */
    void operate(Operation op, double operand) {
      switch(op) {
        case(Operation::ADD):
          add(operand);
          break;
        case(Operation::SUB):
          subtract(operand);
          break;
        case(Operation::MULT):
          multiply(operand);
          break;
        case(Operation::DIV):
          divide(operand);
          break;
        case(Operation::EXIT):
        case(Operation::UNKNOWN):
          return;
        default:
          return;
      }
    }
};

#endif //CALCULATOR_H
