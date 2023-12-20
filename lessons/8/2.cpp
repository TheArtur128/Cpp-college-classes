#include <iostream>

int numberOfTrianglesFor(int height) {
    if (height == 0)
        return 1;
    
    return numberOfTrianglesFor(height - 1) + 2;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int heightLimit;
    int maximumWidth;
    int mementoWidth = 0;

    int numberOfTriangles;
    int shiftNumber;

    std::cout << "Высота = ";
    std::cin >> heightLimit;

    maximumWidth = heightLimit * 2 - 1;

    for (int height = 0; height < heightLimit; height++) {
        shiftNumber = ((int)maximumWidth / 2) - height - 1;

        for (int _ = 0; _ <= shiftNumber; _++) {
            std::cout << " ";
        }

        for (int _ = 0; _ < numberOfTrianglesFor(height); _++) {
            std::cout << "^";
        }

        std::cout << std::endl;
    }
}
