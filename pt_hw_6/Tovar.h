#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <assert.h>

using namespace std;
struct Money
{
	double amount = 0;
	string currency = " ";
	friend ostream& operator <<(ostream& os, Money& t);
};
class Tovar
{
protected:
	string name;
	Money price;
	int quantity;
	string measure;
public:
	Tovar(){}
	Tovar(string _name,  string _measure, double pr);
	Tovar(string _name, Money _price, int _quantity, string _measure);
	void Set_price(double num);
	void Set_quantit(int q);
	Money Get_price();
	void Print(int n);
	double Sum(double d);
};
class Bread: public Tovar
{
public:
	Bread(){}
	Bread(string _name, string _measure, double pr);
	Bread(string _name, Money _price, int _quantity, string _measure);
};
class Milk : public Tovar
{
public:
	Milk() {}
	Milk(string _name, string _measure, double pr);
	Milk(string _name, Money _price, int _quantity, string _measure);
};
class Potato : public Tovar
{
public:
	Potato() {}
	Potato(string _name, string _measure, double pr);
	Potato(string _name, Money _price, int _quantity, string _measure);
};
void Show_h();

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual Money getRub() = 0;
	virtual Money getUsd() = 0;
};

class AdapterR : public Sensor
{
private:
	Tovar* p_t;
public:
    AdapterR(Tovar* p) : p_t(p) { } //or -  p_t=p;
    ~AdapterR() {
        delete p_t;
    }
    Money getRub()
	{
		Money tmp;
		tmp.amount = p_t->Get_price().amount* 2.04;
		tmp.currency = "RUB";
        return tmp;
    }
	Money getUsd()
	{
		Money tmp;
		tmp.amount = p_t->Get_price().amount * 0.027034;
		tmp.currency = "USD";
		return tmp;
	}
};
