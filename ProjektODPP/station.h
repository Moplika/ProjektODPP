#ifndef STATION_H
#define STATION_H

struct Station
{
    int id;
    int firstPosition; //Position in permutation of first element on station
    int lastPosition; //Position in permutation of last element on station

    Station(unsigned int idNumber, unsigned int first, unsigned int last) {
        id = idNumber;
        firstPosition = first;
        lastPosition = last;
    }
};

#endif // STATION_H
