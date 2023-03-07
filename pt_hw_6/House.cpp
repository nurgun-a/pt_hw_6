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
	cout << "������� ������ 1 ����� (������ ����� 3 �����): "; cin >> num1; cout << endl;
	cout << "������� ������ 2 ����� (������ ����� 3 �����): "; cin >> num2; cout << endl;

	num3 = ((num1*3) + (num2*3)) * 2;

	cout << num3<< " ���������� ������ �����"<<endl;
	cout << num1*num2 << " ���������� ������ �����" << endl;
	for (int i = 0; i < num3; i++) { Myhome->addObj(new Wall); }
	for (int i = 0; i < num1*num2; i++) { Myhome->addObj(new Roof); }
	
	Myhome->addObj(new Door);
	cout << "������� ���������� ������������ ������: "; cin >> num1; cout << endl;
	for (int i = 0; i < num1; i++)
	{
		Myhome->addObj(new MDoor);
	}
	cout << "������� ���������� ����: "; cin >> num1; cout << endl;
	for (int i = 0; i < num1; i++)
	{
		Myhome->addObj(new Window);
	}
	return Myhome;
}