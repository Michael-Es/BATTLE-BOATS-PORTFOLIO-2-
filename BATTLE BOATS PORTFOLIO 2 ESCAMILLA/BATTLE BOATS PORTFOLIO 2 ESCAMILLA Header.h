#pragma once
#include <string>
#include <array>
#include <sstream>

std::string getValidCoordinate(); // Validation

class BattleBoatsGrid {
private:
    std::array<std::array<std::string, 4>, 4> rowValues;
    std::string boatSymbol = "@"; 

    std::string generateRow(std::string letter, int index);
    std::string generateHeader();

public:
    BattleBoatsGrid();
    void setBoatSymbol(std::string symbol);  
    void addBoat(std::string coordinate);
    void fireShot(std::string coordinate);
    std::string display();
};

std::string getValidCoordinate(); // VALIDATION FOR BOAT PICK
bool isValidBoatSymbol(char symbol);
std::string getValidBoatSymbol();