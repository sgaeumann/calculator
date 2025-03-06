/****************************************************************************
* @file main.cpp
 * @author Sarah Gäumann <sarah.gaeumann@edu.hefr.ch>
 *
 * @brief Main program to launch calculator
 *
 * @date 2025-03-05
 * @version 0.1.0
 ***************************************************************************/

#include <iostream>
#include "calculator.h"
using namespace std;

int main(){
  cout << "starting calculator program..." << endl;
  Calculator *cl = new Calculator();
  cl->run(); delete cl;
  return 0;
}