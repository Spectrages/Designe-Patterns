#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

enum TransportID {TruckID = 0, ShipID, PlaneID};

class Logistic
{
public:
    virtual void Info() = 0;
    virtual ~Logistic() {}
    static Logistic* CreateTransport(TransportID ID);
};

class Truck: public Logistic
{
public:
    void Info()
    { cout << "Truck\n"; }
};

class Ship: public Logistic
{
public:
    void Info()
    { cout << "Ship\n"; }
};

class Plane: public Logistic
{
public:
    void Info()
    { cout << "Plane\n"; }
};

Logistic* Logistic::CreateTransport(TransportID ID)
{
    Logistic* p;
    switch(ID)
    {
    case TruckID:
        p = new Truck();
        break;

    case ShipID:
        p = new Ship();
        break;

    case PlaneID:
        p = new Plane();
        break;

    default:
        assert(false);
    }
    return p;
}

int main()
{
    vector<Logistic*> log;
    log.push_back(Logistic::CreateTransport(TruckID));
    log.push_back(Logistic::CreateTransport(ShipID));
    log.push_back(Logistic::CreateTransport(PlaneID));

    for(size_t i = 0; i < log.size(); i++)
    {
        log[i]->Info();
    }

    return 0;
}

