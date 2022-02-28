// директива препроцессора
#ifndef Ochered_h
#define Ochered_h
#include <iostream>


class Ochered
{
private:
    int xx;                              //Данные очереди
public:
    Ochered* Next;                       //Указатель не следующее звено
    int x = xx;

protected:
    Ochered* Head, * Tail;                     //Указатели на начало списка и на конец

public:
    Ochered() :Head(NULL), Tail(NULL) {};    //Инициализация указателей как пустых
    ~Ochered();                              //Деструктор для освобождения памяти 
    void setAdd(int x);                      //Функция добавления элемента в очередь
    void getShow();                          //Функция отображения очереди
    void getRemove();                        //Функция удаления элемента
    Ochered(const Ochered& obj);
    Ochered& operator = (const Ochered& obj);
};

// Заканчиваем директивой препроцессора
#endif