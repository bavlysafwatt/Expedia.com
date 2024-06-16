#ifndef EXPEDIA_COM_HOTELSFACTORY_H
#define EXPEDIA_COM_HOTELSFACTORY_H

#include "../Managers/IHotelsManager.h"

class HotelsFactory{
public:
    static vector<IHotelsManager*> GetManagers(){
        vector<IHotelsManager*> managers;
        managers.push_back(new HiltonHotelsManager());
        managers.push_back(new MarriottHotelsManager());

        return managers;
    }
    static IHotelsManager* GetManager(string name){
        for(auto manager : HotelsFactory::GetManagers()){
            if(manager->GetName() == name)
                return manager;
        }
        return nullptr;
    }
};

#endif //EXPEDIA_COM_HOTELSFACTORY_H
