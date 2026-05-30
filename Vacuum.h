#ifndef VACUUM_H
#define VACUUM_H

struct Coordinate {
    int row;
    int column;
};

class Vacuum{
    private:
        Coordinate currentPosition;

    public:
        Vacuum(int startRow, int startColumn) {
            currentPosition.row = startRow;
            currentPosition.column = startColumn;
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
};

#endif