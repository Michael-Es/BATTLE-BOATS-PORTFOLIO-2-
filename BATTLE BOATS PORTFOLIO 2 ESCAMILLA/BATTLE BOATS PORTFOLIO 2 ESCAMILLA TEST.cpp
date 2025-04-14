#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include "BATTLE BOATS BOT HEADER.h"
#include "BATTLE BOATS PORTFOLIO 2 ESCAMILLA Header.h"
using namespace std;


int main() {}
    struct Position {
        int row;
        int col;
    };

    Position convertInput(const string & input) {
        return { input[1] - '1', input[0] - 'A' };
    }

    bool isValidInput(const string & input) {
        if (input.length() != 2) return false;
        char col = input[0];
        char row = input[1];
        return (col >= 'A' && col <= 'D') && (row >= '1' && row <= '4');
    }

    void testConvertInput() {
        Position p = convertInput("A1");
        assert(p.row == 0 && p.col == 0);

        p = convertInput("D4");
        assert(p.row == 3 && p.col == 3);

        cout << "testConvertInput passed.\n";
    }

    void testIsValidInput() {
        assert(isValidInput("A1"));
        assert(isValidInput("D4"));
        assert(!isValidInput("E1"));
        assert(!isValidInput("A5"));
        assert(!isValidInput(""));

        cout << "testIsValidInput passed.\n";
    }

    int main() {
        testConvertInput();
        testIsValidInput();
        cout << "All tests passed.\n";
        return 0;
    }