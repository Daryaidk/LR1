#include <iostream>
#ifndef Ochered111_h
#define Ochered111_h
#include "Ochered.h"
class Ochered111 :private Ochered
{
public:
    void getCalculate();

private:
    int x;                              //Данные очереди
public:
    Ochered111* Next;                       //Указатель не следующее звено

protected:
    Ochered111* Head, * Tail;                     //Указатели на начало списка и на конец

public:
    Ochered111() :Head(NULL), Tail(NULL) {};    //Инициализация указателей как пустых
    ~Ochered111();                              //Деструктор для освобождения памяти 
    void setAdd(int x);                      //Функция добавления элемента в очередь
    void getShow();                          //Функция отображения очереди
    void getRemove();                        //Функция удаления элемента
    Ochered111(const Ochered111& obj);
    Ochered111& operator = (const Ochered111& obj);
};
#endif