#ifndef EXPEDIA_COM_ITINERARYRESERVATION_H
#define EXPEDIA_COM_ITINERARYRESERVATION_H

#include "Reservation.h"

class ItineraryReservation : public Reservation{
protected:
    vector<Reservation*> reservations;
public:
    ItineraryReservation(const ItineraryReservation & another_reservation){
        for (const Reservation* reservation : another_reservation.GetReservations())
            AddReservation(*reservation);
    }

    ItineraryReservation() {}

    void AddReservation(const Reservation & reservation){
        reservations.push_back(reservation.Clone());
    }
    virtual double TotalCost() const{
        double cost = 0;
        for(auto it : reservations){
            cost+=it->TotalCost();
        }
        return cost;
    }
    ~ItineraryReservation(){
        Clear();
    }
    void Clear(){
        for(const auto it : reservations){
            delete it;
        }
        reservations.clear();
    }
    virtual string ToString() const override{
        ostringstream oss;
        oss <<"**********************************************\n";
        oss << "Itinerary of " << reservations.size() << " sub-reservations\n";

        for (const Reservation* reservation : reservations)
            oss << reservation->ToString() << "\n";

        oss << "Total Itinerary cost: " << TotalCost() << "\n";
        oss <<"**********************************************\n";
        return oss.str();
    }
    virtual Reservation* Clone() const override{
        return new ItineraryReservation(*this);
    }
    const vector<Reservation*>& GetReservations() const {
        return reservations;
    }
};

#endif //EXPEDIA_COM_ITINERARYRESERVATION_H
