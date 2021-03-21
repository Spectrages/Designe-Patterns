#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Pepperoni
{
public:
    void info()
    { cout << "Pepperoni\n"; }
};

class Cheese
{
public:
    void info()
    { cout << "Cheese\n"; }
};

class Tomatoes
{
public:
    void info()
    { cout << "Tomatoes\n"; }
};

class Pineapples
{
public:
    void info()
    { cout << "Pineapples\n"; }
};

class Pickles
{
public:
    void info()
    { cout << "Pickles\n"; }
};

class Pizza
{
public:
    vector<Pepperoni> vecPep;
    vector<Cheese> vecCh;
    vector<Tomatoes> vecTom;
    vector<Pineapples> vecPin;
    vector<Pickles> vecPic;
    void info()
    {
        for(size_t i = 0; i < vecPep.size(); ++i) vecPep[i].info();
        for(size_t i = 0; i < vecCh.size(); ++i) vecCh[i].info();
        for(size_t i = 0; i < vecTom.size(); ++i) vecTom[i].info();
        for(size_t i = 0; i < vecPin.size(); ++i) vecPin[i].info();
        for(size_t i = 0; i < vecPic.size(); ++i) vecPic[i].info();
    }
};

class PizzaBuilder
{
protected:
    Pizza *p;
public:
    PizzaBuilder():p(0) {}
    virtual ~PizzaBuilder() {}
    virtual void CreatePizza() {}
    virtual void addPepperoni() {}
    virtual void addCheese() {}
    virtual void addTomatoes() {}
    virtual void addPineapples() {}
    virtual void addPickles() {}

    virtual Pizza* getPizza() { return p; }
};

class PepperoniCheese:public PizzaBuilder
{
public:
    void CreatePizza() { p = new Pizza; }
    void addPepperoni() { p->vecPep.push_back(Pepperoni()); }
    void addCheese() { p->vecCh.push_back(Cheese()); }
};

class PepChPine:public PizzaBuilder
{
public:
    void CreatePizza() {p = new Pizza; }
    void addPepperoni() { p->vecPep.push_back(Pepperoni()); }
    void addCheese() { p->vecCh.push_back(Cheese()); }
    void addPineapples() { p->vecPin.push_back(Pineapples()); }
};

class CheeseTomatoes:public PizzaBuilder
{
public:
    void CreatePizza() {p = new Pizza; }
    void addCheese() { p->vecCh.push_back(Cheese()); }
    void addTomatoes() { p->vecTom.push_back(Tomatoes()); }
};

class FullPizza:public PizzaBuilder
{
public:
    void CreatePizza() {p = new Pizza; }
    void addPepperoni() { p->vecPep.push_back(Pepperoni()); }
    void addCheese() { p->vecCh.push_back(Cheese()); }
    void addTomatoes() { p->vecTom.push_back(Tomatoes()); }
    void addPineapples() { p->vecPin.push_back(Pineapples()); }
    void addPickles() { p->vecPic.push_back(Pickles()); }
};

class Director
{
public:
    Pizza* createPizza(PizzaBuilder &chef)
    {
        chef.CreatePizza();
        chef.addPepperoni();
        chef.addPickles();
        chef.addPineapples();
        chef.addTomatoes();
        chef.addCheese();

        return (chef.getPizza());
    }

};
void ChoisePizza();

int main()
{
    ChoisePizza();
    return 0;
}

void ChoisePizza()
{
    Director dir;
    PepperoniCheese pc;
    PepChPine pcp;
    CheeseTomatoes ct;
    FullPizza fp;
    Pizza *pcz = dir.createPizza(pc);
    Pizza *pcpz = dir.createPizza(pcp);
    Pizza *ctz = dir.createPizza(ct);
    Pizza *fpz = dir.createPizza(fp);
    char ch;
    do
    {
        cout << "Menu: \n";
        cout << "1. Pizza 1;\n2. Pizza 2;\n3. Pizza 3;\n4. Pizza 4;\nChoise: ";
        int ans;
        cin >> ans;
        cout << '\n';
        switch (ans)
        {
        case 1:
            pcz->info();
            break;
        case 2:
            pcpz->info();
            break;
        case 3:
            ctz->info();
            break;
        case 4:
            fpz->info();
            break;
        default:
            assert(false);
        }
        cout << "\nContinue? (y/n): ";
        cin >> ch;
    }
    while(ch != 'n');
}
