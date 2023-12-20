#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    int sum = 0;

    std::string line;
    std::string rawNumber;

    std::cout << "Введите числа разделённые пробелом: ";
    std::cin >> line;

    for (char symbol : line) {
        if (symbol == ' ') {
            sum += atoi(rawNumber.c_str());
            continue;
        }
        
        rawNumber += symbol;
    }

    std::cout << "Сумма = " << sum;
}
