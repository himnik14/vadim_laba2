#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
class Copy 
{
    ofstream fout;
    string _line;
public:
    string get_line();
    Copy();
    Copy(string _line);
    ~Copy();
    Copy(const Copy& cp);
    void set(string _line);
    string update();
    void print();
};

string Copy::get_line()
{
    return _line;
}

// конструктор копирования класса Copy
// передается ссылка на Copy
Copy::Copy(const Copy& cp)
{  // копирование данных из одного объекта в другой
    _line = cp._line;
    cout << "Сработал конструктор копирования!\n";
}

string Copy::update()
{
    fout.open("C:\\Games\\db.txt", ios::app);
    int b = 0;
    if ((_line.size()) % 2 == 0) {
        for (int i = 0; i < _line.size()+b; i++)
        {
            if (isdigit(_line[i-b]))
            {
                if (stoi(to_string(_line[i-b])) % 2 == 0)
                {
                    _line.erase(i-b, 1);
                    b++;
                }
            }
        }
        
    }
    fout << _line << "\n";
    return _line;
}

void Copy::print()
{
    cout << _line << "\n";
}

void Copy::set(string _line)
{
    if (_line.empty())
        throw exception("Строка пустая!\n");
    this->_line = _line;
}

Copy::Copy()
{
    _line = "254gf9f!";
    cout << "Сработал конструктор по умолчанию!\n";
}

Copy::Copy(string _line)
{
    if (_line.empty())
        throw exception("Строка пустая!\n");
    this->_line = _line;
}

Copy::~Copy()
{
    cout << "Сработал деструктор!\n";
}

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Copy cp;//конструктор по умолчанию
    Copy cp1("Строка2 д8ля констр64укто6ра с пара2метром2!");//конструктор с параметром
    Copy cp2;
    cout << cp.update() << "\n";
    cout << cp1.update() << "\n";
    cp2.set("2вгту5");
    cp2.update();
    cp2.print();
    // код, который вызывает конструктор копирования
    Copy cp3("линия");
    Copy cp4 = cp3; // инициализация объекта => вызывается конструктор копирования
    cp4.print();

}

