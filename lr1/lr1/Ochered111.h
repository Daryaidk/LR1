#include <iostream>
#ifndef Ochered111_h
#define Ochered111_h
#include "Ochered.h"
class Ochered111 :private Ochered
{
public:
    void getCalculate();

private:
    int x;                              //������ �������
public:
    Ochered111* Next;                       //��������� �� ��������� �����

protected:
    Ochered111* Head, * Tail;                     //��������� �� ������ ������ � �� �����

public:
    Ochered111() :Head(NULL), Tail(NULL) {};    //������������� ���������� ��� ������
    ~Ochered111();                              //���������� ��� ������������ ������ 
    void setAdd(int x);                      //������� ���������� �������� � �������
    void getShow();                          //������� ����������� �������
    void getRemove();                        //������� �������� ��������
    Ochered111(const Ochered111& obj);
    Ochered111& operator = (const Ochered111& obj);
};
#endif