#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include "Utilities.h"

using namespace std;

class Space {
    private:
        int rowLimit, columnLimit;
        vector<vector<int>> grid;

        Space() : rowLimit(0), columnLimit(0) {
            srand(time(0));
        }

    public:
        Space(const Space&) = delete;
        Space& operator = (const Space&) = delete;

        static Space& getInstance() {
            static Space instance;
            return instance;
        }
        
        bool isValidPosition(int targetRow, int targetColumn) {
            return (targetRow >= 0 && targetRow < rowLimit) && (targetColumn >= 0 && targetColumn < columnLimit);
        }

        void generateGridAndFill(int rows, int columns) {
            QueueSpaceChanges& spaceChanges = QueueSpaceChanges::getInstance();
            rowLimit = rows;
            columnLimit = columns;
            grid.assign(rows, vector<int>(columns,0));

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    grid[i][j] = rand() % 2;
                }
            }
            spaceChanges.addCurrentSpace(grid);
        }

        bool isDirty(int row, int column) {
            return grid[row][column] == 1;
        }

        void cleanTile(int row, int column) {
            QueueSpaceChanges& spaceChanges = QueueSpaceChanges::getInstance();
            grid[row][column] = 0;
            spaceChanges.addCurrentSpace(grid);
        }

        bool hasDirtyTiles() {
            for(int i = 0; i < rowLimit; i++) {
                for(int j = 0; j < columnLimit; j++) {
                    if(grid[i][j] == 1) {
                        return true;
                    }
                }
            }
            return false;
        }

        void cleanNeighbors(int vacuumRow, int vacuumColumn) {
            for (int i = vacuumRow - 1; i <= vacuumRow + 1; i++) {
                for (int j = vacuumColumn - 1; j <= vacuumColumn + 1; j++) {

                    if (i == vacuumRow && j == vacuumColumn) {
                        continue;
                    }

                    if (isValidPosition(i, j) && isDirty(i, j)) {
                        cleanTile(i, j);
                    }
                }
            }
        }

        void printGrid(int vacuumRow, int vacuumColumn) {
            cout << "\nGrid: \n";

            for (int i = 0; i < rowLimit; i++) {
                for (int j = 0; j < columnLimit; j++) {
                    if (i == vacuumRow && j == vacuumColumn) {
                        cout << "A ";
                    } else {
                        cout << grid[i][j] << " ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

};

#endif