#include <cstddef>
#include <iostream>
#include "Ochered1.h"
using namespace std;

void Ochered1::getCalculate() {

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
    cout << "���������� �������� ���������: " << count;          //������� ���������� �������� ��������� �������
}