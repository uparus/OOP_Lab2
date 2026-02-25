#include <iostream>
#include <conio.h>
#include "exceptions.h"
using namespace std;

    char Exceptions::allowedIndex() {
        char letter = _getch();
        char allowedLetters[] = { 'a', 's', 'w', 'd', 'x'};
        int size = sizeof(allowedLetters) / sizeof(allowedLetters[0]);
        for (int i = 0; i < size; i++) {
            if (letter == allowedLetters[i]) return allowedLetters[i];
        }
        return 0;
    }