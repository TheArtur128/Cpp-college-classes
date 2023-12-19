#include <iostream>
using namespace std;

struct Context {
    int width;
    int height;
};

int ReadElement(Context& context, int x, int y)
{
    int element;

    if (y == context.height)
        cout << endl;

    cout << (x + 1) << "-я строка " << (y + 1)  << "-й столбец: ";
    cin >> element;

    return element;
}

int** ConstructMatrix(Context& context)
{
    int** matrix = new int*[context.width];

    for (int x = 0; x < context.width; x++) {
        for (int y = 0; y < context.height; y++) {
            matrix[x][y] = ReadElement(context, x, y);
        }
    }

    return matrix;
}

void Write(int** matrix, Context& context)
{
    for (int x = 0; x <= context.width; x++) {
        cout << "|\t" << endl;

        for (int y = 0; y <= context.height; y++)
            cout << matrix[x][y] << "\t";
    }

    cout << endl;
}

struct Sums {
    int* verticals;
    int* horizontals;
};


int* EmptyWithSize(int size)
{
    int* numbers = new int[size];

    for (int i = 0; i < size; i++) {
        numbers[i] = 0;
    }

    return numbers;
}


Sums* SumsIn(int** matrix, Context& context)
{
    int* verticalSum = EmptyWithSize(context.width);
    int* horizontalSum = EmptyWithSize(context.height);

    for (int x = 0; x < context.width; x++) {
        for (int y = 0; y < context.height; y++) {
            verticalSum[x] += matrix[x][y];
            horizontalSum[y] += matrix[x][y];
        }
    }

    Sums sums = Sums{ verticalSum, horizontalSum };
    return &sums;
}

void WriteVerticalSum(int* sums) {
    cout << endl << "Сумма по строкам!" << endl;

    for (int i = 0; i < 3; i++) {
        cout << (i + 1) << "-я строка: " << sums[i] << endl;
    }
}

void WriteHorizontalSum(int* sums) {
    cout << endl << "Сумма по столбцам!" << endl;

    for (int i = 0; i < 3; i++) {
        cout << (i + 1) << "-й столбец: " << sums[i] << endl;
    }
}

int main() {
    int width = 3;
    int height = 3;

    Context context = Context{ 3, 3 };
    Context& contextRef = context;

    int** matrix = ConstructMatrix(contextRef);
    Write(matrix, contextRef);

    Sums sums = SumsIn(matrix, contextRef);
}
