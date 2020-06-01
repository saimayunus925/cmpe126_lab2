/*
 * ComplexDB.cpp
 *
 *  Created on: Sep 30, 2019
 *      Author: yunus
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Complex.h"
#include "ComplexDB.h"
using namespace std;

ComplexDB::ComplexDB(int size) {
  maxLength = size;
  nums = new Complex [maxLength];
}

ComplexDB::~ComplexDB() {
  delete [] nums;
}

void ComplexDB::ImportComplexFile(string fname) {
    // works for forms of a+bi, a, bi
    int j = 0;
    ifstream fin;
    fin.open(fname.c_str());

    double real,im;
    char plusorminus,ichar;
    Complex c;
    string oneline;
    while (!fin.eof() && j < maxLength){
        getline(fin, oneline);
        real=0;
        im=0;
        plusorminus='\0';
        ichar='\0';
        stringstream(oneline) >> real >> plusorminus >> im >> ichar;
        switch (plusorminus) {
        case '-':
          im=-im;
          break;
        case 'i':
          im=real;
          real=0;
          break;
        case '\0':
          im=0;
          break;
        }
        c.set_complex(real, im);
        // cout << c << endl;
        // I added this so it would fill the array
        // only problem - probably need to use similar logic to add a # to the array
        nums[j] = c;
        ++j;
    }
    fin.close();
}

void ComplexDB::ADD(Complex &c) {
  if (maxLength == 0)
    nums[0] = c;
  int index;
  if (maxLength > 0) {
    for (index = 0; index < maxLength; index++) {
      if (nums[index].find_value() > c.find_value())
        break;
    }
    for (int i = maxLength; i >= index; i--) {
      nums[i] = nums[i-1];
    }
    nums[index] = c;
  }
  maxLength++;
}
void ComplexDB::DELETE(int index) {
  if (maxLength == 0)
    return;
  for (int i = index; i <= maxLength; i++) {
    nums[i] = nums[i+1];
  }
  Complex EMPTY;
  nums[maxLength-1] = EMPTY;
  maxLength--;
}
void ComplexDB::LIST() {
  // simple for now so we can check that things are adding and deleting correctly
  // will add a sorting algorithm or something later to sort nums in ascending order
  for (int i = 0; i < maxLength; i++)
    cout << i << ". "  << nums[i] << endl;
}
void ComplexDB::SAVE(Complex &c) {
  ofstream fout;
  fout.open("126complex.txt");
  if (fout.fail()) {
    cout << "Output file failed to open." << endl;
    exit(1);
  }
  ADD(c);
  for (int i = 0; i < maxLength; i++)
      fout << nums[i] << endl;
  fout.close();
}
