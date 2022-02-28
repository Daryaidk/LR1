// ��������� �������������
#ifndef Ochered_h
#define Ochered_h
#include <iostream>


class Ochered
{
private:
    int xx;                              //������ �������
public:
    Ochered* Next;                       //��������� �� ��������� �����
    int x = xx;

protected:
    Ochered* Head, * Tail;                     //��������� �� ������ ������ � �� �����

public:
    Ochered() :Head(NULL), Tail(NULL) {};    //������������� ���������� ��� ������
    ~Ochered();                              //���������� ��� ������������ ������ 
    void setAdd(int x);                      //������� ���������� �������� � �������
    void getShow();                          //������� ����������� �������
    void getRemove();                        //������� �������� ��������
    Ochered(const Ochered& obj);
    Ochered& operator = (const Ochered& obj);
};

// ����������� ���������� �������������
#endif