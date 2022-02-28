#include <cstddef>
#include <iostream>
#include "Ochered111.h"
using namespace std;

void Ochered111::getCalculate() {

    int count = 0;
    Ochered111* temp = Head;             //Временный указатель на начало списка
    while (temp != NULL)                 //Пока в списке что-то встречается
    {
        if (temp->x % 2 != 0)            //Если элемент не делится без остатка на 2, прибавляем к счетчику 1
        {
            count = count + 1;
        }
        temp = temp->Next;
    }
    cout << "Количество нечетных элементов: " << count;          //Выводим количество нечетных элементов очеререди
}

//деструктор для очистки памяти
Ochered111::~Ochered111()
{
    Ochered111* temp = Head;               //Временный указатель на начало списка
    while (temp != NULL)                   //Пока в списке что-то есть
    {
        temp = Head->Next;                 //Резерв адреса на следующий элемент списка
        delete Head;                       //Освобождение памяти 
        Head = temp;                       //Сдвиг начала на следующий адрес, который берем из резерва
    }
}

//функция заполнения информационных полей класса и добавление в список 
void Ochered111::setAdd(int x)
{
    Ochered111* temp = new Ochered111;     //Выделение памяти для нового звена списка
    temp->x = x;                          //Временное запоминание принятого параметра x
    temp->Next = NULL;                    //Указание, что следующее звено пока пустое

    if (Head != NULL)                     //Если список не пуст
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;              //Если список не пуст, добавление первого элемента
}

//функция удаления элемента из очереди
void Ochered111::getRemove()
{
    if (Head != NULL)                   //Если список не пустой
    {
        Ochered111* temp = Head;           //Обращаемся к началу списка с помощью вспомогательного указателя
        Head = Head->Next;              //Сдвиг начала списка
        delete temp;                    //Освобождение памяти от предыдущего звена списка
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

//функция вывода на экран списка
void Ochered111::getShow()
{
    Ochered111* temp = Head;                //Временный указатель на начало списка
    while (temp != NULL)                 //Пока в списке что-то встречается
    {
        cout << temp->x << " ";          //Выводим значения из списка на экран
        temp = temp->Next;               //Сдвигаем указатель на начало на адрес следующего элемента
    }
    cout << endl;
}