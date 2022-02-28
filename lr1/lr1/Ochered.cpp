#include <cstddef>
#include <iostream>
#include "Ochered.h"
using namespace std;

//деструктор для очистки памяти
Ochered::~Ochered()
{
    Ochered* temp = Head;                  //Временный указатель на начало списка
    while (temp != NULL)                   //Пока в списке что-то есть
    {
        temp = Head->Next;                 //Резерв адреса на следующий элемент списка
        delete Head;                       //Освобождение памяти 
        Head = temp;                       //Сдвиг начала на следующий адрес, который берем из резерва
    }
}

//функция заполнения информационных полей класса и добавление в список 
void Ochered::setAdd(int x)
{
    Ochered* temp = new Ochered;          //Выделение памяти для нового звена списка
    temp->x = x;                          //Временное запоминание принятого параметра x
    temp->Next = NULL;                    //Указание, что следующее звено пока пустое

    if (Head != NULL)                     //Если список не пуст
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;              //Если список не пуст, добавление первого элемента
}

//функция вывода на экран списка
void Ochered::getShow()
{
    Ochered* temp = Head;                //Временный указатель на начало списка
    while (temp != NULL)                 //Пока в списке что-то встречается
    {
        cout << temp->x << " ";          //Выводим значения из списка на экран
        temp = temp->Next;               //Сдвигаем указатель на начало на адрес следующего элемента
    }
    cout << endl;
}

//функция удаления элемента из очереди
void Ochered::getRemove()
{
    if (Head != NULL)                   //Если список не пустой
    {
        Ochered* temp = Head;           //Обращаемся к началу списка с помощью вспомогательного указателя
        cout << "Элемент " << Head->x << " удален" << endl;
        Head = Head->Next;              //Сдвиг начала списка
        delete temp;                    //Освобождение памяти от предыдущего звена списка
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