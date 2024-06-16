#ifndef EXPEDIA_COM_PAYMENTCARD_H
#define EXPEDIA_COM_PAYMENTCARD_H

#include <bits/stdc++.h>
using namespace std;

class PaymentCard{
protected:
    string owner_name;
    string card_number;
    string expiry_date;
    int security_code;
    int balance = 10000;
public:
    const string& GetCardNumber() const {
        return card_number;
    }

    void SetCardNumber(const string& cardNumber) {
        card_number = cardNumber;
    }

    const string& GetExpiryDate() const {
        return expiry_date;
    }

    void SetExpiryDate(const string& expiryDate) {
        expiry_date = expiryDate;
    }

    const string& GetOwnerName() const {
        return owner_name;
    }

    void SetOwnerName(const string& ownerName) {
        owner_name = ownerName;
    }

    int GetSecurityCode() const {
        return security_code;
    }

    void SetSecurityCode(int securityCode) {
        security_code = securityCode;
    }

    virtual string ToString() const {
        ostringstream oss;
        oss << "Owner: " << owner_name << " Card number: " << card_number << " Expiry date: " << expiry_date;
        return oss.str();
    }

    virtual PaymentCard* Clone() const = 0;

    virtual bool ChargeCost(const double &cost) = 0;

    virtual ~PaymentCard() {
    }
};

class DebitCard : public PaymentCard{
protected:
    string billing_address;
public:
    const string& GetBillingAddress() const {
        return billing_address;
    }

    void SetBillingAddress(const string& billingAddress) {
        billing_address = billingAddress;
    }

    virtual PaymentCard *Clone() const override{
        return new DebitCard(*this);
    }

    virtual bool ChargeCost(const double &cost) override{
        if(cost <= balance){
            balance-=cost;
            return true;
        }
        else
            return false;
    }

    virtual string ToString() const {
        ostringstream oss;
        oss << "[Debit Card]: " << PaymentCard::ToString() << " Billing Address: " << billing_address;
        return oss.str();
    }
};

class CreditCard : public PaymentCard{
protected:

public:
    virtual PaymentCard* Clone() const override{
        return new CreditCard(*this);
    }
    virtual string ToString(){
        ostringstream oss;
        oss << "[Credit Card]: " << PaymentCard::ToString();
        return oss.str();
    }

    virtual bool ChargeCost(const double &cost) override{
        if(cost <= balance){
            balance-=cost;
            return true;
        }
        else
            return false;
    }

};

#endif //EXPEDIA_COM_PAYMENTCARD_H
