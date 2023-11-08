#include <iostream>

void ReadNumberTo(int *place)
{
	int number;

	std::cout << "Введите число\n>> ";
	std::cin >> number;

	place = &number;
}

std::pair<int, int> DoModel(void (*readNumberTo)(int*))
{
	int sum = 0;
	int counter = 0;

	int* newNumber;

	do {
		readNumberTo(newNumber);

		sum += *newNumber;
		counter++;
	} while (*newNumber != 0);

	return std::pair<int, int>(sum, counter);
}

void WriteResultFrom(std::pair<int, int> result)
{
	int sum = result.first;
	int counter = result.second;

	std::cout << "Сумма = ";
	std::cout << sum << std::endl;

	std::cout << "Количество чисел = ";
	std::cout << counter;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	WriteResultFrom(DoModel(ReadNumberTo));
}
