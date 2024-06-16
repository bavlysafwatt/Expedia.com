#ifndef EXPEDIA_COM_AIRCANADAFLIGHT_H
#define EXPEDIA_COM_AIRCANADAFLIGHT_H

#include <bits/stdc++.h>
using namespace std;

class AirCanadaFlight {
public:
    double price;
    string date_time_from;
    string date_time_to;
};

class AirCanadaOnlineAPI{
public:
    static vector<AirCanadaFlight> GetFlights(string from, string from_date, string to, string to_date, int adults, int childern) {
        vector<AirCanadaFlight> flights;

        flights.push_back( { 200, "16-07-2024", "25-07-2024" });
        flights.push_back( { 250, "14-07-2024", "20-07-2024" });
        flights.push_back( { 300, "20-07-2024", "25-07-2024" });
        flights.push_back( { 400, "01-08-2024", "05-08-2024" });
        flights.push_back( { 150, "02-08-2024", "06-08-2024" });
        return flights;
    }
};

#endif //EXPEDIA_COM_AIRCANADAFLIGHT_H
