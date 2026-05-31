#include <iostream>
#include "Space.h"
#include "Validator.h"
#include "Cleaner.h"

using namespace std;

int main() {
    clearScreen();
    cout << "Vacuum Agent\n\n";
    Validator validator;
    validator.getData();
    int rows = validator.getRowIndex();
    int columns = validator.getColumnIndex();
    
    QueueSpaceChanges& QueueSpaceChanges = QueueSpaceChanges::getInstance();
    QueueSpaceChanges.setDimensions(rows, columns);                                                                                              

    Space& space = Space::getInstance();
    space.generateGridAndFill(rows, columns);

    Vacuum kwiddo(rows, columns);

    Cleaner cleaner;
    cleaner.startCleaning(kwiddo);

    clearScreen();
    QueueSpaceChanges.printBlocksOfFour();

    cout << "\nPress ENTER to exit program...";
    cin.clear();
    cin.ignore(10000, '\n');
    cin.get();
}