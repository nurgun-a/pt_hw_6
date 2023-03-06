#include "Tovar.h"

Tovar::Tovar(string _name, string _measure, double pr)
{
	name = _name; 
	measure = _measure; 
	price.currency = "UAH";
	price.amount = pr;
	quantity = 0;
}

Tovar::Tovar(string _name, Money _price, int _quantity, string _measure)
{
	name = _name; price = _price; quantity = _quantity; measure = _measure;
}

void Tovar::Set_price(double num)
{
	price.amount = num;
}

void Tovar::Set_quantit(int q)
{
	if (q<=0)
	{
		cout << "Error input" << endl;
	}
	else quantity = q;
}

Money Tovar::Get_price()
{
	return price;
}

void Tovar::Print(int n)
{
	Sensor* pr = new AdapterR(this);
	Money tmp;
	if (n==1)
	{
		tmp = pr->getUsd();
		cout << setw(13) << name << setw(10) << tmp << setw(10) << measure << setw(10) << quantity 
			<< setw(10)<< Sum(tmp.amount) << " USD" << endl;
	}
	else if(n==2)
	{
		tmp=pr->getRub();
		cout << setw(13) << name  << setw(10) << tmp << setw(10) << measure << setw(10) << quantity << setw(10)<< Sum(tmp.amount) << " RUB" <<endl;
	}
	else
	{
		cout << setw(13) << name  << setw(10) << price << setw(10) << measure << setw(10) << quantity << setw(10)<<Sum(price.amount)<<" UAH" << endl;
	}
	
}

double Tovar::Sum(double d)
{
	return d * quantity;
}

Bread::Bread(string _name, string _measure, double pr):Tovar(_name,_measure, pr){}

Bread::Bread(string _name, Money _price, int _quantity, string _measure):
	Tovar(_name,_price,_quantity, _measure){}

Milk::Milk(string _name, string _measure, double pr):Tovar(_name,_measure,pr){}

Milk::Milk(string _name, Money _price, int _quantity, string _measure):
	Tovar(_name, _price, _quantity, _measure) {}

Potato::Potato(string _name, string _measure, double pr):Tovar(_name,_measure,pr){}

Potato::Potato(string _name, Money _price, int _quantity, string _measure):
	Tovar(_name, _price, _quantity, _measure) {}

ostream& operator<<(ostream& os, Money& t)
{
	os << t.amount << " " << t.currency;
	return os;
}

void Show_h()
{	
	cout << setw(15) << "Наименование |"  << setw(14) << "Цена   |" << setw(11) << "ед. изм|"
		<< setw(13) << "Кол.-во  |" << setw(15) << "Сумма    |" << endl;
	cout << "-------------------------------------------------------------------" << endl;
}
