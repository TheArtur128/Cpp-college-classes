#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	int numbers[50][2];

	for (int i = 0; i <= 49; i++) {
		numbers[i][0] = i + 1;
		numbers[i][1] = 100 - i - 1;
	}

	return 0;
}
