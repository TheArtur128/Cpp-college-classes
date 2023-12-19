#include <iostream>
using namespace std;

int main()
{
    int evenNumbers[50];
    int insertionIndex = 0;

    for (int number = 1; number <= 99; number++) {
        if (number % 2 == 0) {
            evenNumbers[insertionIndex] = number;
            insertionIndex++;
        }
    }

    for (int evenNumber : evenNumbers) {
        cout << evenNumber << endl;
    }
}
