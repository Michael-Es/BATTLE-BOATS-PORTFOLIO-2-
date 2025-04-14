#pragma once
#include <string>
#include <vector>


std::string getRandomPosition();

bool hasGuessed(const std::vector<std::string>& guesses, const std::string& pos);

std::string computerGuess(std::vector<std::string>& previousGuesses);

std::string placeComputerBoat();