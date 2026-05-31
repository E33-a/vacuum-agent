#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstdlib>
#include <queue>
#include <vector>
#include "Space.h"

using namespace std;

inline static void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

class QueueSpaceChanges {
    private:
        int vectorsPerBlock = 8;
        int row, column;
        queue<vector<vector<int>>> changesInSpace;
        vector<vector<vector<int>>> blocks;

        QueueSpaceChanges(int row = 5, int column = 5) : row(row), column(column) {}

    public:
        QueueSpaceChanges(const QueueSpaceChanges&) = delete;
        QueueSpaceChanges& operator = (const QueueSpaceChanges&) = delete;

        static QueueSpaceChanges& getInstance() {
            static QueueSpaceChanges instance;
            return instance;
        }
        
        void setDimensions(int rowDimension, int columnDimension) {
            row = rowDimension;
            column = columnDimension;
        }

        void addCurrentSpace(vector<vector<int>> current) {
            changesInSpace.push(current);
        }

        void printBlocksOfFour() {
            queue<vector<vector<int>>> copy = changesInSpace; 
            cout << "\nShowing a total of " << copy.size() << " space changes\n\n";
            
            while(!copy.empty()) {
                blocks.clear();
                while(blocks.size() < vectorsPerBlock && !copy.empty()) {
                    blocks.push_back(copy.front());
                    copy.pop();
                }

                for(int i = 0; i < row; i++) {
                    for(size_t m = 0; m < blocks.size(); m++){
                        for(int j = 0; j < column; j++) {
                            cout << blocks[m][i][j] << " ";
                        }
                        if(m < blocks.size() -1) {
                            cout << "   ";
                        }
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
        }

        ~QueueSpaceChanges() {};

};

#endif
