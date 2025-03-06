/****************************************************************************
* @file calculator.h
 * @author Sarah Gäumann <sarah.gaeumann@edu.hefr.ch>
 *
 * @brief Calculator class header
 *
 * @date 2025-03-05
 * @version 0.1.0
 ***************************************************************************/
#pragma once


#include <iostream>
#include <limits>
using namespace std;

enum class Operation : char {
  ADD='+',SUB='-',MULT='*',DIV='/',EXIT='#',UNKNOWN
};

class Calculator{
  private:
    double operand = 1.0; // default value
  public:
    ~Calculator() = default;
    int run();

    void add(const double x){
      operand = operand+x;
      cout << "Result: " << operand << endl;
    }

    void subtract(const double x){
      operand = operand-x;
      cout << "Result: " << operand << endl;
    }

    void multiply(const double x){
      operand = operand*x;
      cout << "Result: " << operand << endl;
    }

    void divide(const double x){
      if(x==0) {
        cout << "Error: division by 0! Skipped" << endl;
        return;
      }
      operand = operand / x;
      cout << "Result: " << operand << endl;
    }

    void getFirstOperand() {
        double op;
        printf("Enter the first operand: ");
        while(1) {
          if(cin >> op) break; // valid number
          // else not a valid number
          cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input. Please enter a numerical value: ";
        }
        operand = op;
      }

    /**
     *
     * @return char corresponding to operation
     */
    static char getOperation() {
      char operation;
      cout <<"Enter the operation:" << endl;
      cout <<"+ \t- \t* \t/ \t# to exit" << endl;
      cin >> operation;
      return operation;
    }

    /**
     * gets the user's input and binds it to operand
     * @return operand
     */
    static double getOperand() {
      double operand;
      cout << "Enter the operand: ";
      while (!(cin >> operand)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a numerical value: ";
      }
      return operand;
    }

    /**
     * binds user's input to an Operation
     * @return corresponding operation
     * @see enum class Operation
     */
    static Operation bindToOperation() {
      char c = getOperation();
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
          return Operation::EXIT;
        default:
          cout << "Unknown operator. Please enter a valid one." << endl;
          return Operation::UNKNOWN;
      }
    }

    /**
     * calls the corresponding operation with the operand
     * @param op operation to make
     * @param operand
     */
    void operate(const Operation op, const double operand) {
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
        default:
          return;
      }
    }
};
