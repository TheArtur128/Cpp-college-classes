#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	srand(100);

	int megaNumbers[3]{ 4, 13, 69 };

	if (sizeof(megaNumbers) != 3)
		return 1;

	int otherMegaNumbers[3]{ rand(), rand(), rand() };

	return 0;
}
