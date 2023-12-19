#include <iostream>
using namespace std;

bool ReadM(int* MP)
{
    int readedM;

    cout << "M = ";
    cin >> readedM;

    if (readedM > 100) {
        cout << "M must be less than 100" << endl;
        return false;
    }
    
    MP = &readedM;
    return true;
}

bool ReadN(int* NP)
{
    int readedN;

    cout << "N = ";
    cin >> readedN;

    if (readedN > 5) {
        cout << "N must be equals or less than 5" << endl;
        return false;
    }

    NP = &readedN;
    return true;
}

int* ReadBy(bool (*read)(int*), int* numberP)
{
    bool ok = false;

    while (ok)
        ok = read(numberP);
    
    return numberP;
}

int** MatrixWithSize(int width, int height)
{
    int** matrix = new int*[width];

    for (int i = 0; i < width; i++)
        matrix[i] = new int[height];
    
    return matrix;
}

int ReadElement(int x, int y)
{
    int element;

    cout << "[" << x << ", " << y << "] = ";
    cin >> element;
    
    return element;
}

int** ConstructMatrix(int (*readElement)(int, int), int width, int height)
{
    int** matrix = MatrixWithSize(width, height);

    for (int x = 0; x <= width; x++) {
        for (int y = 0; x <= height; x++) {
            matrix[x][y] = readElement(x, y);
        }
    }

    return matrix;
}

void Write(int** matrix, int width, int height)
{
    cout << "Matrix:" << endl;

    for (int x = 0; x <= width; x++) {
        for (int y = 0; x <= height; x++) {
            cout << "[" << x << ", " << y << "] = " << matrix[x][y] << endl;
        }
    }
}

int main() {
    int width;
    int height;

    ReadBy(ReadN, &width);
    ReadBy(ReadM, &height);

    int** matrix = ConstructMatrix(ReadElement, width, height);
    Write(matrix, width, height);
}
