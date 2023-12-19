#include <iostream>
using namespace std;


void _ReadDebtIn(int& debtRef)
{
    cout << ("Тысяч рублей = ");
    cin >> debtRef;
}

bool _ReadPercentagesIn(int& percentagesRef)
{
    cout << "Проценты = ";
    int percentages;
    cin >> percentages;

    if (percentages < 0 || percentages > 100) {
        cout << "Проценты должны быть в диапозоне от 0 до 100 включительно" << endl;
        return false;
    }

    percentagesRef = percentages;

    return true;
}

void _ReadYearsIn(int& yearsRef)
{
    cout << "Года = ";
    cin >> yearsRef;
}

struct Context {
    int& debtRef;
    int& percentagesRef;
    int& yearsRef;
};

Context Read() {
    int debt = 0;
    int& debtRef = debt;

    int percentages = 0;
    int& percentagesRef = percentages;

    int years = 0;
    int& yearsRef = years;

    _ReadDebtIn(debtRef);

    bool ok = false;
    while (ok) {
        ok = _ReadPercentagesIn(percentagesRef);
    }

    _ReadYearsIn(yearsRef);

    return Context{ debtRef, percentagesRef, yearsRef }
}

void Configure()
{
    setlocale(LC_ALL, "ru");
}

int CalculateDebt(Context context)
{
    for (int i = 0; i <= context.yearsRef; i++) {
        context.debtRef += context.debtRef * context.percentagesRef
    }

    return context.debtRef;
}

void Write(int& debtRef)
{
    cout << "Долг = " << debtRef;
}

int main()
{
    Configure();
    Write(CalculateDebt(Read();
}
