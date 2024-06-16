#ifndef EXPEDIA_COM_HILTONROOM_H
#define EXPEDIA_COM_HILTONROOM_H

#include <bits/stdc++.h>
using namespace std;

class HiltonRoom{
public:
    string room_type;
    int available;
    double price_per_night;
    string date_from;
    string date_to;
};

class HiltonHotelAPI{
public:
    static vector<HiltonRoom> SearchRooms(string country, string city, string from_date, string to_date, int adults, int children, int needed_rooms) {
        vector<HiltonRoom> rooms;

        rooms.push_back( { "Interior View", 6, 200.0, "16-07-2024", "22-07-2024" });
        rooms.push_back( { "City View", 3, 300.0, "01-08-2024", "03-08-2024" });
        rooms.push_back( { "Deluxe View", 8, 500.0, "10-08-2024", "18-08-2024" });

        return rooms;
    }
};

#endif //EXPEDIA_COM_HILTONROOM_H
