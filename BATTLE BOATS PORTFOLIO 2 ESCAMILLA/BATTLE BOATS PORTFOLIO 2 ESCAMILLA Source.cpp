#include <iostream>
#include "BATTLE BOATS PORTFOLIO 2 ESCAMILLA Header.h"
using namespace std;


BattleBoatsGrid::BattleBoatsGrid() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            rowValues[i][j] = "_";
        }
    }
}

std::string BattleBoatsGrid::generateRow(std::string letter, int index) {
    return letter + "\t" + rowValues[index][0] + " " + rowValues[index][1] + " " + rowValues[index][2] + " " + rowValues[index][3] + "\n";
}

std::string BattleBoatsGrid::generateHeader() {
    return "\t1 2 3 4\n";
}

void BattleBoatsGrid::addBoat(std::string coordinate) {
    int rowValue;
    if (coordinate.at(0) == 'A') rowValue = 0;
    else if (coordinate.at(0) == 'B') rowValue = 1;
    else if (coordinate.at(0) == 'C') rowValue = 2;
    else if (coordinate.at(0) == 'D') rowValue = 3;

    int columnValue = coordinate.at(1) - '0' - 1;
    rowValues[rowValue][columnValue] = "@";
}

void BattleBoatsGrid::fireShot(std::string coordinate) {
    int rowValue;
    if (coordinate.at(0) == 'A') rowValue = 0;
    else if (coordinate.at(0) == 'B') rowValue = 1;
    else if (coordinate.at(0) == 'C') rowValue = 2;
    else if (coordinate.at(0) == 'D') rowValue = 3;

    int columnValue = coordinate.at(1) - '0' - 1;
    rowValues[rowValue][columnValue] = "X";
}

std::string BattleBoatsGrid::display() {
    std::stringstream ss;
    ss << generateHeader()
        << generateRow("A", 0)
        << generateRow("B", 1)
        << generateRow("C", 2)
        << generateRow("D", 3);
    return ss.str();
}


string getValidCoordinate() { // Validation
    string coordinate;
    bool valid = false;

    while (!valid) {
        cout << "Enter the coordinate to place your boat (Ex. A1, B3, C2): ";
        cin >> coordinate;

        if (coordinate.length() == 2) {
            coordinate[0] = toupper(coordinate[0]);

            if (coordinate[0] >= 'A' && coordinate[0] <= 'D' &&
                coordinate[1] >= '1' && coordinate[1] <= '4') {
                valid = true;
            }
        }

        if (!valid) {
            cout << "Invalid input. Please enter a coordinate from A1 to D4." << endl;
        }
    }

    return coordinate;
}
