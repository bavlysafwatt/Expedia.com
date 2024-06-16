cmake_minimum_required(VERSION 3.26)
project(Expedia_com)

set(CMAKE_CXX_STANDARD 17)

add_executable(Expedia_com main.cpp helpers.h ExpediaFrontend.h ExpediaBackend.h CustomerView.h
        Reservation/Reservation.h Reservation/ReservationsSet.h Reservation/ItineraryReservation.h Reservation/HotelReservation.h Reservation/FlightReservation.h
        Managers/CustomerManager.h Managers/IFlighsManager.h Managers/IHotelsManager.h Managers/UserManager.h
        Hotels/HiltonRoom.h Hotels/HotelRequest.h Hotels/HotelRoom.h Hotels/HotelsFactory.h Hotels/MarriottFoundRoom.h
        Flights/AirCanadaFlight.h Flights/Flight.h Flights/FlightRequest.h Flights/FlightsFactory.h Flights/TurkishFlight.h
        Characters/Customer.h Characters/PaymentCard.h Characters/User.h)
