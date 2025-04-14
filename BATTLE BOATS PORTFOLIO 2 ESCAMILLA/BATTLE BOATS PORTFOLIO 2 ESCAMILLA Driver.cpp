#include <iostream>
#include <sstream>
#include <array>
#include "BATTLE BOATS BOT HEADER.h"
#include "BATTLE BOATS PORTFOLIO 2 ESCAMILLA Header.h"


using namespace std;


void displayBothGrids(BattleBoatsGrid& playerGrid, BattleBoatsGrid& guessGrid) {
    std::stringstream left(playerGrid.display());
    std::stringstream right(guessGrid.display());

    std::string leftLine, rightLine;
    std::cout << "\nYou:                Computer:\n\n";

    while (std::getline(left, leftLine) && std::getline(right, rightLine)) {
        std::cout << leftLine << "\t   " << rightLine << "\n";
    }
}
int main() {
    srand(static_cast<unsigned int>(time(0))); 
    char playAgain;

    do {
        cout << "Welcome to Battle Boats!" << endl;

        BattleBoatsGrid playerGrid;
        BattleBoatsGrid computerGrid;
        BattleBoatsGrid playerGuessGrid;

        string symbol = getValidBoatSymbol();  
        playerGrid.setBoatSymbol(symbol);

        cout << "\nWhere would you like to hide your boat?\n";
        string playerBoat = getValidCoordinate();
        playerGrid.addBoat(playerBoat);

        computerGrid.setBoatSymbol("@");
        string computerBoat = placeComputerBoat();
        computerGrid.addBoat(computerBoat);

        cout << "\nGreat! Let's begin!" << endl;

        vector<string> computerGuesses;
        bool gameOver = false;

        while (!gameOver) {
            displayBothGrids(playerGrid, playerGuessGrid);

            cout << "\nPick a spot to fire! ";
            string playerShot = getValidCoordinate();
            cout << "\nYou chose " << playerShot << ". ";

            if (playerShot == computerBoat) {
                cout << "Hit!\n\nYou sunk the boat! Great job, you win!\n";
                playerGuessGrid.fireShot(playerShot);
                gameOver = true;
            }
            else {
                cout << "You missed!" << endl;
                playerGuessGrid.fireShot(playerShot);
            }

            if (!gameOver) {
                string compShot = computerGuess(computerGuesses);
                cout << "\nThe enemy chose " << compShot << ". ";

                if (compShot == playerBoat) {
                    cout << "They hit your boat!\n\nYou lose!\n\nThe Enemy Wins!" << endl;
                    playerGrid.fireShot(compShot);
                    gameOver = true;
                }
                else {
                    cout << "They missed!" << endl;
                    playerGrid.fireShot(compShot);
                }
            }
        }

        cout << "\n--- Final Grids ---" << endl;
        displayBothGrids(playerGrid, playerGuessGrid);

        
        do {
            cout << "\nWould you like to play again? (Y/N): ";
            cin >> playAgain;
            playAgain = toupper(playAgain);

            if (playAgain != 'Y' && playAgain != 'N') {
                cout << "Invalid input. Please enter Y or N." << endl;
            }
        } while (playAgain != 'Y' && playAgain != 'N');

    } while (playAgain == 'Y');

    return 0;
}
