#ifndef EXPEDIA_COM_RESERVATIONSSET_H
#define EXPEDIA_COM_RESERVATIONSSET_H

#include "Reservation.h"
#include "ItineraryReservation.h"

class ReservationsSet: public ItineraryReservation {
public:
    using ItineraryReservation::ItineraryReservation;

    virtual Reservation* Clone() const {
        return new ReservationsSet(*this);
    }
};

#endif //EXPEDIA_COM_RESERVATIONSSET_H
