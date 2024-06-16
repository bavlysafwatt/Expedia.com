#ifndef EXPEDIA_COM_EXPEDIAFRONTEND_H
#define EXPEDIA_COM_EXPEDIAFRONTEND_H

#include "ExpediaBackend.h"
#include "CustomerView.h"
#include "Managers/UserManager.h"

class ExpediaFrontend{
private:
    UserManager *user_manager;
    ExpediaBackend *expedia_manager;
    CustomerManager *customer_manager = nullptr;

    void LoadDataBase(){
        user_manager->loaddatabase();
    }
public:
    ExpediaFrontend(const ExpediaFrontend&) = delete;
    void operator=(const ExpediaFrontend&) = delete;

    ExpediaFrontend() : user_manager(new UserManager()), expedia_manager(new ExpediaBackend()){
    }

    ~ExpediaFrontend() {
        cout << "Destructor: ExpediaFrontend\n";

        if (user_manager != nullptr) {
            delete user_manager;
            user_manager = nullptr;
        }
        if (expedia_manager != nullptr) {
            delete expedia_manager;
            expedia_manager = nullptr;
        }
    }

    void run(){
        LoadDataBase();
        while(true){
            user_manager->AccessSystem();
            customer_manager = new CustomerManager(user_manager->getcurrentuser(), *expedia_manager);
            CustomerView view(*customer_manager);
            view.Display();
        }
    }
};

#endif //EXPEDIA_COM_EXPEDIAFRONTEND_H
