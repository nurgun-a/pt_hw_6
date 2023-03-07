#pragma once
#include "Tovar.h"

class House
{
public:
    virtual double getSum() = 0;
    virtual void addObj(House* p) { assert(false); }
    virtual ~House() {}
    virtual void ClearH(){}
};
class Wall : public House
{
public:
    virtual double getSum() { return 2700; }
};
class Window : public House
{
public:
    virtual double getSum() { return 3800; }
};
class Door : public House
{
public:
    virtual double getSum() { return 14500; }
};
class MDoor : public House
{
public:
    virtual double getSum() { return 2500; }
};
class Roof : public House
{
public:
    virtual double getSum() { return 3680; }
};

class CompositeHouse : public House
{
    vector <House*> h;
public:
    double getSum()
    {
        double total = 0;
        for (int i = 0; i < h.size(); ++i)
            total += h[i]->getSum();
        return total;
    }
    void addObj(House* h1) { h.push_back(h1); }
    void ClearH() { h.clear(); }
    ~CompositeHouse()
    {
        for (int i = 0; i < h.size(); ++i)
            delete h[i];
    }
};

CompositeHouse* CreatHouse1();
CompositeHouse* MyHouse();