#include <iostream>
#include "radio.h"

using namespace std;

unsigned int Radio::getVolume() const {return m_volume;};
unsigned int Radio::getStation() const{return m_station;};
int Radio::getMaxVolume() const {return MAX_VOLUME;};
int Radio::getMinVolume() const {return MIN_VOLUME;};

void Radio::setVolume(unsigned int const & volume) {
    if (volume >= MIN_VOLUME && volume <= MAX_VOLUME) {
        m_volume = volume;
    }
}
void Radio::setStation(unsigned int const & station) {
    if (station >= MIN_STATION && station <= MAX_STATION) {
        m_station = station;
    }
}

void Radio::incVolume() {if (m_volume < MAX_VOLUME) m_volume += 1;}
void Radio::decVolume(){if (m_volume > MIN_VOLUME) m_volume -= 1;}

void Radio::nextStation() {
    if (m_station == MAX_STATION) {
        m_station = MIN_STATION;
    } else {
        m_station += 1;
    }
}
void Radio::previousStation() {
    if (m_station == MIN_STATION) {
        m_station = MAX_STATION;
    } else {
        m_station -= 1;
    }
}

Radio::~Radio() {}
