#ifndef EXPEDIA_COM_USER_H
#define EXPEDIA_COM_USER_H

#include <string>
#include "PaymentCard.h"
using namespace std;

class User {
protected:
    string user_name;
    string password;
    string name;
    string email;

public:
    User(const User&) = delete;
    void operator=(const User&) = delete;

    User() {
    }

    virtual ~User() {
    }
    virtual void AddPaymentCard(const PaymentCard& card) = 0;

    string ToString() const {
        ostringstream oss;
        oss << "Name: " << user_name;
        oss << "\n";
        oss << "Email: " << email << "\n";
        oss << "User name: " << user_name << "\n";
        return oss.str();
    }

    void Read(const string &user_name) {
        SetUserName(user_name);

        string str;

        cout << "Enter password: ";
        cin >> str;
        SetPassword(str);

        cout << "Enter name: ";
        cin >> str;
        SetName(str);

        cout << "Enter email: ";
        cin >> str;
        SetEmail(str);
    }

    const string& GetEmail() const {
        return email;
    }

    void SetEmail(const string& email) {
        this->email = email;
    }

    const string& GetName() const {
        return name;
    }

    void SetName(const string& name) {
        this->name = name;
    }

    const string& GetPassword() const {
        return password;
    }

    void SetPassword(const string& password) {
        this->password = password;
    }

    const string& GetUserName() const {
        return user_name;
    }

    void SetUserName(const string& userName) {
        user_name = userName;
    }

};

#endif //EXPEDIA_COM_USER_H
