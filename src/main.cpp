/****************************************************************************
* @file main.cpp
 * @author Sarah Gäumann <sarah.gaeumann@edu.hefr.ch>
 *
 * @brief Main program to launch calculator
 *
 * @date 2025-03-05
 * @version 0.1.0
 ***************************************************************************/

#include <stdio.h>
#include "calculator.h"

int main(){
  printf("starting calculator program...");
  Calculator *cl = new Calculator();
  cl->run();
  return 0;
}