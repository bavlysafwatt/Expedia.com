#ifndef EXPEDIA_COM_MARRIOTTFOUNDROOM_H
#define EXPEDIA_COM_MARRIOTTFOUNDROOM_H

#include <bits/stdc++.h>
using namespace std;

class MarriottFoundRoom {
public:
    string room_type;
    int available;
    double price_per_night;
    string date_from;
    string date_to;
};

class MarriottHotelAPI {
public:
    static vector<MarriottFoundRoom> FindRooms(string from_date, string to_date, string country, string city, int needed_rooms, int adults, int children) {
        vector<MarriottFoundRoom> rooms;

        rooms.push_back( { "City View", 8, 320.0, "16-08-2024", "25-08-2024" });
        rooms.push_back( { "Interior View", 8, 220.0, "16-08-2024", "25-08-2024" });
        rooms.push_back( { "Private View", 5, 600.0, "16-08-2024", "25-08-2024" });

        return rooms;
    }
};

#endif //EXPEDIA_COM_MARRIOTTFOUNDROOM_H
