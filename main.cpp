#include <iostream>
#include <conio.h>
using namespace std;

class Radio
{
private:
    unsigned int m_volume;
    unsigned int m_station;
    const unsigned int MIN_VOLUME = 0;
    const unsigned int MAX_VOLUME = 10;
    const unsigned int MIN_STATION = 1;
    const unsigned int MAX_STATION = 10;
public:
    Radio() {
        clog << "The volume is set to 3\n";
        clog << "The station is set to 1\n";
        m_volume = 3;
        m_station = MIN_STATION;
    }

    unsigned int getVolume() const {return m_volume;};
    unsigned int getStation() const{return m_station;};
    int getMaxVolume() const {return MAX_VOLUME;};
    int getMinVolume() const {return MIN_VOLUME;};

    void setVolume(unsigned int const & volume) {
        if (volume >= MIN_VOLUME && volume <= MAX_VOLUME) {
            m_volume = volume;
        }
    }
    void setStation(unsigned int const & station) {
        if (station >= MIN_STATION && station <= MAX_STATION) {
            m_station = station;
        }
    }

    void incVolume() {if (m_volume < MAX_VOLUME) m_volume += 1;}
    void decVolume(){if (m_volume > MIN_VOLUME) m_volume -= 1;}

    void nextStation() {
        if (m_station == MAX_STATION) {
            m_station = MIN_STATION;
        } else {
            m_station += 1;
        }
    }
    void previousStation() {
        if (m_station == MIN_STATION) {
            m_station = MAX_STATION;
        } else {
            m_station -= 1;
        }
    }

    ~Radio();
};

Radio::~Radio() {}

class Exceptions {
public:
    char allowedIndex() {
        char letter = _getch();
        char allowedLetters[] = { 'a', 's', 'w', 'd', 'x'};
        int size = sizeof(allowedLetters) / sizeof(allowedLetters[0]);
        for (int i = 0; i < size; i++) {
            if (letter == allowedLetters[i]) return allowedLetters[i];
        }
        return 0;
    }
};

int main() {
    Radio radio;
    Exceptions Exception;

    cout << "\nPress W,S to adjust the volume of the radio\nPress A,D to adjust the station of the radio\nPress X to exit the radio\n";
    char option;
    do {
        cout << "\nVolume: " << radio.getVolume() << endl;
        cout << "Station № " << radio.getStation() << endl;
        option = Exception.allowedIndex();
        switch (option) {
            case 'a': {
                radio.previousStation();
                break;
            }
            case 'd': {
                radio.nextStation();
                break;
            }
            case 'w': {
                radio.incVolume();
                if (radio.getVolume() == radio.getMaxVolume()) clog << "The audio level is set to max\n";
                break;
            }
            case 's': {
                radio.decVolume();
                if (radio.getVolume() == radio.getMinVolume()) clog << "The audio level is set to min\n";
                break;
            }
            default: {
                continue;
            }
        }
    }while (option != 'x');


    return 0;
}