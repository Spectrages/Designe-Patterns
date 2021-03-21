#include <iostream>
#include <vector>

using namespace std;

class Chair
{
public:
    virtual void info() = 0;
    virtual ~Chair(){}
};

class Sofa
{
public:
    virtual void info() = 0;
    virtual ~Sofa(){}
};

class Table
{
public:
    virtual void info() = 0;
    virtual ~Table(){}
};

class ModernChair:public Chair
{
    void info()
    { cout << "I create Modern chair\n"; }
};

class ModernTable:public Table
{
    void info()
    { cout << "I create Modern table\n"; }
};

class ModernSofa:public Sofa
{
    void info()
    { cout << "I create Modern sofa\n"; }
};

class VicChair:public Chair
{
    void info()
    { cout << "I create Victorian chair\n"; }
};

class VicTable:public Table
{
    void info()
    { cout << "I create Victorian table\n"; }
};

class VicSofa:public Sofa
{
public:
    void info()
    { cout << "I create Victorian sofa\n"; }
};

class OldChair:public Chair
{
public:
    void info()
    { cout << "I create Old chair\n"; }
};

class OldSofa:public Sofa
{
public:
    void info()
    { cout << "I create Old sofa\n"; }
};

class OldTable:public Table
{
public:
    void info()
    { cout << "I create Old table\n"; }
};

class FurnitureFactory
{
public:
    virtual Chair* createChair() = 0;
    virtual Sofa* createSofa() = 0;
    virtual Table* createTable() = 0;
    virtual ~FurnitureFactory() {}
};

class ModernFactory:public FurnitureFactory
{
public:
    Chair *createChair()
    { return new ModernChair; }
    Sofa *createSofa()
    { return new ModernSofa; }
    Table *createTable()
    { return new ModernTable; }
};

class VictorianFactory:public FurnitureFactory
{
public:
    Chair *createChair()
    { return new VicChair; }
    Sofa *createSofa()
    { return new VicSofa; }
    Table *createTable()
    { return new VicTable; }
};

class OldFactory:public FurnitureFactory
{
public:
    Chair *createChair()
    { return new OldChair; }
    Sofa *createSofa()
    { return new OldSofa; }
    Table *createTable()
    { return new OldTable; }
};

class Furnitures
{
public:
    vector<Chair*> vecCh;
    vector<Sofa*> vecSf;
    vector<Table*> vecTb;
    ~Furnitures()
    {
        for(size_t i = 0; i < vecCh.size(); ++i) delete vecCh[i];
        for(size_t i = 0; i < vecSf.size(); ++i) delete vecSf[i];
        for(size_t i = 0; i < vecTb.size(); ++i) delete vecTb[i];
    }
    void info()
    {
        for(size_t i = 0; i < vecCh.size(); ++i) vecCh[i]->info();
        for(size_t i = 0; i < vecSf.size(); ++i) vecSf[i]->info();
        for(size_t i = 0; i < vecTb.size(); ++i) vecTb[i]->info();
    }
};

class Create
{
public:
    Furnitures* createFur(FurnitureFactory& factory)
    {
        Furnitures *p = new Furnitures;
        p->vecCh.push_back(factory.createChair());
        p->vecSf.push_back(factory.createSofa());
        p->vecTb.push_back(factory.createTable());
        return p;
    }
};

int main()
{
    Create create;
    ModernFactory mod_fa;
    VictorianFactory vic_fa;
    OldFactory old_fa;

    Furnitures *mod = create.createFur(mod_fa);
    Furnitures *vic = create.createFur(vic_fa);
    Furnitures *old = create.createFur(old_fa);
    cout << "Modern factory: \n";
    mod->info();
    cout << "Victorian factory: \n";
    vic->info();
    cout << "Old factory: ";
    old->info();
    return 0;
}
