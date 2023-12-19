#include <iostream>
using namespace std;

int main()
{
    int numbers[10]{ rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand() };

    for (int& numberRef : numbers) {
        if (numberRef > 10) {
            numberRef -= 10;
        }
    }

    for (int number : numbers) {
        cout << number << endl;
    }
}
