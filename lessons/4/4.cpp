#include <iostream>
using namespace std;


int MaximumIn(int* numbers) {
    if (sizeof(numbers) == 0)
        return 0;  // В идеальном мире тут должен был быть тип возвращаемого значения Option инт либо вызов исключения.

    int maximum = numbers[0];

    if (sizeof(numbers) == 1)
        return maximum;

    for (int i = 1; i < sizeof(numbers); i++) {
        if (numbers[i] > maximum)
            maximum = numbers[i];
    }

    return maximum;
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

    cout << "Введенные числа: ";

    for (int i = 0; i < length; i++) {
        cout << numbers[i] << " ";
    }

    if (sizeof(numbers) == 0)
        cout << "Для максимума введите хотя бы одно число";
    else
        cout << "Максимум = " << MaximumIn(numbers);
}
