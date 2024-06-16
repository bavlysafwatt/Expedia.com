#ifndef EXPEDIA_COM_USERMANAGER_H
#define EXPEDIA_COM_USERMANAGER_H

#include "../Characters/Customer.h"
#include "../helpers.h"

class UserManager{
private:
    User* current_user = nullptr;
    map<string, User*> user_object;

    void FreeLoadData(){
        for(auto pair : user_object){
            delete pair.second;
        }
        user_object.clear();
        current_user = nullptr;
    }
public:
    UserManager(const UserManager&) = delete;
    void operator=(const UserManager&) = delete;

    UserManager(){}

    ~UserManager(){
        FreeLoadData();
    }

    void loaddatabase(){
        FreeLoadData();
        Customer* customrUser = new Customer();
        customrUser->SetUserName("bavly");
        customrUser->SetPassword("222");
        customrUser->SetEmail("bavly@gmail.com");
        customrUser->SetName("Bavly Safwat Abd-Elshaheed");

        DebitCard* debitCard = new DebitCard();
        debitCard->SetOwnerName(customrUser->GetName());
        debitCard->SetCardNumber("11-22-33-44");
        debitCard->SetExpiryDate("11/20");
        debitCard->SetSecurityCode(111);
        debitCard->SetBillingAddress("111 hello st, BC, Canada");
        customrUser->AddPaymentCard(*debitCard);

        CreditCard* creditCard = new CreditCard();
        creditCard->SetOwnerName(customrUser->GetName());
        creditCard->SetCardNumber("22-11-03-44");
        creditCard->SetExpiryDate("11/25");
        creditCard->SetSecurityCode(1117);
        customrUser->AddPaymentCard(*creditCard);
        user_object[customrUser->GetUserName()] = customrUser;
    }

    void AccessSystem(){
        int choice = readmenu({"Login", "Sign Up", "Exit"});
        if(choice==1) login();
        else if(choice==2) sign_up();
        else exit(0);
    }

    void login(){
        loaddatabase();
        while(true){
            string un, pass;
            cout << "Enter user name (no spaces): ";
            cin >> un;
            cout << "Enter password (no spaces): ";
            cin >> pass;
            if(!user_object.count(un)){
                cout << "\nInvalid user user_name or password. Try again\n\n";
                continue;
            }
            User *user = user_object[un];
            if(pass!=user->GetPassword()){
                cout << "\nInvalid user user_name or password. Try again\n\n";
                continue;
            }
            current_user = user;
            break;
        }
    }

    void sign_up(){
        string user_name;
        while(true){
            cout << "Enter user name(no spaces): ";
            cin >> user_name;
            if(user_object.count(user_name))
                cout << "Already used, please try again." << endl;
            else
                break;
        }
        current_user = new Customer();
        current_user->Read(user_name);
        user_object[current_user->GetUserName()] = current_user;
        cout << "Do you want to add DebitCard or CreditCard: ";
        vector<string> menu;
        menu.push_back("DebitCard");
        menu.push_back("CreditCard");
        menu.push_back("Continue");
        while (true){
            int choice = readmenu(menu);
            if(choice==1){
                DebitCard *card = new DebitCard();
                string owner_name, card_number, expiry_date, billing_address;
                int security_code;
                cout << "Enter owner name: "; cin >> owner_name;
                cout << "Enter card number: "; cin >> card_number;
                cout << "Enter expiry date: "; cin >> expiry_date;
                cout << "Enter security code: "; cin >> security_code;
                cout << "Enter billing address: "; cin >> billing_address;
                card->SetOwnerName(owner_name);
                card->SetCardNumber(card_number);
                card->SetExpiryDate(expiry_date);
                card->SetSecurityCode(security_code);
                card->SetBillingAddress(billing_address);
                current_user->AddPaymentCard(*card);
            }
            else if(choice==2){
                CreditCard *card = new CreditCard();
                string owner_name, card_number, expiry_date;
                int security_code;
                cout << "Enter owner name: "; cin >> owner_name;
                cout << "Enter card number: "; cin >> card_number;
                cout << "Enter expiry date: "; cin >> expiry_date;
                cout << "Enter security code: "; cin >> security_code;
                card->SetOwnerName(owner_name);
                card->SetCardNumber(card_number);
                card->SetExpiryDate(expiry_date);
                card->SetSecurityCode(security_code);
                current_user->AddPaymentCard(*card);
            }
            else break;
        }
    }
    User* getcurrentuser() const{
        return current_user;
    }
};

#endif //EXPEDIA_COM_USERMANAGER_H
