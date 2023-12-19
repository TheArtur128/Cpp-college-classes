#include <iostream>
using namespace std;

// Model

int RandomNumberBetween(int min, int max)
{
    float attitude = rand() / RAND_MAX;

    return (int) attitude*(max - min) + min;
}

int* GenerateNumbers(int length)
{
    int* numbers{ new int[length] };

    for (int i = 0; i < length; i++) {
        numbers[i] = RandomNumberBetween(10, 30);
    }

    return numbers;
}

int* Combined(int* firstNumbers, int* secondNumbers)
{
    int* combinedNumbers{ new int[sizeof(firstNumbers) + sizeof(secondNumbers)] };

    for (int i = 0; i < sizeof(firstNumbers); i++) {
        combinedNumbers[i] = firstNumbers[i];
    }

    int receivingIndex;
    for (int insertionIndex = sizeof(firstNumbers); insertionIndex < sizeof(combinedNumbers); insertionIndex++) {
        receivingIndex = insertionIndex - sizeof(firstNumbers);
        combinedNumbers[insertionIndex] = secondNumbers[receivingIndex];
    }

    return combinedNumbers;
}

int MaxOf(int* numbers)
{
    int max = numbers[0];

    for (int i = 1; i < sizeof(numbers); i++) {
        if (numbers[i] > max)
            max = numbers[i];
    }

    return max;
}

int SumOf(int* numbers)
{
    int sum = 0;

    for (int i = 0; i < sizeof(numbers); i++) {
        sum += numbers[i];
    }

    return sum;
}

int AverageOf(int* numbers)
{
    return SumOf(numbers) / sizeof(numbers);
}

int MinOf(int* numbers)
{
    int min = numbers[0];

    for (int i = 1; i < sizeof(numbers); i++) {
        if (numbers[i] < min)
            min = numbers[i];
    }

    return min;
}

struct Result {
    int max;
    int average;
    int min;
};

Result* ResultFrom(int firstNumbersLength, int secondNumbersLength) // По идее тут должна быть дтоха, но так как всего два параметра копирующих другую дтоху, то ладно.
{
    int* firstNumbers = GenerateNumbers(firstNumbersLength);
    int* secondNumbers = GenerateNumbers(secondNumbersLength);

    int* combinedNumbers = Combined(firstNumbers, secondNumbers);

    Result result = Result{ MaxOf(combinedNumbers), AverageOf(combinedNumbers), MinOf(combinedNumbers) };
    return &result;
}

// View

void Write(Result* resultP)
{
    Result result = *resultP;

    cout << "\nThird array attributes:" << endl;
    cout << "Max = " << result.max << endl;
    cout << "Average = " << result.average << endl;
    cout << "Min = " << result.min << endl;
}

// Должен быть в ` Presenter`
struct InputDTO {
    int firstNumbersLength;
    int secondNumbersLength;
};

InputDTO* Read()
{
    int firstNumbersLength;
    int secondNumbersLength;

    cout << "First array length = ";
    cin >> firstNumbersLength;

    cout << "Second array length = ";
    cin >> secondNumbersLength;

    InputDTO input{ firstNumbersLength, secondNumbersLength };
    return &input;
}

// Presenter

int main()
{
    InputDTO* inputP = Read();
    InputDTO input = *inputP;

    Write(ResultFrom(input.firstNumbersLength, input.secondNumbersLength));
}
