int main()
{
	setlocale(LC_ALL, "Russian");
	int sum = 0;
	int counter = 0;
	int newNumber;
	do {
		std::cout << "Введите число\n>> ";
		std::cin >> newNumber;
		counter++;
		sum += newNumber;
	} while (newNumber != 0);
	std::cout << "Сумма = ";
	std::cout << sum << std::endl;
	std::cout << "Количество чисел = ";
	std::cout << counter;
}
