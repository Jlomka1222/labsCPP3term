#include <iostream>
#include <conio.h>

using namespace std;

// ����� linckedlist ��� ������ � ����������� �������
// ��������� ��������� ������ � ��������� ������
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

//����������� ������ linckedlist
linckedlist::linckedlist()
{
    size = 0;
    head = nullptr;
    
}

linckedlist operator + (linckedlist c1, linckedlist c2)
{
    return linckedlist(c1.seconds + c2.seconds);
}

//���������� ������ linckedlist
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

// ������� ������� ����� �����
int GetInt()
{
    int res = 0;
    int chs = 0;
    do {
        res = scanf_s("%d", &chs);
        while (getchar() != '\n');
        if (!res || chs < 0) printf("������������ ����!\n");
    } while (chs < 0 || res != 1);
    return chs;
}

//������� ��� ���������� 1 ������� 2 ������������
void linckedlist::task1_lab2()
{
    int check;
    while (true)
    {
        system("cls");
        cout << "1.���������� �������" << endl;
        cout << "2.���������� +" << endl;
        cout << "3.���������� &" << endl;
        cout << "0.�����" << endl;
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
            cout << "������������ ����!" << endl;
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
    b = Equal(5, 6);// ���������� Equal(int, int), b = 0
    cout << "��� ��� ����� ����� b ������>> " << b << endl;
    b = Equal(3.755, 3.755); // ���������� Equal(double, double), b = 1
    cout << "��� ������� ����� b ������>> " << b << endl;
    b = Equal('A', 'A'); // ���������� Equal(char, char), b = 1
    cout << "��� ����� b ������>> " << b << endl;
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
//������� ���������� �������� � ������
void linckedlist::Add()
{
    int data;
    cout << "������� ������ ��� ����������:";
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
    cout << "������� ��� ��������" << endl;
    cout << "��� ����������� ������� ����� �������" << endl;
    _getch();
}

//������� �������� �������� �� ������
void linckedlist::Del()
{
    if (!size)
    {
        cout << "������ ����" << endl;
        cout << "��� ����������� ������� ����� �������" << endl;
        _getch();
        return;
    }
    int num;
    cout << "������� ����� �������� ��� �������� �� 0 �� " << size - 1 << endl;
    do
    {
        rewind(stdin);
        num = GetInt();  //������ �������� ��� ��������
        if (num<0 || num> size - 1 ) cout << "������ �������� �� ����������. �������� ����";
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
    cout << "������� " << temp->data << " � �������� " << num << " �����" << endl;
    size--;
    delete temp;
    cout << "��� ����������� ������� ����� �������" << endl;
    _getch();
}

// ������� ������ ������ �� �����
void linckedlist::Print()
{
    if (!size)
    {
        cout << "������ ����" << endl;
        cout << "��� ����������� ������� ����� �������" << endl;
        _getch();
        return;
    }
    Node* temp = head;
    cout << "������:" << endl;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << "��� ����������� ������� ����� �������" << endl;
    _getch();
}

//������� ������ �������� �� ��������� ����� 
void linckedlist::Search()
{
    bool flag = true;
    if (!size)
    {
        cout << "������ ����" << endl;
        cout << "��� ����������� ������� ����� �������" << endl;
        _getch();
        return;
    }
    cout << "������� �������" << endl;
    int data;
    data = GetInt();
    int number = 0;
    Node* temp = head;
    while (temp)
    {
        if (temp->data == data)
        {
            cout << "�������� " << data << " ��� ������� " << number+1 << endl;
            flag = false;
        }
        number++;
        temp = temp->next;
    }
    if (flag) cout << "�� ����������" << endl;
    cout << "��� ����������� ������� ����� �������" << endl;
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
        cout <<"�������������� ��������� ���������� �� ������:" << endl
            << "1.�������� ������� � ������" << endl
            << "2.���������� ������ " << endl
            << "3.����� �������� ������" << endl
            << "4.������� ������� ������ �� �������" << endl
            << "5.������� 1 ������������ 2"<< endl
            << "0.��������� ���������" << endl;
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
            cout << "������������ ����! ���������� ��� ���!" << endl
                << "��� ����������� ������� ����� �������" << endl;
            _getch();
            system("cls");
        }
    }
    return 0;
}

