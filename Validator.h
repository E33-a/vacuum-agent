#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "Utilities.h"
#include <iostream>

using namespace std;

class Validator {
private:
  int rowIndex, columnIndex;

public:
  Validator() : rowIndex(0), columnIndex(0) {}

  int getRowIndex() { return rowIndex; }

  int getColumnIndex() { return columnIndex; }

  void getData() {
    do {
      cout << "Enter the rows (5 or more):    ";
      cin >> rowIndex;
      if (rowIndex < 5 || rowIndex > 100) {
        cout << "Invalid value. Try again.\n";
        if (rowIndex > 100)
          cout << "Please enter fewer rows; very large values may use a lot "
                  "of memory.\n\n";
      }
    } while (rowIndex < 5 || rowIndex > 100);

    do {
      cout << "Enter the columns (5 or more):     ";
      cin >> columnIndex;
      if (columnIndex < 5 || columnIndex > 100) {
        cout << "Invalid value. Try again.\n\n";
        if (columnIndex > 100)
          cout << "Please enter fewer columns; very large values may use a "
                  "lot of memory.\n";
      }
    } while (columnIndex < 5 || columnIndex > 100);
    clearScreen();
  }

  ~Validator() {}
};

#endif
