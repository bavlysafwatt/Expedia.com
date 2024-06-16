#ifndef EXPEDIA_COM_IHOTELSMANAGER_H
#define EXPEDIA_COM_IHOTELSMANAGER_H

#include "../Hotels/HotelRoom.h"
#include "../Hotels/HotelRequest.h"
#include "../Hotels/HiltonRoom.h"
#include "../Hotels/MarriottFoundRoom.h"


class IHotelsManager{
protected:
    HotelRequest request;
public:
    virtual void SetHotelRequest(const HotelRequest &request_) {
        request = request_;
    }
    virtual vector<HotelRoom> SearchHotelRooms() const = 0;
    virtual string GetName() const = 0;
    virtual ~IHotelsManager(){}
};

class HiltonHotelsManager : public IHotelsManager{
private:

public:
    virtual string GetName() const override{
        return "Hilton Hotel";
    }

    virtual vector<HotelRoom> SearchHotelRooms() const override{
        vector<HiltonRoom> api = HiltonHotelAPI::SearchRooms(request.GetCountry(), request.GetCity(), request.GetFromDate(), request.GetToDate(), request.GetAdults(), request.GetChildren(), request.GetRooms());
        vector<HotelRoom> rooms;
        for(auto &api_room : api){
            HotelRoom room;
            room.SetHotelName("Hilton Hotel");
            room.SetDateFrom(api_room.date_from);
            room.SetDateTo(api_room.date_to);
            room.SetPricePerNight(api_room.price_per_night);
            room.SetAvailableRooms(api_room.available);
            room.SetRoomType(api_room.room_type);

            rooms.push_back(room);
        }
        return rooms;
    }
};

class MarriottHotelsManager : public IHotelsManager{
public:
    virtual string GetName() const override{
        return "Marriott Hotel";
    }

    virtual vector<HotelRoom> SearchHotelRooms() const override{
        vector<MarriottFoundRoom> api = MarriottHotelAPI::FindRooms(request.GetCountry(), request.GetCity(), request.GetFromDate(), request.GetToDate(), request.GetAdults(), request.GetChildren(), request.GetRooms());
        vector<HotelRoom> rooms;
        for(auto &api_room : api){
            HotelRoom room;
            room.SetHotelName("Marriott Hotel");
            room.SetDateFrom(api_room.date_from);
            room.SetDateTo(api_room.date_to);
            room.SetPricePerNight(api_room.price_per_night);
            room.SetAvailableRooms(api_room.available);
            room.SetRoomType(api_room.room_type);

            rooms.push_back(room);
        }
        return rooms;
    }
};

#endif //EXPEDIA_COM_IHOTELSMANAGER_H
