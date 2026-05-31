#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include "Utilities.h"

using namespace std;

class Validator {
    private:
        int rowIndex, columnIndex;
    public:
        Validator() : rowIndex(0), columnIndex(0) {}

        int getRowIndex() {
            return rowIndex;
        }

        int getColumnIndex() {
            return columnIndex;
        }

        void getData() {
            do {
                cout << "Enter the rows (5 or more):    ";
                cin >> rowIndex;
                if (rowIndex < 5) {
                    cout << "Invalid value. Try again.\n";
                }
            } while (rowIndex < 5);

            do {
                cout << "Enter the columns (5 or more):     ";
                cin >> columnIndex;
                if (columnIndex < 5) {
                    cout << "Invalid value. Try again.\n";
                }
            } while (columnIndex < 5);
            clearScreen();
        }

        ~Validator(){}
};

#endif                                                 
