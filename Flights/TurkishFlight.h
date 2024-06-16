#ifndef EXPEDIA_COM_TURKISHFLIGHT_H
#define EXPEDIA_COM_TURKISHFLIGHT_H

#include <bits/stdc++.h>
using namespace std;

class TurkishFlight{
public:
    double cost;
    string datetime_from;
    string datetime_to;
};

class TurkishAirlinesOnlineAPI{
public:
    void SetFromToInfo(string datetime_from, string from, string datetime_to, string to) {
    }
    void SetPassengersInfo(int infants, int childern, int adults) {
    }
    vector<TurkishFlight> GetAvailableFlights() const {
        vector<TurkishFlight> flights;

        flights.push_back( { 200, "16-07-2024", "25-07-2024" });
        flights.push_back( { 250, "14-07-2024", "20-07-2024" });
        flights.push_back( { 300, "20-07-2024", "25-07-2024" });
        flights.push_back( { 400, "01-08-2024", "05-08-2024" });
        flights.push_back( { 150, "02-08-2024", "06-08-2024" });
        return flights;
    }
};

#endif //EXPEDIA_COM_TURKISHFLIGHT_H
