#ifndef VACUUM_H
#define VACUUM_H

#include <iostream>
#include <cctype>
#include "Space.h"

struct Coordinate {
    int row;
    int column;
};

class Vacuum{
    private:
        Coordinate currentPosition;

    public:
        Vacuum(int row, int column) {
            Space& space = Space::getInstance();
            char response;
            cout << "\nDo you want to set the initial position? (y/n): ";
            cin >> response;
            response = tolower(response);
            switch(response) {
                case 'y':
                    do {
                        cout << "\nPosition from (0, 0) to (" << row -1 << ", " << column - 1 << ")\n";
                        cout << "\nEnter the row: ";
                        cin >> currentPosition.row;
                        cout << "\nEnter the column: ";
                        cin >> currentPosition.column;
                        if (!space.isValidPosition(currentPosition.row, currentPosition.column)) {
                            cout << "Coordenates out of limits. Try again.\n";
                        }
                    } while (!space.isValidPosition(currentPosition.row, currentPosition.column));
                    break;
                case 'n':
                    cout << "Random position selected.\n";
                    currentPosition.row = rand() % row;
                    currentPosition.column = rand() % column;
                    break;
                default:
                    cout << "Invalid option. Try again.\n";
                    break;
            }
        }

        void moveToRight() {
            currentPosition.column += 1;
        }

        void moveToLeft() {
            currentPosition.column -= 1;
        }

        void moveToUp() {
            currentPosition.row -= 1;
        }

        void moveToDown() {
            currentPosition.row += 1;
        }
        
        void moveToDiagonalSupRight() {
            currentPosition.row -= 1;
            currentPosition.column += 1;
        }

        void moveToDiagonalSupLeft() {
            currentPosition.row -= 1;
            currentPosition.column -= 1;
        }

        void moveToDiagonalInfRight() {
            currentPosition.row += 1;
            currentPosition.column += 1;
        }

        void moveToDiagonalInfLeft() {
            currentPosition.row += 1;
            currentPosition.column -= 1;
        }

        int getRow() {
            return currentPosition.row;
        }

        int getColumn() {
            return currentPosition.column;
        }

        void setPosition(int row, int column) {
            currentPosition.row = row;
            currentPosition.column = column;
        }

        ~Vacuum() {}
};

#endif