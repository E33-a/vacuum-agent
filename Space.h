#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <cstdlib>
#include <ctime>

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
            rowLimit = rows;
            columnLimit = columns;
            grid.assign(rows, vector<int>(columns,0));

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    grid[i][j] = rand() % 2;
                }
            }
        }

        bool isDirty(int row, int column) {
            return grid[row][column] == 1;
        }

        void cleanTile(int row, int column) {
            grid[row][column] = 0;
        }
};

#endif