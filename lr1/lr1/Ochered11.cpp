#include <cstddef>
#include <iostream>
#include "Ochered11.h"
using namespace std;

void Ochered11::getCalculate_2() {

    int count = 0;
    Ochered* temp = Head;                //��������� ��������� �� ������ ������
    while (temp != NULL)                 //���� � ������ ���-�� �����������
    {
        if (temp->x % 2 != 0)            //���� ������� �� ������� ��� ������� �� 2, ���������� � �������� 1
        {
            count = count + 1;
        }
        temp = temp->Next;
    }
    cout << "���������� �������� ���������: " << count;          //������� ���������� �������� ��������� ���������
}

void Ochered11::setAdd_2(int x) {

    Ochered* temp = new Ochered;      //��������� ������ ��� ������ ����� ������
    temp->x = x;                          //��������� ����������� ��������� ��������� x
    temp->Next = NULL;                    //��������, ��� ��������� ����� ���� ������

    if (Head != NULL)                     //���� ������ �� ����
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;              //���� ������ �� ����, ���������� ������� ��������
}

void Ochered11::getRemove_2()
{
    if (Head != NULL)                   //���� ������ �� ������
    {
        Ochered* temp = Head;           //���������� � ������ ������ � ������� ���������������� ���������
        Head = Head->Next;              //����� ������ ������
        delete temp;                    //������������ ������ �� ����������� ����� ������
    }
}