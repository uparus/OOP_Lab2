#ifndef RADIO_H
#define RADIO_H

#include <iostream>
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

    unsigned int getVolume() const;
    unsigned int getStation() const;
    int getMaxVolume() const;
    int getMinVolume() const;

    void setVolume(unsigned int const & volume);
    void setStation(unsigned int const & station);

    void incVolume();
    void decVolume();

    void nextStation();
    void previousStation();

    ~Radio();
};



#endif //RADIO_H
