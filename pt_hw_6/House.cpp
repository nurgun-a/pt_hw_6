#include "House.h"

CompositeHouse* CreatHouse1()
{
	CompositeHouse* Myhome = new CompositeHouse;
	for (int i = 0; i < 84; i++)
	{
		Myhome->addObj(new Wall);
	}
	for (int i = 0; i < 4; i++)
	{
		Myhome->addObj(new Window);
	}

	Myhome->addObj(new Door);

	for (int i = 0; i < 4; i++)
	{
		Myhome->addObj(new MDoor);
	}
	for (int i = 0; i < 49; i++)
	{
		Myhome->addObj(new Roof);
	}
	return Myhome;
}

CompositeHouse* MyHouse()
{
	CompositeHouse* Myhome = new CompositeHouse;
	int num1, num2, num3;
	cout << "Введите ширину 1 стены (Высота будет 3 метра): "; cin >> num1; cout << endl;
	cout << "Введите ширину 2 стены (Высота будет 3 метра): "; cin >> num2; cout << endl;

	num3 = ((num1*3) + (num2*3)) * 2;

	cout << num3<< " квадратных метров стены"<<endl;
	cout << num1*num2 << " квадратных метров крыши" << endl;
	for (int i = 0; i < num3; i++) { Myhome->addObj(new Wall); }
	for (int i = 0; i < num1*num2; i++) { Myhome->addObj(new Roof); }
	
	Myhome->addObj(new Door);
	cout << "Введите количество межкомнатных дверей: "; cin >> num1; cout << endl;
	for (int i = 0; i < num1; i++)
	{
		Myhome->addObj(new MDoor);
	}
	cout << "Введите количество окон: "; cin >> num1; cout << endl;
	for (int i = 0; i < num1; i++)
	{
		Myhome->addObj(new Window);
	}
	return Myhome;
}