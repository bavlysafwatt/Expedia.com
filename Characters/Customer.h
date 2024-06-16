#ifndef EXPEDIA_COM_CUSTOMER_H
#define EXPEDIA_COM_CUSTOMER_H

#include "User.h"
#include "../Reservation/Reservation.h"
#include "../Reservation/ReservationsSet.h"

class Customer: public User {
protected:
    vector<PaymentCard*> cards;
    ReservationsSet reservations;

public:
    Customer(const Customer&) = delete;
    void operator=(const Customer&) = delete;

    Customer() {

    }

    ~Customer() {
        for (PaymentCard* card : cards)
            delete card;
        cards.clear();
    }

    void AddPaymentCard(const PaymentCard& card) {
        cards.push_back(card.Clone());
    }

    void AddReservation(const Reservation& reservation) {
        reservations.AddReservation(*reservation.Clone());
    }

    const vector<PaymentCard*>& GetCards() const {
        return cards;
    }

    const ReservationsSet& GetReservations() const {
        return reservations;
    }
};

#endif //EXPEDIA_COM_CUSTOMER_H
