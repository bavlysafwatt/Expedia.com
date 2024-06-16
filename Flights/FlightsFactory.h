#ifndef EXPEDIA_COM_FLIGHTSFACTORY_H
#define EXPEDIA_COM_FLIGHTSFACTORY_H
#include "../Managers/IFlighsManager.h"

class FlightsFactory{
public:
    static vector<IFlighsManager*> GetManagers(){
        vector<IFlighsManager*> managers;
        managers.push_back(new TurkishFlighsManager());
        managers.push_back(new AirCanadaFlighsManager());

        return managers;
    }
    static IFlighsManager* GetManager(string name){
        for(auto manager : FlightsFactory::GetManagers()){
            if(manager->GetName() == name)
                return manager;
        }
        return nullptr;
    }
};

#endif //EXPEDIA_COM_FLIGHTSFACTORY_H
