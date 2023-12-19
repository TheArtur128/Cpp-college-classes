#include <iostream>
using namespace std;


int SumBetween(int* numbers) {
    int sum = 0;

    for (int i = 0; i < sizeof(numbers) - 1; i++) {
        sum += numbers[i];
    }

    return sum;
}


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

    cout << "Введенные цифры: ";

    for (int i = 0; i < length; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Сумма: " << SumBetween(numbers);
}
