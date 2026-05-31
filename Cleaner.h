#ifndef CLEANER_H
#define CLEANER_H

#include <iostream>
#include "Space.h"
#include "Vacuum.h"

using namespace std;

class Cleaner {
public:
    void startCleaning(Vacuum& vacuum) {
        Space& space = Space::getInstance();
        char option;
        int row, column;

        do {
            cout << "Vacuum is in: ("
                 << vacuum.getRow() << ", "
                 << vacuum.getColumn() << ") \n";

            space.printGrid(vacuum.getRow(), vacuum.getColumn());

            space.cleanNeighbors(vacuum.getRow(), vacuum.getColumn());

            cout << "After the clean: \n";
            space.printGrid(vacuum.getRow(), vacuum.getColumn());

            if (!space.hasDirtyTiles()) {
                cout << "There are no dirty tiles. Clean finished.";
                break;
            }

            cout << "Whish you clean more tiles? (y/n): ";
            cin >> option;

            if (option == 'y' || option == 'Y') {
                do {
                    cout << "Enter the row: ";
                    cin >> row;

                    cout << "Enter the column: ";
                    cin >> column;

                    if (!space.isValidPosition(row, column)) {
                        cout << "Coordenates out of limits. Try again.\n";
                    }
                } while (!space.isValidPosition(row, column));
                cout << "Vacuum is in: ("
                    << vacuum.getRow() << ", "
                    << vacuum.getColumn() << ") \n";
                vacuum.setPosition(row, column);
            }

        } while (option == 'y' || option == 'Y');

        cout << "\nProcess finished.";
    }
};

#endif