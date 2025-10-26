#include <iostream>  // библиотека для ввода и вывода
using namespace std;

// Функция "просеивания вниз" (heapify) — поддерживает свойство кучи
void heapify(int arr[], int n, int i) {
    int largest = i;      // предполагаем, что текущий элемент — наибольший (корень поддерева)
    int left = 2 * i + 1; // индекс левого потомка
    int right = 2 * i + 2; // индекс правого потомка

    // Если левый потомок существует и больше корня — обновляем largest
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок существует и больше текущего largest — обновляем largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если largest изменился — значит, нужно поменять элементы местами
    if (largest != i) {
        swap(arr[i], arr[largest]); // ставим больший элемент на вершину

        // Рекурсивно вызываем heapify для поддерева, где произошло изменение
        heapify(arr, n, largest);
    }
}

// Основная функция пирамидальной сортировки (Heap Sort)
void heapSort(int arr[], int n) {
    // 1️⃣ Строим начальную кучу (перегруппируем массив)
    // Начинаем с середины массива, потому что узлы после n/2 — это листья
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 2️⃣ Извлекаем элементы из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень (максимальный элемент) в конец
        swap(arr[0], arr[i]);

        // Вызываем heapify для уменьшенной кучи
        heapify(arr, i, 0);
    }
}

// Вспомогательная функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Главная функция программы
int main() {
    int n;

    cout << "Введите количество элементов массива: ";
    cin >> n; // считываем размер массива

    int arr[n];
    cout << "Введите " << n << " элементов массива:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nМассив до сортировки:\n";
    printArray(arr, n);

    // Вызываем пирамидальную сортировку
    heapSort(arr, n);

    cout << "Массив после сортировки:\n";
    printArray(arr, n);

    return 0; // успешное завершение
}
