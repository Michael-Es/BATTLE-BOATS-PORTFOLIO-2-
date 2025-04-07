#pragma once
#include <string>
#include <array>
#include <sstream>

std::string getValidCoordinate(); //Validation

class BattleBoatsGrid { //Classes
private:
    std::array<std::array<std::string, 4>, 4> rowValues;

    std::string generateRow(std::string letter, int index);
    std::string generateHeader();

public:
    BattleBoatsGrid();
    void addBoat(std::string coordinate);
    void fireShot(std::string coordinate);
    std::string display();
};