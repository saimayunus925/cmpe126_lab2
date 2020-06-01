/*
 * lab_2_main.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: yunus
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Complex.h"
#include "ComplexDB.h"
using namespace std;

// TODO - find out how to do 'delete' function
// TODO - ask TA about '0-8i', '0-8.00001i' problem

int main() {
  ComplexDB db(8);
  Complex c1;
  int n;
  db.ImportComplexFile("126import.txt");
  db.LIST();
  cout << "Enter a complex number in a+bi format:" << endl;
  cout << "(no a+i or a-bi format)" << endl;
  cin >> c1;

  cout << "1. ADD the number to group of complex numbers." << endl;
  cout << "2. DELETE a number from group of complex numbers" << endl;
  cout << "3. LIST group of complex numbers." << endl;
  cout << "4. Add the number to group of complex numbers and SAVE results to 126complex.txt" << endl;
  cout << "5. EXIT" << endl;
  cin >> n;

  while(true) {
    if (n == 5) {
      break;
    }
    else if (n == 1) {
      db.ADD(c1);
    }
    else if (n == 2) {
      db.LIST();
      int x;
      cout << "Enter the number of the item you want to delete." << endl;
      cin >> x;
      db.DELETE(x);
    }
    else if (n == 3) {
      db.LIST();
    }
    else if (n == 4) {
      db.SAVE(c1);
    }
    else {
      cout << "INVALID INPUT - please try again." << endl;
    }
    cout << "Please select again from the menu if you'd like." << endl;
    cin >> n;
  }

}



