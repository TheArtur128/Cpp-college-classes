#include <iostream>
using namespace std;


int* ReadNumbers()
{
	int readedNumbers[5];

	for (int i = 0; i <= 4; i++) {
		cout << "Введите число под номером " << (i + 1) << " (из 5)\n>>> ";
		cin >> readedNumbers[i];
	}

	return readedNumbers;
}


int SumBetween(int numbers[5])
{
	int sum = 0;

	for (int i = 0; i <= 4; i++) {
		sum += numbers[i];
	}

	return sum;
}


void WriteSum(int sum) {
	cout << "Сумма: " << sum << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	WriteSum(SumBetween(ReadNumbers()));

	return 0;
}
