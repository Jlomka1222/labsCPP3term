#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

//             �������������� ���������
// +          (�������� �����)
// +=         (�������� ������)
// =          (������������)
// ==         (��������� ��� ������� String � ��� char*)
// !=         (��������� ��� ������� String � ��� char*)
// []         (��������� ������� �� �������)
// ()         (��������� ����� ������)
// (int, int) (��������� ��������� �� ��������)

//             ��������� �������
// isdigit    (��������� ��� �� ������� �����)
// isalpha    (��������� ��� �� ������� �����)
// capitalize (������ ������ ������ ���������)
// toupper    (��� ����� ��������� � ������� �������)
// tolower    (��� ����� ��������� � ������ �������)

class String {

    char* string;

public:

    String(const char* string = "");

    String(const String& str);

    ~String();

    char* get();
    void set(const char* string);
    bool isdigit();
    bool isalpha();
    void capitalize();
    void toupper();
    void tolower();
    unsigned int len();

    String operator + (String str);
    friend String operator + (const char* ch, String str);
    String& operator = (String str);
    void operator += (String str);
    bool operator == (String str);
    bool operator == (const char* str);
    bool operator != (String str);
    bool operator != (const char* str);
    char operator [] (int idx);
    String operator () (int idx1, int idx2);

};

String::String(const char* string) {
    this->string = new char[strlen(string) + 1];
    strcpy(this->string, string);
}

String::String(const String& str) {
    string = new char[strlen(str.string) + 1];
    strcpy(string, str.string);
}

String::~String() {
    delete[] string;
}

char* String::get() {
    return string;
}

void String::set(const char* str) {
    string = new char[strlen(str) + 1];
    strcpy(string, str);
}

String String::operator + (String str) {
    String ret;
    char* buff = new char[strlen(string) + strlen(str.get()) + 1];
    strcat(buff, string);
    strcat(buff, str.get());
    ret.set(buff);
    return ret;
}

String operator + (const char* ch, String str) {
    String ret;
    char* buff = new char[strlen(ch) + strlen(str.get()) + 1];
    strcat(buff, ch);
    strcat(buff, str.get());
    ret.set(buff);
    return ret;
}

String& String::operator = (String str) {
    this->string = new char[strlen(str.get()) + 1];
    strcpy(string, str.get());
    return *this;
}

void String::operator += (String str) {
    char* buff = new char[strlen(string) + 1];
    strcpy(buff, string);
    string = new char[strlen(buff) + strlen(str.get()) + 1];
    strcat(string, buff);
    strcat(string, str.get());
}

bool String::operator == (String str) {
    return strcmp(str.get(), string) == 0;
}

bool String::operator == (const char* str) {
    return strcmp(str, string) == 0;
}

bool String::operator != (String str) {
    return strcmp(str.get(), string) != 0;
}

bool String::operator != (const char* str) {
    return strcmp(str, string) != 0;
}

char String::operator [] (int idx) {
    if (idx < 0) {
        idx = (int)strlen(string) + idx;
    }
    idx = abs(idx);
    if (idx >= strlen(string)) {
        idx %= (int)strlen(string);
    }
    return string[idx];
}

String String::operator () (int idx1, int idx2) {
    if (idx2 > strlen(string) || idx2 < 0) {
        idx2 = (int)strlen(string);
    }
    if (idx1 < 0 || idx1 > strlen(string)) {
        idx1 = 0;
    }
    char* buff = new char[idx2 - idx1];
    for (int i = idx1; i <= idx2; i++) {
        buff[i - idx1] = string[i];
    }
    String str(buff);
    return str;
}

bool String::isdigit() {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] < '0' || string[i] > '9') {
            return false;
        }
    }
    return true;
}

bool String::isalpha() {
    for (int i = 0; i < strlen(string); i++) {
        if ((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z')) {
            return false;
        }
    }
    return true;
}

void String::capitalize() {
    string[0] = (char)std::toupper(string[0]);
}

void String::toupper() {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = (char)std::toupper(string[i]);
    }
}

void String::tolower() {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = (char)std::tolower(string[i]);
    }
}

unsigned int String::len() {
    return strlen(string);
}

ostream& operator << (ostream& out, String str) {
    return out << str.get();
}

istream& operator >> (istream& in, String& str) {
    char* buff = new char[strlen(str.get()) + 1];
    in >> buff;
    str.set(buff);
    return in;
}

int main() {
    system("color 70");
    system("mode 150,35");
    setlocale(LC_ALL, "Rus");
    String str, str1("qwe"), str2("tyu");
    str = "asd" + str1 + str2 + "string";
    cout << str << endl;
    cout << str1 + str2 << endl;
    String choice;
    cout << choice << endl;
    while (true) {
        cout << "������� ������ - concat\n�������� ������ - compare\n������� ��������� �� �������� - substr\n"
            "������� ������ �� ������� - atindex\n������ ����� ������ - length\n��� ������� ����� - isalpha\n"
            "��� ������� ����� - isdigit\n������� ������ ����� ��������� - capitalize\n"
            "��� ����� � ������� ������� - toupper\n��� ����� � ������ ������� - tolower" << endl;
        cin >> choice;
        if (choice == "exit") {
            cout << "����� �� ���������" << endl;
            break;
        }
        else if (choice == "concat") {
            String s1, s2;
            cout << "������� ������ ������" << endl;
            cin >> s1;
            cout << "������� ������ ������" << endl;
            cin >> s2;
            String s3 = s1 + s2;
            cout << s3 << endl;
        }
        else if (choice == "compare") {
            String s1, s2;
            cout << "������� ������ ������" << endl;
            cin >> s1;
            cout << "������� ������ ������" << endl;
            cin >> s2;
            if (s1 == s2) {
                cout << "������ ���������" << endl;
            }
            else {
                cout << "������ ��������" << endl;
            }
        }
        else if (choice == "substr") {
            String s;
            int idx1, idx2;
            cout << "������� ������" << endl;
            cin >> s;
            cout << "������� ������ ������" << endl;
            cin >> idx1;
            cout << "������� ������ ������" << endl;
            cin >> idx2;
            s = s(idx1, idx2);
            cout << s << endl;
        }
        else if (choice == "atindex") {
            String s;
            int idx;
            cout << "������� ������" << endl;
            cin >> s;
            cout << "������� ������" << endl;
            cin >> idx;
            cout << s[idx] << endl;
        }
        else if (choice == "length") {
            String s;
            cout << "������� ������" << endl;
            cin >> s;
            cout << s.len() << endl;
        }
        else if (choice == "isalpha") {
            String s;
            cout << "������� ������" << endl;
            cin >> s;
            if (s.isalpha()) {
                cout << "\n��� ������� - �����\n" << endl;
            }
            else {
                cout << "\n�� ��� ������� - �����\n" << endl;
            }
        }
        else if (choice == "isdigit") {
            String s;
            cout << "������� ������" << endl;
            cin >> s;
            if (s.isdigit()) {
                cout << "\n��� ������� - �����\n" << endl;
            }
            else {
                cout << "\n�� ��� ������� - �����\n" << endl;
            }
        }
        else if (choice == "capitalize") {
            String s;
            cout << "������� ������" << endl;
            cin >> s;
            s.capitalize();
            cout << s << endl;
        }
        else if (choice == "toupper") {
            String s;
            cout << "������� ������" << endl;
            cin >> s;
            s.toupper();
            cout << s << endl;
        }
        else if (choice == "tolower") {
            String s;
            cout << "������� ������" << endl;
            cin >> s;
            s.tolower();
            cout << s << endl;
        }
        else {
            cout << "�� ���������� ����� �������" << endl;
        }
    }
    return 0;
}