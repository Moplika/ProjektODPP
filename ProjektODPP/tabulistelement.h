#ifndef TABULISTELEMENT_H
#define TABULISTELEMENT_H

struct TabuListElement
{
    unsigned int machineId;
    unsigned int frontElement;
    unsigned int backElement;

    TabuListElement(unsigned int machID, unsigned int front, unsigned int back) {
        machineId = machID;
        frontElement = front;
        backElement = back;
    }
};

#endif // TABULISTELEMENT_H
