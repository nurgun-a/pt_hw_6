#include "Tovar.h"
#include "House.h"

void main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char key = ' ';
    bool key_1 = 1;
    int num = 0, num1 = 0, num2=0;

    CompositeHouse* house = new CompositeHouse;

    house->addObj(CreatHouse1());
    cout << "����� ��������� ���� "<< house->getSum() << " ������" << endl;
    system("pause");
    house->ClearH();
    house->addObj(MyHouse());
    cout << "����� ��������� ���� " << house->getSum() << " ������" << endl;
    system("pause");
    // �
    delete house;

    vector <Tovar> t1
    { 
        Milk("������", "����", 45.58),
        Bread("����", "�����",23.44),
        Potato("��������", "��",33.80)
    };    
    do
    {
        system("cls");
        Show_h();
        for (auto v : t1)
        {
            v.Print(num);
        }
        cout << endl;
        cout << "1 - ������� � ������ ������" << endl;
        cout << "2 - ������ ����������" << endl;
        cout << "0 - �����" << endl;

        cout << "Enter :"; cin >> key;
        switch (key)
        {
        case '1':
        {
            cout << endl;
            cout << "1 - ������� � ��������\n2 - ������� � ������\n����� ������ ����� ����� ������� � �������" << endl;
            cout << "Enter :"; cin >> num;
        }break;
        case '2':
        {
            cout << "1 - ������" << endl;
            cout << "2 - ����" << endl;
            cout << "3 - ��������" << endl;
            cout << "Enter :"; cin >> num1;
            cout << "������� ���.-�� :"; cin >> num2;
            if (num1>0&&num1<4&&num2>0)
            {
                t1[num1 - 1].Set_quantit(num2);
            }
            else
            {
                cout << "������ �����" << endl;
                system("pause");
                break;
            }
        }break;
        case '0':
        {
            key_1 = 0;
        }break;
        default:
            cout << "������ �����" << endl;
            system("pause");
            break;
        }
    } while (key_1);
}