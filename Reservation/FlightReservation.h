#ifndef EXPEDIA_COM_FLIGHTRESERVATION_H
#define EXPEDIA_COM_FLIGHTRESERVATION_H

#include "Reservation.h"
#include "../Flights/Flight.h"
#include "../Flights/FlightRequest.h"

class FlightReservation : public Reservation{
private:
    FlightRequest request;
    Flight flight;
public:
    FlightReservation(const FlightRequest &request, const Flight &flight) :
            request(request), flight(flight) {
    }

    virtual FlightReservation* Clone() const override {
        return new FlightReservation(*this);
    }

    virtual double TotalCost() const override {
        return flight.GetTotalCost();
    }

    virtual string ToString() const override {
        ostringstream oss;
        oss << "Airline reservation with reservation: " << flight.GetAirlineName() << ": From " << request.GetFrom() << " on " << request.GetDatetimeFrom() << "\n";
        oss << "\tTo " << request.GetTo() << " on " << request.GetDatetimeTo() << "\n";
        oss << "\t" << "Adults: " << request.GetAdults() << " children: " << request.GetChildren() << " infants: " << request.GetInfants() << "\n";
        oss << "\tTotal Cost:" << TotalCost() << "\n";

        return oss.str();
    }

    const Flight& GetFlight() const {
        return flight;
    }

    const FlightRequest& GetRequest() const {
        return request;
    }
};

#endif //EXPEDIA_COM_FLIGHTRESERVATION_H
