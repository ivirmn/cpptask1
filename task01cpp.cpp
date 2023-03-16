#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <clocale>
using namespace std;

const int MAX_SIZE = 100;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    int a[MAX_SIZE][MAX_SIZE];

    // Ввод размерности матрицы
    cout << "Введите размерность матрицы: ";
    cin >> n >> m;

    // Ввод матрицы или генерация случайных значений
    cout << "Хотите ввести значения матрицы вручную (1) или заполнить случайными значениями (2)? ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Введите элементы матрицы:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        // Вывод исходной матрицы
        cout << "Исходная матрица:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        // Инициализация генератора случайных чисел
        srand(time(NULL));

        // Заполнение матрицы случайными значениями
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = rand() % 100; // Генерация чисел от 0 до 99
            }
        }
        cout << "Сгенерированная матрица:" << endl;
        // Вывод сгенерированной матрицы
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Меняем местами четные и нечетные столбцы матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j += 2) {
            int tmp = a[i][j];
            a[i][j] = a[i][j + 1];
            a[i][j + 1] = tmp;
        }
    }

    // Вывод измененной матрицы
    cout << "Измененная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}