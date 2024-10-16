#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>

using namespace std;

void create(int* arr, int SIZE, double MIN, double MAX)
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = (MAX - MIN) * rand() / RAND_MAX + MIN;
    }
}

void Print(int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << setw(4) << arr[i];
    cout << endl;
}

int findMinMod(int* arr, int SIZE)
{
    int minMod = abs(arr[0]);
    for (int i = 1; i < SIZE; i++)
    {
        if (abs(arr[i]) < minMod)
        {
            minMod = abs(arr[i]);
        }
    }
    return minMod;
}

int sumModsAfterZero(int* arr, int SIZE)
{
    int sum = 0;
    bool foundZero = false;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == 0)
        {
            foundZero = true;
        }
        else if (foundZero)
        {
            sum += abs(arr[i]);
        }
    }
    return sum;
}

void rearrangeArray(int* arr, int SIZE)
{
    int* tempArr = new int[SIZE];
    int evenIndex = 0;
    int oddIndex = SIZE / 2;

    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 == 0)
        {
            tempArr[evenIndex] = arr[i];
            evenIndex++;
        }
        else
        {
            tempArr[oddIndex] = arr[i];
            oddIndex++;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = tempArr[i];
    }

    delete[] tempArr;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE;
    cout << "Введіть розмір масиву (SIZE): "; cin >> SIZE;

    double MIN = -20, MAX = 20;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX);

    Print(arr, SIZE);
    cout << endl;
    cout << "Мінімальний за модулем елемент масиву: " << findMinMod(arr, SIZE) << endl;
    cout << "Сума модулів елементів масиву, розташованих після першого елементу, рівного нулю: " << sumModsAfterZero(arr, SIZE) << endl;
    rearrangeArray(arr, SIZE);
    cout << endl;
    Print(arr, SIZE);

    delete[] arr;

    return 0;
}

