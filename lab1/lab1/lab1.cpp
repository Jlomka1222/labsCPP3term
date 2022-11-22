#include <iostream>
#include <conio.h>

using namespace std;

// Класс linckedlist для работы с односвязным списком
// Объявлены публичные методы и приватные данные
class linckedlist
{
public:
    linckedlist();
    linckedlist(int k)
    {
        seconds = k;
    }
    ~linckedlist();

    void Add();
    int Getsize() 
    { 
        return size; 
    };
    int Getseconds()
    {
        return seconds;
    };
    int Setseconds(int Seconds)
    {
        seconds = Seconds;
        return seconds;
    }
    void display()
    {
        cout << seconds << " seconds" << endl;
    }
    void Del();
    void Print();
    void Search();
    struct Node
    {
        int data;
        Node* next;
        Node(int data = int(), Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

    Node* head;
    void task1_lab2();
    bool Equal(int, int);
    bool Equal(double, double);
    bool Equal(char, char);
    void perfun();
    void perplus();
    void peramper();
    int seconds;
private:
    int size;
    
};

//конструктор класса linckedlist
linckedlist::linckedlist()
{
    size = 0;
    head = nullptr;
    
}

linckedlist operator + (linckedlist c1, linckedlist c2)
{
    return linckedlist(c1.seconds + c2.seconds);
}

//деструктор класса linckedlist
linckedlist::~linckedlist()
{
    while (size)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

// Функция проерки ввода числа
int GetInt()
{
    int res = 0;
    int chs = 0;
    do {
        res = scanf_s("%d", &chs);
        while (getchar() != '\n');
        if (!res || chs < 0) printf("Неправильный ввод!\n");
    } while (chs < 0 || res != 1);
    return chs;
}

//функция для выполнения 1 задания 2 лабораторной
void linckedlist::task1_lab2()
{
    int check;
    while (true)
    {
        system("cls");
        cout << "1.перегрузка функции" << endl;
        cout << "2.перегрузка +" << endl;
        cout << "3.перегрузка &" << endl;
        cout << "0.выход" << endl;
        check = GetInt();
        switch (check)
        {
        case 1:
            perfun();
            break;
        case 2:
            perplus();
            break;
        case 3:
            peramper();
            break;
        case 0:
            return;
        default:
            cout << "неправильный ввод!" << endl;
            _getch();
        }
    }
    
    _getch();
}
bool linckedlist::Equal(char c1, char c2)
{
    return (bool)(c1 == c2);
}

bool linckedlist::Equal(double d1, double d2)
{
    return (bool)(d1 == d2);
}

bool linckedlist::Equal(int i1, int i2)
{
    return (bool)(i1 == i2);
}

void linckedlist::perfun()
{
    system("cls");
    bool b;
    b = Equal(5, 6);// вызывается Equal(int, int), b = 0
    cout << "Для для целых чисел b вернет>> " << b << endl;
    b = Equal(3.755, 3.755); // вызывается Equal(double, double), b = 1
    cout << "Для дробных чисел b вернет>> " << b << endl;
    b = Equal('A', 'A'); // вызывается Equal(char, char), b = 1
    cout << "Для строк b вернет>> " << b << endl;
    _getch();
}

void linckedlist::perplus()
{
   
    linckedlist c1(20);
    linckedlist c2(10);
    linckedlist c3 = c1 + c2;
    c3.display();
    _getch();
}

void linckedlist::peramper()
{

}
//Функция добавления элемента в список
void linckedlist::Add()
{
    int data;
    cout << "введите данные для добавления:";
    rewind(stdin);
    data = GetInt();
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node* temp = this->head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
    size++;
    cout << "элемент был добавлен" << endl;
    cout << "для продолжения нажмите любую клавишу" << endl;
    _getch();
}

//Функция удаления элемента из списка
void linckedlist::Del()
{
    if (!size)
    {
        cout << "список пуст" << endl;
        cout << "для продолжения нажмите любую клавишу" << endl;
        _getch();
        return;
    }
    int num;
    cout << "введите номер элемента для удаления от 0 до " << size - 1 << endl;
    do
    {
        rewind(stdin);
        num = GetInt();  //индекс элемента для удаления
        if (num<0 || num> size - 1 ) cout << "такого элемента не существует. повтоите ввод";
    } while (num<0 || num> size - 1 );                                                    
    Node* temp = head;
    if (num == 0)
    {
        head = head->next;
        delete temp;
        size--;
        return;
    }
    Node* prev = temp;
    for (int i = 0; i < num; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    cout << "элемент " << temp->data << " с индексом " << num << " удалён" << endl;
    size--;
    delete temp;
    cout << "для продолжения нажмите любую клавишу" << endl;
    _getch();
}

// Функция вывода списка на экран
void linckedlist::Print()
{
    if (!size)
    {
        cout << "список пуст" << endl;
        cout << "для продолжения нажмите любую клавишу" << endl;
        _getch();
        return;
    }
    Node* temp = head;
    cout << "список:" << endl;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << "для продолжения нажмите любую клавишу" << endl;
    _getch();
}

//Функция поиска элемента по заданному числу 
void linckedlist::Search()
{
    bool flag = true;
    if (!size)
    {
        cout << "список пуст" << endl;
        cout << "для продолжения нажмите любую клавишу" << endl;
        _getch();
        return;
    }
    cout << "введите элемент" << endl;
    int data;
    data = GetInt();
    int number = 0;
    Node* temp = head;
    while (temp)
    {
        if (temp->data == data)
        {
            cout << "значение " << data << " под номером " << number+1 << endl;
            flag = false;
        }
        number++;
        temp = temp->next;
    }
    if (flag) cout << "не существует" << endl;
    cout << "для продолжения нажмите любую клавишу" << endl;
    _getch();
}

int main()
{
    system("color 70");
    system("mode 150,35");
    setlocale(LC_ALL, "Rus");
    linckedlist a;
    while (true)
    {
        system("cls");
        cout <<"Воспользуйтесь функциями указанными на экране:" << endl
            << "1.добавить элемент в список" << endl
            << "2.напечатать список " << endl
            << "3.поиск элемента списка" << endl
            << "4.удалить элемент списка по индексу" << endl
            << "5.задание 1 лабораторная 2"<< endl
            << "0.закончить программу" << endl;
        int check;
        rewind(stdin);
        check = GetInt();
        switch (check)
        {
        case 1:
            system("cls");
            a.Add();
            break;
        case 2:
            system("cls");
            a.Print();
            break;
        case 3:
            system("cls");
            a.Search();
            break;
        case 4:
            system("cls");
            a.Del();
            break;
        case 5:
            a.task1_lab2();
            break;
        case 0:
            exit(1);
        default:
            cout << "Неправильный ввод! Попробуйте еще раз!" << endl
                << "Для продолжения нажмите любую клавишу" << endl;
            _getch();
            system("cls");
        }
    }
    return 0;
}

