#ifndef MACHINE_H
#define MACHINE_H

struct Machine
{
    int id;
    int firstPosition; //Position in permutation of first element on station
    int lastPosition; //Position in permutation of last element on station

    Machine(unsigned int idNumber, unsigned int first, unsigned int last) {
        id = idNumber;
        firstPosition = first;
        lastPosition = last;
    }
};

#endif // MACHINE_H
