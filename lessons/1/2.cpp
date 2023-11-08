#include <iostream>
using namespace std;

int ReadBalance()
{
    cout << "Введите количество деняк которые у вас есть\n>> ";

    int balance;
    cin >> balance;

    return balance;
}

int ReadTransaction()
{
    cout << "Введите количество деняк которые вам прислали\n>> ";

    int money;
    cin >> money;

    return money;
}

int DoTransaction(int balance, int money)
{
    return balance + money;
}

void WriteNewBalance(int newBalance)
{
    cout << "Теперь у вас " << newBalance << " деняк" << endl;
}

void main()
{
    setlocale(LC_ALL, "Russian");

    int balance = ReadBalance();
    int transaction = ReadTransaction();

    WriteNewBalance(DoTransaction(balance, transaction));
}
