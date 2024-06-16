#ifndef EXPEDIA_COM_HOTELREQUEST_H
#define EXPEDIA_COM_HOTELREQUEST_H

#include <string>
using namespace std;

class HotelRequest {
private:
    string from_date;
    string to_date;
    string country;
    string city;
    int rooms;
    int adults;
    int children;

public:
    int GetTotalNights() const {
        // Some date computations
        return 3;
    }
    int GetAdults() const {
        return adults;
    }

    void SetAdults(int adults) {
        this->adults = adults;
    }

    int GetChildren() const {
        return children;
    }

    void SetChildren(int children) {
        this->children = children;
    }

    const string& GetCity() const {
        return city;
    }

    void SetCity(const string& city) {
        this->city = city;
    }

    const string& GetCountry() const {
        return country;
    }

    void SetCountry(const string& country) {
        this->country = country;
    }

    const string& GetFromDate() const {
        return from_date;
    }

    void SetFromDate(const string& fromDate) {
        from_date = fromDate;
    }

    int GetRooms() const {
        return rooms;
    }

    void SetRooms(int rooms) {
        this->rooms = rooms;
    }

    const string& GetToDate() const {
        return to_date;
    }

    void SetToDate(const string& toDate) {
        to_date = toDate;
    }
};

#endif //EXPEDIA_COM_HOTELREQUEST_H
