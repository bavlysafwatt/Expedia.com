#ifndef EXPEDIA_COM_RESERVATION_H
#define EXPEDIA_COM_RESERVATION_H

#include <bits/stdc++.h>
using namespace std;

class Reservation{
public:
    virtual Reservation* Clone()const = 0;
    virtual double TotalCost() const = 0;
    virtual string ToString() const = 0;
    virtual ~Reservation(){}
};

#endif //EXPEDIA_COM_RESERVATION_H
