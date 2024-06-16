#ifndef EXPEDIA_COM_HOTELRESERVATION_H
#define EXPEDIA_COM_HOTELRESERVATION_H

#include "Reservation.h"
#include "../Hotels/HotelRoom.h"
#include "../Hotels/HotelRequest.h"

class HotelReservation : public Reservation{
private:
    HotelRequest request;
    HotelRoom room;

public:
    HotelReservation(const HotelRequest &request, const HotelRoom &room) :
            request(request), room(room) {
    }

    virtual HotelReservation* Clone() const override{
        return new HotelReservation(*this);
    }

    virtual double TotalCost() const override{
        return room.GetPricePerNight()*request.GetTotalNights();
    }
    virtual string ToString() const override {
        ostringstream oss;
        oss << "Hotel reservation: " << room.GetHotelName() << ": " << request.GetCity() << " @ " << request.GetCountry() << "\n";
        oss << "\t" << request.GetFromDate() << " to " << request.GetToDate() << " : " << request.GetTotalNights() << "\n";
        oss << "\t" << "Adults: " << request.GetAdults() << " children " << request.GetChildren() << "\n";
        oss << "\tTotal Cost:" << TotalCost() << "\n";

        return oss.str();
    }

    const HotelRequest& GetRequest() const {
        return request;
    }

    const HotelRoom& GetRoom() const {
        return room;
    }
};

#endif //EXPEDIA_COM_HOTELRESERVATION_H
