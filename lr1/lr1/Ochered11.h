#include <iostream>
#ifndef Ochered11_h
#define Ochered11_h
#include "Ochered.h"
#include "Ochered1.h"
class Ochered11 :protected Ochered
{
public:
	void getCalculate_2();
	void setAdd_2(int x);                      //Функция добавления элемента в очередь
	void getRemove_2();                        //Функция удаления элемента
};
#endif