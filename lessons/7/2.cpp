#include <iostream>
using namespace std;

int* ReadNumbers()
{
    int numbers[4];
    cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3];

    return numbers;
}

int main()
{
    int* matrix[3]{ ReadNumbers(), ReadNumbers(), ReadNumbers() };
}
