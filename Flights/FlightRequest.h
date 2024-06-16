#ifndef EXPEDIA_COM_FLIGHTREQUEST_H
#define EXPEDIA_COM_FLIGHTREQUEST_H

#include <bits/stdc++.h>
using namespace std;

class FlightRequest{
private:
    string datetime_from;
    string from;
    string datetime_to;
    string to;
    int infants;
    int childern;
    int adults;
public:
    string GetDatePartFrom() const {
        return datetime_from;	// extract date only
    }

    string GetDatePartTo() const {
        return datetime_to;	// extract date only
    }

    int GetAdults() const {
        return adults;
    }

    void SetAdults(int adults) {
        this->adults = adults;
    }

    int GetChildren() const {
        return childern;
    }

    void SetChildren(int childern) {
        this->childern = childern;
    }

    const string& GetDatetimeFrom() const {
        return datetime_from;
    }

    void SetDatetimeFrom(const string& datetimeFrom) {
        datetime_from = datetimeFrom;
    }

    const string& GetDatetimeTo() const {
        return datetime_to;
    }

    void SetDatetimeTo(const string& datetimeTo) {
        datetime_to = datetimeTo;
    }

    const string& GetFrom() const {
        return from;
    }

    void SetFrom(const string& from) {
        this->from = from;
    }

    int GetInfants() const {
        return infants;
    }

    void SetInfants(int infants) {
        this->infants = infants;
    }

    const string& GetTo() const {
        return to;
    }

    void SetTo(const string& to) {
        this->to = to;
    }
};

#endif //EXPEDIA_COM_FLIGHTREQUEST_H
