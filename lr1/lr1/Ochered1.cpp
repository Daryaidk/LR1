#include <cstddef>
#include <iostream>
#include "Ochered1.h"
using namespace std;

void Ochered1::getCalculate() {

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
    cout << "Количество нечетных элементов: " << count;          //Выводим количество нечетных элементов очереди
}