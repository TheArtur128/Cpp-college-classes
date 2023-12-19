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
    cout << "Лимит выводимых чисел = ";
    cin >> limit;

    cout << "Числа больше лимита: ";

    for (int i = 0; i < length; i++) {
        if (numbers[i] > limit)
            cout << numbers[i] << " ";
    }
}
