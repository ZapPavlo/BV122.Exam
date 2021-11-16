#include <iostream>
#include <string>
using namespace std;

const unsigned size = 100;

struct name {
    string regicer;
    string films;
    int god;
    int dollar;
};
name lenta[40];

int main()
{
    setlocale(LC_ALL, "RUS");

    for (int i = 1; i <= 40; i++) {

        cout << "¬ведите режиссера: ";
        cin.getline(lenta[i].regicer);
        cout << "¬ведите название фильма: ";
        cin.getline(lenta[i].films);
        cout << "¬ведите год выпуска фильма: ";
        cin >> lenta[i].god;
        cout << "¬ведите стоимость: ";
        cin >> lenta[i].dollar;

        cin.get();
        return(0);
    }
}