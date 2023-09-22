#include <bits/stdc++.h>
using namespace std;

int readInt(int low, int high, bool cancel = false){
    cout << "\nEnter number in range " << low << " - " << high << ": ";
    int choice; cin >> choice;
    if(cancel && choice == -1)
        return choice;
    if (low <= choice && choice <= high)
        return choice;
    cout << "ERROR: invalid number...Try again\n";
    return readInt(low, high);
}

int readmenu(const vector<string> &choices, string header = "Menu") {
    cout << "\n"<<header<<":\n";
    for (int ch = 0; ch < (int) choices.size(); ++ch) {
        cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
    }
    return readInt(1, choices.size());
}

string return_current_time_and_date(){
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

class Reservation{
public:
    virtual Reservation* Clone()const = 0;
    virtual double TotalCost() const = 0;
    virtual string ToString() const = 0;
    virtual ~Reservation(){}
};

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

class ReservationsSet: public ItineraryReservation {
public:
    using ItineraryReservation::ItineraryReservation;

    virtual Reservation* Clone() const {
        return new ReservationsSet(*this);
    }
};

class AirCanadaFlight {
public:
    double price;
    string date_time_from;
    string date_time_to;
};

class AirCanadaOnlineAPI{
public:
    static vector<AirCanadaFlight> GetFlights(string from, string from_date, string to, string to_date, int adults, int childern) {
        vector<AirCanadaFlight> flights;

        flights.push_back( { 200, "16-08-2023", "25-08-2023" });
        flights.push_back( { 250, "16-08-2023", "25-08-2023" });
        return flights;
    }
};

class TurkishFlight{
public:
    double cost;
    string datetime_from;
    string datetime_to;
};

class TurkishAirlinesOnlineAPI{
public:
    void SetFromToInfo(string datetime_from, string from, string datetime_to, string to) {
    }
    void SetPassengersInfo(int infants, int childern, int adults) {
    }
    vector<TurkishFlight> GetAvailableFlights() const {
        vector<TurkishFlight> flights;

        flights.push_back( { 300, "16-08-2023", "25-08-2023" });
        flights.push_back( { 320, "16-08-2023", "25-08-2023" });
        return flights;
    }
};

class Flight{
private:
    string airline_name;
    double total_cost = 0;
    string date_time_from;
    string date_time_to;
public:
    string ToString() const{
        ostringstream oss;
        oss << "Airline: " << airline_name << " Cost: " << total_cost << " From: " << date_time_from << " To: " << date_time_to;
        return oss.str();
    }
    const string& GetDateTimeFrom() const {
        return date_time_from;
    }

    void SetDateTimeFrom(const string& dateTimeFrom) {
        date_time_from = dateTimeFrom;
    }

    const string& GetDateTimeTo() const {
        return date_time_to;
    }

    void SetDateTimeTo(const string& dateTimeTo) {
        date_time_to = dateTimeTo;
    }

    double GetTotalCost() const {
        return total_cost;
    }

    void SetTotalCost(double totalCost) {
        total_cost = totalCost;
    }

    const string& GetAirlineName() const {
        return airline_name;
    }

    void SetAirlineName(const string& airlineName) {
        airline_name = airlineName;
    }
};

class FlightRequest{
private:
    string datetime_from;
    string from;
    string datetime_to;
    string to;
    int infants;
    int childern;
    int adults;
public:
    string GetDatePartFrom() const {
        return datetime_from;	// extract date only
    }

    string GetDatePartTo() const {
        return datetime_to;	// extract date only
    }

    int GetAdults() const {
        return adults;
    }

    void SetAdults(int adults) {
        this->adults = adults;
    }

    int GetChildren() const {
        return childern;
    }

    void SetChildren(int childern) {
        this->childern = childern;
    }

    const string& GetDatetimeFrom() const {
        return datetime_from;
    }

    void SetDatetimeFrom(const string& datetimeFrom) {
        datetime_from = datetimeFrom;
    }

    const string& GetDatetimeTo() const {
        return datetime_to;
    }

    void SetDatetimeTo(const string& datetimeTo) {
        datetime_to = datetimeTo;
    }

    const string& GetFrom() const {
        return from;
    }

    void SetFrom(const string& from) {
        this->from = from;
    }

    int GetInfants() const {
        return infants;
    }

    void SetInfants(int infants) {
        this->infants = infants;
    }

    const string& GetTo() const {
        return to;
    }

    void SetTo(const string& to) {
        this->to = to;
    }
};

class FlightReservation : public Reservation{
private:
    FlightRequest request;
    Flight flight;
public:
    FlightReservation(const FlightRequest &request, const Flight &flight) :
            request(request), flight(flight) {
    }

    virtual FlightReservation* Clone() const override {
        return new FlightReservation(*this);
    }

    virtual double TotalCost() const override {
        return flight.GetTotalCost();
    }

    virtual string ToString() const override {
        ostringstream oss;
        oss << "Airline reservation with reservation: " << flight.GetAirlineName() << ": From " << request.GetFrom() << " on " << request.GetDatetimeFrom() << "\n";
        oss << "\tTo " << request.GetTo() << " on " << request.GetDatetimeTo() << "\n";
        oss << "\t" << "Adults: " << request.GetAdults() << " children: " << request.GetChildren() << " infants: " << request.GetInfants() << "\n";
        oss << "\tTotal Cost:" << TotalCost() << "\n";

        return oss.str();
    }

    const Flight& GetFlight() const {
        return flight;
    }

    const FlightRequest& GetRequest() const {
        return request;
    }
};

class IFlighsManager{
protected:
    FlightRequest request;
public:
    virtual void SetFlightRequest(const FlightRequest &request_) {
        request = request_;
    }
    virtual vector<Flight> SearchFlights() const = 0;
    virtual string GetName() const = 0;
    virtual ~IFlighsManager(){}
};

class AirCanadaFlighsManager : public IFlighsManager{
public:
    virtual string GetName() const{
        return "AirCanada Airlines";
    }

    virtual vector<Flight> SearchFlights() const override{
        vector<AirCanadaFlight> api = AirCanadaOnlineAPI::GetFlights(request.GetFrom(), request.GetDatePartFrom(), request.GetTo(), request.GetDatePartTo(), request.GetAdults(), request.GetChildren());
        vector<Flight> flights;
        for(auto &f : api){
            Flight flight;
            flight.SetAirlineName(GetName());
            flight.SetTotalCost(f.price);
            flight.SetDateTimeFrom(f.date_time_from);
            flight.SetDateTimeTo(f.date_time_to);

            flights.push_back(flight);
        }
        return flights;
    }
};

class TurkishFlighsManager: public IFlighsManager{
public:
    virtual string GetName() const{
        return "Turkish Airlines";
    }

    virtual vector<Flight> SearchFlights() const override{
        TurkishAirlinesOnlineAPI api;
        vector<TurkishFlight> fl = api.GetAvailableFlights();
        vector<Flight> flights;
        for(auto &f : fl){
            Flight flight;
            flight.SetAirlineName(GetName());
            flight.SetTotalCost(f.cost);
            flight.SetDateTimeFrom(f.datetime_from);
            flight.SetDateTimeTo(f.datetime_to);

            flights.push_back(flight);
        }
        return flights;
    }
};

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

class HiltonRoom{
public:
    string room_type;
    int available;
    double price_per_night;
    string date_from;
    string date_to;
};

class HiltonHotelAPI{
public:
    static vector<HiltonRoom> SearchRooms(string country, string city, string from_date, string to_date, int adults, int children, int needed_rooms) {
        vector<HiltonRoom> rooms;

        rooms.push_back( { "Interior View", 6, 200.0, "16-08-2023", "25-08-2023" });
        rooms.push_back( { "City View", 3, 300.0, "16-08-2023", "25-08-2023" });
        rooms.push_back( { "Deluxe View", 8, 500.0, "16-08-2023", "25-08-2023" });

        return rooms;
    }
};

class MarriottFoundRoom {
public:
    string room_type;
    int available;
    double price_per_night;
    string date_from;
    string date_to;
};

class MarriottHotelAPI {
public:
    static vector<MarriottFoundRoom> FindRooms(string from_date, string to_date, string country, string city, int needed_rooms, int adults, int children) {
        vector<MarriottFoundRoom> rooms;

        rooms.push_back( { "City View", 8, 320.0, "16-08-2023", "25-08-2023" });
        rooms.push_back( { "Interior View", 8, 220.0, "16-08-2023", "25-08-2023" });
        rooms.push_back( { "Private View", 5, 600.0, "16-08-2023", "25-08-2023" });

        return rooms;
    }
};

class HotelRoom{
private:
    string hotel_name;
    string room_type;
    int available_rooms = 0;
    double price_per_night = 0;
    string date_from;
    string date_to;
public:
    string ToString() const{
        ostringstream oss;
        oss << "Hotel Name: " << hotel_name << " Room Type: " << room_type << "(" << available_rooms << ")" << "Price per night: " << price_per_night << " From Date " << date_from << " to " << date_to << "";
        return oss.str();
    }
    const string& GetDateFrom() const {
        return date_from;
    }

    void SetDateFrom(const string& dateFrom) {
        date_from = dateFrom;
    }

    const string& GetDateTo() const {
        return date_to;
    }

    void SetDateTo(const string& dateTo) {
        date_to = dateTo;
    }

    double GetPricePerNight() const {
        return price_per_night;
    }

    void SetPricePerNight(double pricePerNight) {
        price_per_night = pricePerNight;
    }

    const string& GetRoomType() const {
        return room_type;
    }

    void SetRoomType(const string& roomType) {
        room_type = roomType;
    }

    int GetAvailableRooms() const {
        return available_rooms;
    }

    void SetAvailableRooms(int availableRooms = 0) {
        available_rooms = availableRooms;
    }

    const string& GetHotelName() const {
        return hotel_name;
    }

    void SetHotelName(const string& hotelName) {
        hotel_name = hotelName;
    }
};

class HotelRequest {
private:
    string from_date;
    string to_date;
    string country;
    string city;
    int rooms;
    int adults;
    int children;

public:
    int GetTotalNights() const {
        // Some date computations
        return 3;
    }
    int GetAdults() const {
        return adults;
    }

    void SetAdults(int adults) {
        this->adults = adults;
    }

    int GetChildren() const {
        return children;
    }

    void SetChildren(int children) {
        this->children = children;
    }

    const string& GetCity() const {
        return city;
    }

    void SetCity(const string& city) {
        this->city = city;
    }

    const string& GetCountry() const {
        return country;
    }

    void SetCountry(const string& country) {
        this->country = country;
    }

    const string& GetFromDate() const {
        return from_date;
    }

    void SetFromDate(const string& fromDate) {
        from_date = fromDate;
    }

    int GetRooms() const {
        return rooms;
    }

    void SetRooms(int rooms) {
        this->rooms = rooms;
    }

    const string& GetToDate() const {
        return to_date;
    }

    void SetToDate(const string& toDate) {
        to_date = toDate;
    }
};

class HotelReservation : public Reservation{
private:
    HotelRequest request;
    HotelRoom room;

public:
    HotelReservation(const HotelRequest &request, const HotelRoom &room) :
            request(request), room(room) {
    }

    virtual HotelReservation* Clone() const override{
        return new HotelReservation(*this);
    }

    virtual double TotalCost() const override{
        return room.GetPricePerNight()*request.GetTotalNights();
    }
    virtual string ToString() const override {
        ostringstream oss;
        oss << "Hotel reservation: " << room.GetHotelName() << ": " << request.GetCity() << " @ " << request.GetCountry() << "\n";
        oss << "\t" << request.GetFromDate() << " to " << request.GetToDate() << " : " << request.GetTotalNights() << "\n";
        oss << "\t" << "Adults: " << request.GetAdults() << " children " << request.GetChildren() << "\n";
        oss << "\tTotal Cost:" << TotalCost() << "\n";

        return oss.str();
    }

    const HotelRequest& GetRequest() const {
        return request;
    }

    const HotelRoom& GetRoom() const {
        return room;
    }
};

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

class ExpediaBackend{
private:
    vector<IFlighsManager*> flights_managers;
    vector<IHotelsManager*> hotels_managers;
public:
    ExpediaBackend(const ExpediaBackend&) = delete;
    void operator=(const ExpediaBackend&) = delete;

    ExpediaBackend(){
        flights_managers = FlightsFactory::GetManagers();
        hotels_managers = HotelsFactory::GetManagers();
    }

    vector<Flight> FindFlights(const FlightRequest& request_) const{
        vector<Flight> flights;
        for(auto *mgr : flights_managers){
            mgr->SetFlightRequest(request_);
            vector<Flight> more = mgr->SearchFlights();
            flights.insert(flights.end(), more.begin(), more.end());
        }
        return flights;
    }

    vector<HotelRoom> FindHotels(const HotelRequest& request_) const{
        vector<HotelRoom> rooms;
        for(auto *mgr : hotels_managers){
            mgr->SetHotelRequest(request_);
            vector<HotelRoom> more = mgr->SearchHotelRooms();
            rooms.insert(rooms.end(), more.begin(), more.end());
        }
        return rooms;
    }
};

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

    virtual ~User() {	// To allow dynamic casting, we need 1+ virtual function
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

class Customer: public User {
protected:
    vector<PaymentCard*> cards;
    ReservationsSet reservations;

public:
    Customer(const Customer&) = delete;
    void operator=(const Customer&) = delete;

    Customer() {

    }

    ~Customer() {
        for (PaymentCard* card : cards)
            delete card;
        cards.clear();
    }

    void AddPaymentCard(const PaymentCard& card) {
        cards.push_back(card.Clone());
    }

    void AddReservation(const Reservation& reservation) {
        reservations.AddReservation(*reservation.Clone());
    }

    const vector<PaymentCard*>& GetCards() const {
        return cards;
    }

    const ReservationsSet& GetReservations() const {
        return reservations;
    }
};

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

class CustomerView{
private:
    CustomerManager &customer_manager;
    const Customer& customer;
    ItineraryReservation current_itinerary;

    void ReadFlightRequest(FlightRequest &request) const{
        string str;
        int val;

        cout << "Enter From: ";
        cin >> str;
        request.SetFrom(str);

        cout << "Enter From Date (dd-mm-yy): ";
        cin >> str;
        request.SetDatetimeFrom(str);

        cout << "Enter To: ";
        cin >> str;
        request.SetTo(str);

        cout << "Enter To Date (dd-mm-yy): ";
        cin >> str;
        request.SetDatetimeTo(str);

        cout << "Enter # of adults children (5-16) and infants: ";
        cin >> val;
        request.SetAdults(val);
        cin >> val;
        request.SetChildren(val);
        cin >> val;
        request.SetInfants(val);
    }

    void ReadHotelRequest(HotelRequest &request) const{
        string str;
        int val;

        cout << "Enter From Date (dd-mm-yy): ";
        cin >> str;
        request.SetFromDate(str);

        cout << "Enter To Date (dd-mm-yy): ";
        cin >> str;
        request.SetToDate(str);

        cout << "Enter Country: ";
        cin >> str;
        request.SetCountry(str);

        cout << "Enter City: ";
        cin >> str;
        request.SetCity(str);

        cout << "Enter # of adults and children: ";
        cin >> val;
        request.SetAdults(val);
        cin >> val;
        request.SetChildren(val);
    }

    int ChooseFlight(const vector<Flight> &flights) const {
        if (flights.size() == 0) {
            cout << "No trips for this request info\n";
            return -1;
        }

        for (const Flight& flight : flights) {
            cout << flight.ToString() << "\n";
        }

        return readInt(1, flights.size(), true);
    }

    int ChooseRoom(const vector<HotelRoom> &rooms) const{
        if (rooms.size() == 0) {
            cout << "No trips for this request info\n";
            return -1;
        }

        for (const HotelRoom& room : rooms) {
            cout << room.ToString() << "\n";
        }

        return readInt(1, rooms.size(), true);
    }

    void AddFlight() {
        FlightRequest request;
        ReadFlightRequest(request);

        vector<Flight> flights = customer_manager.FindFlights(request);
        int flight_choice = ChooseFlight(flights);

        if (flight_choice == -1)
            return;

        Flight &flight = flights[flight_choice - 1];

        FlightReservation reservation(request, flight);
        current_itinerary.AddReservation(reservation);
    }

    void AddHotel() {
        HotelRequest request;
        ReadHotelRequest(request);

        vector<HotelRoom> rooms = customer_manager.FindHotels(request);
        int hotel_choice = ChooseRoom(rooms);

        if (hotel_choice == -1)
            return;

        HotelRoom &room = rooms[hotel_choice - 1];

        HotelReservation reservation(request, room);
        current_itinerary.AddReservation(reservation);
    }

    void PayItinerary() {
        vector<string> payment_choices = customer_manager.GetPaymentChoices();
        int payment_chocie = readmenu(payment_choices, "Select a payment choice");
        PaymentCard* payment_card = customer.GetCards()[payment_chocie - 1];

        bool status = customer_manager.MakeReservation(current_itinerary, *payment_card);

        if (status) {
            cout << "Itinerary reserved\n";
        } else
            cout << "Failed to reserve the Itinerary\n";
    }
public:
    CustomerView(CustomerManager &customer_manager) :
            customer_manager(customer_manager), customer(*customer_manager.GetCustomer()) {
    }

    void Display() {
        cout << "\n\nHello " << customer.GetName() << " | User View\n";

        vector<string> menu;
        menu.push_back("View Profile");
        menu.push_back("Make Itinerary");
        menu.push_back("List my itineraries");
        menu.push_back("Logout");

        while (true) {
            int choice = readmenu(menu);
            if (choice == 1)
                ViewProfile();
            else if (choice == 2)
                MakeItinerary();
            else if (choice == 3)
                ListItineraries();
            else
                break;
        }
    }
    void ViewProfile() const {
        cout << "\n" << customer.ToString() << "\n";
    }

    void MakeItinerary() {
        vector<string> menu;
        menu.push_back("Add Flight");
        menu.push_back("Add Hotel");
        menu.push_back("Done");
        menu.push_back("Cancel");

        while (true) {
            int choice = readmenu(menu);
            if (choice == 1)
                AddFlight();
            else if (choice == 2)
                AddHotel();
            else if (choice == 3) {
                PayItinerary();
                current_itinerary.Clear();
                break;
            } else {
                current_itinerary.Clear();
                break;
            }
        }
    }
    void ListItineraries() const {
        vector<string> itineraries = customer_manager.GetItineraries();

        if (itineraries.size() == 0) {
            cout << "No itineraries so far!\n";
        }

        for (string& str : itineraries)
            cout << str << "\n";
    }
};

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
                current_user->AddPaymentCard(*card);
            }
            else break;
        }
    }
    User* getcurrentuser() const{
        return current_user;
    }
};


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

int main() {
    ExpediaFrontend site;
    site.run();
    return 0;
}
