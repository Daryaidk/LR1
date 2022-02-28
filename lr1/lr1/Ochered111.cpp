#include <cstddef>
#include <iostream>
#include "Ochered111.h"
using namespace std;

void Ochered111::getCalculate() {

    int count = 0;
    Ochered111* temp = Head;             //��������� ��������� �� ������ ������
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

//���������� ��� ������� ������
Ochered111::~Ochered111()
{
    Ochered111* temp = Head;               //��������� ��������� �� ������ ������
    while (temp != NULL)                   //���� � ������ ���-�� ����
    {
        temp = Head->Next;                 //������ ������ �� ��������� ������� ������
        delete Head;                       //������������ ������ 
        Head = temp;                       //����� ������ �� ��������� �����, ������� ����� �� �������
    }
}

//������� ���������� �������������� ����� ������ � ���������� � ������ 
void Ochered111::setAdd(int x)
{
    Ochered111* temp = new Ochered111;     //��������� ������ ��� ������ ����� ������
    temp->x = x;                          //��������� ����������� ��������� ��������� x
    temp->Next = NULL;                    //��������, ��� ��������� ����� ���� ������

    if (Head != NULL)                     //���� ������ �� ����
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;              //���� ������ �� ����, ���������� ������� ��������
}

//������� �������� �������� �� �������
void Ochered111::getRemove()
{
    if (Head != NULL)                   //���� ������ �� ������
    {
        Ochered111* temp = Head;           //���������� � ������ ������ � ������� ���������������� ���������
        Head = Head->Next;              //����� ������ ������
        delete temp;                    //������������ ������ �� ����������� ����� ������
    }
}

Ochered111::Ochered111(const Ochered111& obj)
{
    Ochered111* temp = obj.Head;
    Ochered111* tempp = obj.Head;
    while (temp)
    {
        setAdd(temp->x);
        temp = temp->Next;
    }
    while (tempp)
    {
        setAdd(tempp->x);
        tempp = tempp->Next;
    }

}

Ochered111& Ochered111::operator=(const Ochered111& obj)
{
    if (this != &obj)
    {
        Ochered111* temp = Head;
        while (temp)
        {
            Head = Head->Next;
            delete temp;
            temp = Head;
        }

        temp = obj.Head;
        while (temp)
        {
            setAdd(temp->x);
            temp = temp->Next;
        }
    }
    return *this;
}

//������� ������ �� ����� ������
void Ochered111::getShow()
{
    Ochered111* temp = Head;                //��������� ��������� �� ������ ������
    while (temp != NULL)                 //���� � ������ ���-�� �����������
    {
        cout << temp->x << " ";          //������� �������� �� ������ �� �����
        temp = temp->Next;               //�������� ��������� �� ������ �� ����� ���������� ��������
    }
    cout << endl;
}