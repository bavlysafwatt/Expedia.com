#ifndef EXPEDIA_COM_EXPEDIABACKEND_H
#define EXPEDIA_COM_EXPEDIABACKEND_H

#include "Managers/IHotelsManager.h"
#include "Managers/IFlighsManager.h"
#include "Hotels/HotelsFactory.h"
#include "Flights/FlightsFactory.h"

class ExpediaBackend{
private:
    vector<IFlighsManager*> flights_managers;
    vector<IHotelsManager*> hotels_managers;
public:
    ExpediaBackend(const ExpediaBackend&) = delete;
    void operator=(const ExpediaBackend&) = delete;

    ExpediaBackend(){
        flights_managers = FlightsFactory::GetManagers();
        hotels_managers = HotelsFactory::GetManagers();
    }

    vector<Flight> FindFlights(const FlightRequest& request_) const{
        vector<Flight> flights;
        for(auto *mgr : flights_managers){
            mgr->SetFlightRequest(request_);
            vector<Flight> more = mgr->SearchFlights();
            flights.insert(flights.end(), more.begin(), more.end());
        }
        return flights;
    }

    vector<HotelRoom> FindHotels(const HotelRequest& request_) const{
        vector<HotelRoom> rooms;
        for(auto *mgr : hotels_managers){
            mgr->SetHotelRequest(request_);
            vector<HotelRoom> more = mgr->SearchHotelRooms();
            rooms.insert(rooms.end(), more.begin(), more.end());
        }
        return rooms;
    }
};

#endif //EXPEDIA_COM_EXPEDIABACKEND_H
