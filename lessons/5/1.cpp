#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Сколько хотите ввести цифр?\n>> ";

    int length;
    cin >> length;

    cout << "Ввод:" << endl;

    int* numbers{ new int[length] };

    for (int i = 0; i < length; i++) {
        cout << ">> ";
        cin >> numbers[i];
    }

    int limit;
    cout << "Лимит замены = ";
    cin >> limit;

    cout << "Все числа: ";
    for (int i = 0; i < length; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Числа с заменой: ";
    int outputNumer;

    for (int i = 0; i < length; i++) {
        outputNumer = numbers[i] > limit ? 5 : numbers[i];
        cout << outputNumer << " ";
    }
}
