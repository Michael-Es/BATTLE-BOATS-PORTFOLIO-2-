#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include "BATTLE BOATS PORTFOLIO 2 ESCAMILLA Header.h"


using namespace std;

int main() {
cout << "Welcome to Battle Boats" << endl;

BattleBoatsGrid grid;

string boatPosition = getValidCoordinate();
grid.addBoat(boatPosition);

cout << "This is your boat location!" << endl;
cout << grid.display();


string shot = getValidCoordinate();
grid.fireShot(shot);

cout << "After firing a shot!" << endl;
cout << grid.display();
}
