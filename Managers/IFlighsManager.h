#ifndef EXPEDIA_COM_IFLIGHSMANAGER_H
#define EXPEDIA_COM_IFLIGHSMANAGER_H

#include "../Flights/Flight.h"
#include "../Flights/FlightRequest.h"
#include "../Flights/AirCanadaFlight.h"
#include "../Flights/TurkishFlight.h"

class IFlighsManager{
protected:
    FlightRequest request;
public:
    virtual void SetFlightRequest(const FlightRequest &request_) {
        request = request_;
    }
    virtual vector<Flight> SearchFlights() const = 0;
    virtual string GetName() const = 0;
    virtual ~IFlighsManager(){}
};

class AirCanadaFlighsManager : public IFlighsManager{
public:
    virtual string GetName() const{
        return "AirCanada Airlines";
    }

    virtual vector<Flight> SearchFlights() const override{
        vector<AirCanadaFlight> api = AirCanadaOnlineAPI::GetFlights(request.GetFrom(), request.GetDatePartFrom(), request.GetTo(), request.GetDatePartTo(), request.GetAdults(), request.GetChildren());
        vector<Flight> flights;
        for(auto &f : api){
            Flight flight;
            flight.SetAirlineName(GetName());
            flight.SetTotalCost(f.price);
            flight.SetDateTimeFrom(f.date_time_from);
            flight.SetDateTimeTo(f.date_time_to);

            flights.push_back(flight);
        }
        return flights;
    }
};

class TurkishFlighsManager: public IFlighsManager{
public:
    virtual string GetName() const{
        return "Turkish Airlines";
    }

    virtual vector<Flight> SearchFlights() const override{
        TurkishAirlinesOnlineAPI api;
        vector<TurkishFlight> fl = api.GetAvailableFlights();
        vector<Flight> flights;
        for(auto &f : fl){
            Flight flight;
            flight.SetAirlineName(GetName());
            flight.SetTotalCost(f.cost);
            flight.SetDateTimeFrom(f.datetime_from);
            flight.SetDateTimeTo(f.datetime_to);

            flights.push_back(flight);
        }
        return flights;
    }
};

#endif //EXPEDIA_COM_IFLIGHSMANAGER_H
