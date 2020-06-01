/*
 * ComplexDB.h
 *
 *  Created on: Sep 30, 2019
 *      Author: yunus
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Complex.h"
using namespace std;

#ifndef COMPLEXDB_H_
#define COMPLEXDB_H_

class ComplexDB {
public:
  ComplexDB(int size);
  ~ComplexDB();
  void ImportComplexFile(string fname);
  void ADD(Complex &c);
  void DELETE(int index);
  void LIST();
  void SAVE(Complex &c);
private:
  int maxLength;
  Complex *nums;
};

#endif /* COMPLEXDB_H_ */

