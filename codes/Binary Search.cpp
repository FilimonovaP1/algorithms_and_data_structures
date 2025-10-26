#include <iostream>  // библиотека для ввода-вывода
using namespace std;

// Функция бинарного поиска
int binarySearch(int arr[], int n, int target) {
    int left = 0;          // левая граница поиска (первый элемент)
    int right = n - 1;     // правая граница поиска (последний элемент)

    // Пока левая граница не пересечёт правую
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        // вычисляем индекс середины (без риска переполнения)

        // Проверяем, совпадает ли элемент в середине с искомым
        if (arr[mid] == target)
            return mid;    // возвращаем индекс найденного элемента

        // Если элемент меньше искомого — ищем в правой половине
        else if (arr[mid] < target)
            left = mid + 1;

        // Если элемент больше искомого — ищем в левой половине
        else
            right = mid - 1;
    }

    // Если элемент не найден — возвращаем -1
    return -1;
}

// Вспомогательная функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Главная функция программы
int main() {
    int n;

    cout << "Введите количество элементов массива: ";
    cin >> n; // считываем размер массива

    int arr[n];
    cout << "Введите " << n << " элементов массива (в порядке возрастания):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nМассив: ";
    printArray(arr, n);

    int target;
    cout << "Введите элемент для поиска: ";
    cin >> target;

    // Вызов функции бинарного поиска
    int result = binarySearch(arr, n, target);

    // Проверяем результат
    if (result != -1)
        cout << "Элемент " << target << " найден в позиции " << result
             << " (индекс " << result << ")." << endl;
    else
        cout << "Элемент " << target << " не найден в массиве." << endl;

    return 0; // успешное завершение программы
}
