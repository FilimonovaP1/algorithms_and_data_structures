#include <iostream>  // библиотека для ввода-вывода
using namespace std;

// Функция интерполяционного поиска
int interpolationSearch(int arr[], int n, int target) {
    int low = 0;           // левая граница поиска
    int high = n - 1;      // правая граница поиска

    // Пока диапазон допустим и target лежит внутри диапазона значений
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        
        // Если все элементы одинаковы (во избежание деления на 0)
        if (arr[low] == arr[high]) {
            if (arr[low] == target)
                return low; // элемент найден
            else
                break; // элемент не найден
        }

        // Формула интерполяции — приближение позиции искомого элемента
        int pos = low + ((double)(target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // Если элемент найден
        if (arr[pos] == target)
            return pos;

        // Если target больше — элемент может быть правее
        if (arr[pos] < target)
            low = pos + 1;
        // Если target меньше — элемент может быть левее
        else
            high = pos - 1;
    }

    // Если элемент не найден
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
    cin >> n;

    int arr[n];
    cout << "Введите " << n << " элементов массива (в порядке возрастания):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nМассив: ";
    printArray(arr, n);

    int target;
    cout << "Введите элемент для поиска: ";
    cin >> target;

    int result = interpolationSearch(arr, n, target);

    if (result != -1)
        cout << "Элемент " << target << " найден в позиции " << result
             << " (индекс " << result << ")." << endl;
    else
        cout << "Элемент " << target << " не найден в массиве." << endl;

    return 0;
}
