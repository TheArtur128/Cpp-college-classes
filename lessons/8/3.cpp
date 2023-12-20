#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	int guessedNumber;
	int attemptNumber = 0;
	int number;

	std::cout << "Введите число от 1 до 7, которое должен угадать ваш противник: ";

	while (true) {
		std::cin >> guessedNumber;

		if (guessedNumber >= 1 && guessedNumber <= 7)
		{
			break;
		}
		
		std::cout << "Неправильно! Новое от 1 до 7: ";
	}

	system("cls");
	std::cout << "Угадайте число который загадал ваш опонент!" << std::endl;

	do {
		attemptNumber++;

		if (attemptNumber == 1)
			std::cout << "Вариант ответа: ";
		else
			std::cout << "Вы не угадали! Ещё раз: ";

		std::cin >> number;
	} while (number != guessedNumber);

	std::cout << "Вы отгодали число с " << attemptNumber << "-й попытки!";

	return 0;
}
