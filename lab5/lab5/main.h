#pragma once
#include <iostream>
using namespace std;

template <class SC> class Ring
{
    struct Element
    {
        SC data;
        Element* next; // ��������� �� ��������� ������� ������
        Element* prev; // ��������� �� ���������� ������� ������
    };
private:
    Element* Head; // ��������� ������ �����������  �������
    Element* Curr; // ��������� �� ������� �������
    int length; // ���������� ��������� � ������
public: // ������ � ������ ��������� ��� ������������ ������

    Ring(); // �����������
    Ring(SC x);	 // ����������� � ����������
    Ring(const Ring<SC>& C); // ����������� �����
    ~Ring(); // ����������
    int   getlength();
    void  init(); // ������� ������� ��������� �� ������
    void  push_start(SC data);
    void  push(SC data); // ��������� ����� ������� � ������
    SC    pop(); // ��������� ������� �������
    void  delFromData(SC adr); // ������� � ������� ������� ���������� ���������� ������ 
    void  loop(); // ������� ���� ������ � �������
    void  clear(); // �������� ���� ������
    void  next(); // ������� � ���������� ��������
    void  prev(); // ������� � ����������� ��������
    int   isNoEmpty(); // �������� ��������� ������ (���� ������ �� ����)
    void  operator +(SC v); // �������������� �������� + ��� ���������� ������ ��������
    void  sort(); // ���������� ������ 
    int   GetInt(); //�������� ����� �����
};

