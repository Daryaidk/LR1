#include <cstddef>
#include <iostream>
#include "Ochered.h"
using namespace std;

//���������� ��� ������� ������
Ochered::~Ochered()
{
    Ochered* temp = Head;                  //��������� ��������� �� ������ ������
    while (temp != NULL)                   //���� � ������ ���-�� ����
    {
        temp = Head->Next;                 //������ ������ �� ��������� ������� ������
        delete Head;                       //������������ ������ 
        Head = temp;                       //����� ������ �� ��������� �����, ������� ����� �� �������
    }
}

//������� ���������� �������������� ����� ������ � ���������� � ������ 
void Ochered::setAdd(int x)
{
    Ochered* temp = new Ochered;          //��������� ������ ��� ������ ����� ������
    temp->x = x;                          //��������� ����������� ��������� ��������� x
    temp->Next = NULL;                    //��������, ��� ��������� ����� ���� ������

    if (Head != NULL)                     //���� ������ �� ����
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;              //���� ������ �� ����, ���������� ������� ��������
}

//������� ������ �� ����� ������
void Ochered::getShow()
{
    Ochered* temp = Head;                //��������� ��������� �� ������ ������
    while (temp != NULL)                 //���� � ������ ���-�� �����������
    {
        cout << temp->x << " ";          //������� �������� �� ������ �� �����
        temp = temp->Next;               //�������� ��������� �� ������ �� ����� ���������� ��������
    }
    cout << endl;
}

//������� �������� �������� �� �������
void Ochered::getRemove()
{
    if (Head != NULL)                   //���� ������ �� ������
    {
        Ochered* temp = Head;           //���������� � ������ ������ � ������� ���������������� ���������
        cout << "������� " << Head->x << " ������" << endl;
        Head = Head->Next;              //����� ������ ������
        delete temp;                    //������������ ������ �� ����������� ����� ������
    }
}


Ochered::Ochered(const Ochered& obj)
{
    Ochered* temp = obj.Head;
    while (temp)
    {
        setAdd(temp->x);
        temp = temp->Next;
    }
}

Ochered& Ochered::operator=(const Ochered& obj)
{
    if (this != &obj)
    {
        Ochered* temp = Head;
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