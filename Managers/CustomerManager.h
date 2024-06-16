#ifndef EXPEDIA_COM_CUSTOMERMANAGER_H
#define EXPEDIA_COM_CUSTOMERMANAGER_H

#include "../Characters/Customer.h"
#include "../ExpediaBackend.h"

class CustomerManager{
private:
    Customer *customer;
    ExpediaBackend &expedia_manager;
public:
    CustomerManager(User *user, ExpediaBackend &expedia_manager) :
            customer(dynamic_cast<Customer*>(user)), expedia_manager(expedia_manager) {

        if (customer == nullptr) {
            cout << "Error: User is null pointer as input\n";
        }
    }

    vector<Flight> FindFlights(const FlightRequest &request) const {
        return expedia_manager.FindFlights(request);
    }

    vector<HotelRoom> FindHotels(const HotelRequest &request) const {
        return expedia_manager.FindHotels(request);
    }

    vector<string> GetPaymentChoices() const {
        vector<string> cards_info;

        for (PaymentCard* card : customer->GetCards())
            cards_info.push_back(card->ToString());
        return cards_info;
    }

    bool MakeReservation(const Reservation& reservation, PaymentCard &payment_card) {
        bool is_paid = payment_card.ChargeCost(reservation.TotalCost());

        if (is_paid) {
            cout << "Money withdraw successfully\n";
            cout << "Reservation confirmed\n";
            customer->AddReservation(reservation);
            return true;
        }
        else
            cout << "Failed to withdtaw Money for the reservation\n";

        return false;
    }

    vector<string> GetItineraries() const {
        const ReservationsSet& set = customer->GetReservations();
        vector<string> itineraries;

        for (const Reservation* reservation : set.GetReservations())
            itineraries.push_back(reservation->ToString());

        return itineraries;
    }

    const Customer* GetCustomer() const {
        return customer;
    }
};

#endif //EXPEDIA_COM_CUSTOMERMANAGER_H
