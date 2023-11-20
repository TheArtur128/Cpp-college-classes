#include <iostream>

using namespace std;


int _boxCount = 15;
int &refBoxCount = _boxCount;


int _carNumber = 0;
void WriteNumberOfLoadedBoxesTo(int &refNumberOfLoadedBoxes)
{
    _carNumber++;

    cout << "Всего на складе " << refBoxCount << " коробок" << endl;
    cout << "Сколько загрузить ящиков в машину N" << _carNumber << "?\n>> ";
    
    cin >> refNumberOfLoadedBoxes;
}


void OnOverflow(int &_)
{
    cout << "На складе только " << refBoxCount << " коробок" << endl;
}


void Do(int &refBoxCount)
{
    int *pNumberOfLoadedBoxes;

    do {
        WriteNumberOfLoadedBoxesTo(*pNumberOfLoadedBoxes);

        if (*pNumberOfLoadedBoxes > refBoxCount) {
            OnOverflow(*pNumberOfLoadedBoxes);
            continue;
        }

        refBoxCount -= *pNumberOfLoadedBoxes;
    } while (refBoxCount > 0);
}


void OnExit()
{
    cout << "На складе больше нет коробок" << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    Do(refBoxCount);
    OnExit();
}
