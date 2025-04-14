#include "BATTLE BOATS BOT HEADER.h"
#include <cstdlib>
#include <ctime>

std::string getRandomPosition() {
    char rows[] = { 'A', 'B', 'C', 'D' };
    int cols[] = { 1, 2, 3, 4 };

    char row = rows[rand() % 4];
    int col = cols[rand() % 4];

    return std::string(1, row) + std::to_string(col);
}

bool hasGuessed(const std::vector<std::string>& guesses, const std::string& pos) {
    for (const std::string& guess : guesses) {
        if (guess == pos) return true;
    }
    return false;
}

std::string computerGuess(std::vector<std::string>& previousGuesses) {
    std::string guess;
    do {
        guess = getRandomPosition();
    } while (hasGuessed(previousGuesses, guess));

    previousGuesses.push_back(guess);
    return guess;
}

std::string placeComputerBoat() {
    return getRandomPosition(); // Randomly place a boat
}