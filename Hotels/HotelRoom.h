#ifndef EXPEDIA_COM_HOTELROOM_H
#define EXPEDIA_COM_HOTELROOM_H

#include <bits/stdc++.h>
using namespace std;

class HotelRoom{
private:
    string hotel_name;
    string room_type;
    int available_rooms = 0;
    double price_per_night = 0;
    string date_from;
    string date_to;
public:
    string ToString() const{
        ostringstream oss;
        oss << "Hotel Name: " << hotel_name << " Room Type: " << room_type << "(" << available_rooms << ")" << "Price per night: " << price_per_night << " From Date " << date_from << " to " << date_to << "";
        return oss.str();
    }
    const string& GetDateFrom() const {
        return date_from;
    }

    void SetDateFrom(const string& dateFrom) {
        date_from = dateFrom;
    }

    const string& GetDateTo() const {
        return date_to;
    }

    void SetDateTo(const string& dateTo) {
        date_to = dateTo;
    }

    double GetPricePerNight() const {
        return price_per_night;
    }

    void SetPricePerNight(double pricePerNight) {
        price_per_night = pricePerNight;
    }

    const string& GetRoomType() const {
        return room_type;
    }

    void SetRoomType(const string& roomType) {
        room_type = roomType;
    }

    int GetAvailableRooms() const {
        return available_rooms;
    }

    void SetAvailableRooms(int availableRooms = 0) {
        available_rooms = availableRooms;
    }

    const string& GetHotelName() const {
        return hotel_name;
    }

    void SetHotelName(const string& hotelName) {
        hotel_name = hotelName;
    }
};

#endif //EXPEDIA_COM_HOTELROOM_H
