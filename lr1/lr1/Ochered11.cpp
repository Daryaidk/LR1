#include <cstddef>
#include <iostream>
#include "Ochered11.h"
using namespace std;

void Ochered11::getCalculate_2() {

    int count = 0;
    Ochered* temp = Head;                //Временный указатель на начало списка
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

void Ochered11::setAdd_2(int x) {

    Ochered* temp = new Ochered;      //Выделение памяти для нового звена списка
    temp->x = x;                          //Временное запоминание принятого параметра x
    temp->Next = NULL;                    //Указание, что следующее звено пока пустое

    if (Head != NULL)                     //Если список не пуст
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;              //Если список не пуст, добавление первого элемента
}

void Ochered11::getRemove_2()
{
    if (Head != NULL)                   //Если список не пустой
    {
        Ochered* temp = Head;           //Обращаемся к началу списка с помощью вспомогательного указателя
        Head = Head->Next;              //Сдвиг начала списка
        delete temp;                    //Освобождение памяти от предыдущего звена списка
    }
}