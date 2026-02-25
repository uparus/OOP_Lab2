#include <iostream>
#include "exceptions.h"
#include "radio.h"
using namespace std;




int main() {
    Radio Radio;
    Exceptions Exception;

    cout << "\nPress W,S to adjust the volume of the radio\nPress A,D to adjust the station of the radio\nPress X to exit the radio\n";
    char option;
    do {
        cout << "\nVolume: " << Radio.getVolume() << endl;
        cout << "Station № " << Radio.getStation() << endl;
        option = Exception.allowedIndex();
        switch (option) {
            case 'a': {
                Radio.previousStation();
                break;
            }
            case 'd': {
                Radio.nextStation();
                break;
            }
            case 'w': {
                Radio.incVolume();
                if (Radio.getVolume() == Radio.getMaxVolume()) clog << "The audio level is set to max\n";
                break;
            }
            case 's': {
                Radio.decVolume();
                if (Radio.getVolume() == Radio.getMinVolume()) clog << "The audio level is set to min\n";
                break;
            }
            default: {
                continue;
            }
        }
    }while (option != 'x');


    return 0;
}