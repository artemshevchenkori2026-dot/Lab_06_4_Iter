#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Динамічне створення та заповнення масиву
void Create(double* a, const int n, const double Low, const double High) {
    for (int i = 0; i < n; i++) {
        a[i] = Low + (rand() / (RAND_MAX / (High - Low)));
    }
}

// Виведення масиву на екран
void Print(const double* a, const int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(8) << fixed << setprecision(2) << a[i];
    }
    cout << endl;
}

// 1.1. Максимальний за модулем елемент масиву
double MaxAbs(const double* a, const int n) {
    if (n <= 0) return 0;
    double maxAbsVal = abs(a[0]);
    for (int i = 1; i < n; i++) {
        if (abs(a[i]) > maxAbsVal) {
            maxAbsVal = abs(a[i]);
        }
    }
    return maxAbsVal;
}

// 1.2. Сума елементів між першим і другим додатними
double SumBetweenPositives(const double* a, const int n) {
    int firstPosIdx = -1;
    int secondPosIdx = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (firstPosIdx == -1) {
                firstPosIdx = i;
            }
            else if (secondPosIdx == -1) {
                secondPosIdx = i;
                break;
            }
        }
    }

    if (firstPosIdx == -1 || secondPosIdx == -1 || secondPosIdx - firstPosIdx <= 1) {
        return 0; // Додатних менше ніж 2 або між ними немає елементів
    }

    double sum = 0;
    for (int i = firstPosIdx + 1; i < secondPosIdx; i++) {
        sum += a[i];
    }
    return sum;
}

// 2. Перетворення масиву: нулі в кінець зі збереженням порядку інших елементів
void MoveZerosToEnd(double* a, const int n) {
    double* temp = new double[n];
    int index = 0;

    // Спочатку копіюємо всі ненульові елементи
    for (int i = 0; i < n; i++) {
        if (a[i] != 0.0) {
            temp[index++] = a[i];
        }
    }

    // Заповнюємо залишок нулями
    while (index < n) {
        temp[index++] = 0.0;
    }

    // Переносимо назад у динамічний масив
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    delete[] temp;
}

int main() {
    srand((unsigned)time(0));

    int n;
    cout << "Enter size of array n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    // Динамічне виділення пам'яті
    double* a = new double[n];

    const double LOW = -10.0;
    const double HIGH = 10.0;

    Create(a, n, LOW, HIGH);

    cout << "\nInitial array:" << endl;
    Print(a, n);

    cout << "\n1.1. Max abs element: " << MaxAbs(a, n) << endl;
    cout << "1.2. Sum between 1st and 2nd positive: " << SumBetweenPositives(a, n) << endl;

    MoveZerosToEnd(a, n);

    cout << "\nModified array (zeros moved to end):" << endl;
    Print(a, n);

    // Звільнення динамічної пам'яті
    delete[] a;

    return 0;
}