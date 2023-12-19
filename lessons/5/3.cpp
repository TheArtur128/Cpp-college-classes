#include <iostream>
using namespace std;


int SumBetween(int* numbers) {
    int sum = 0;

    for (int i = 0; i < sizeof(numbers) - 1; i++) {
        if (numbers[i] % 3 == 0)
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
    int inputNumber;

    for (int i = 0; i < length; i++) {
        cout << ">> ";
        cin >> numbers[i];
    }

    cout << "Числа: ";

    for (int i = 0; i < length; i++) {
        cout << numbers[i] << " ";
    }

    cout << "Сумма = " << SumBetween(numbers);
}
