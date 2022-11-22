#pragma once
#include <iostream>
using namespace std;

template <class SC> class Ring
{
    struct Element
    {
        SC data;
        Element* next; // указатель на следующий элемент списка
        Element* prev; // указатель на предыдущий элемент списка
    };
private:
    Element* Head; // указатель первый добавленный  элемент
    Element* Curr; // указатель на текущий элемент
    int length; // количество элементов в списке
public: // данные и методы доступные для пользователя класса

    Ring(); // конструктор
    Ring(SC x);	 // конструктор с параметром
    Ring(const Ring<SC>& C); // конструктор копий
    ~Ring(); // деструктор
    int   getlength();
    void  init(); // текущий элемент ссылается на первый
    void  push_start(SC data);
    void  push(SC data); // добавляем новый элемент в список
    SC    pop(); // извлекаем текущий элемент
    void  delFromData(SC adr); // находим и удаляем элемент содержащий переданные данные 
    void  loop(); // вывести весь список в консоль
    void  clear(); // очистить весь список
    void  next(); // перейти к следующему элементу
    void  prev(); // перейти к предыдущему элементу
    int   isNoEmpty(); // проверка состояния списка (если список не пуст)
    void  operator +(SC v); // переопределяем оператор + для добавления нового элемента
    void  sort(); // сортировка списка 
    int   GetInt(); //проверка ввода числа
};

