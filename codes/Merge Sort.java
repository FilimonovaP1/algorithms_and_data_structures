import java.util.Scanner; // библиотека для считывания пользовательского ввода

public class MergeSortExample {

    // Метод для слияния двух отсортированных подмассивов в один отсортированный
    private static void merge(int[] arr, int left, int mid, int right) {
        // Определяем размеры двух временных подмассивов
        int n1 = mid - left + 1; // длина левого подмассива
        int n2 = right - mid;    // длина правого подмассива

        // Создаем временные массивы
        int[] L = new int[n1];
        int[] R = new int[n2];

        // Копируем данные во временные массивы L[] и R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        // Индексы для обхода подмассивов
        int i = 0, j = 0;
        // Индекс для вставки в исходный массив
        int k = left;

        // Сливаем временные массивы обратно в arr[left..right]
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {   // если элемент из левого подмассива меньше или равен элементу из правого
                arr[k] = L[i];
                i++;
            } else {              // иначе вставляем элемент из правого подмассива
                arr[k] = R[j];
                j++;
            }
            k++; // переходим к следующей позиции в основном массиве
        }

        // Копируем оставшиеся элементы из L[], если они есть
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Копируем оставшиеся элементы из R[], если они есть
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Основная рекурсивная функция сортировки слиянием
    private static void mergeSort(int[] arr, int left, int right) {
        if (left < right) { // если в массиве более одного элемента
            // Находим середину массива
            int mid = (left + right) / 2;

            // Рекурсивно сортируем левую и правую половины
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // После сортировки обеих половин — сливаем их
            merge(arr, left, mid, right);
        }
    }

    // Вспомогательная функция для вывода массива
    private static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Главная функция программы (точка входа)
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // создаем объект для ввода

        System.out.print("Введите количество элементов массива: ");
        int n = scanner.nextInt(); // считываем размер массива

        int[] arr = new int[n]; // создаем массив указанной длины

        System.out.println("Введите " + n + " элементов массива:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt(); // считываем элементы
        }

        System.out.println("\nМассив до сортировки:");
        printArray(arr);

        // Вызов сортировки слиянием
        mergeSort(arr, 0, n - 1);

        System.out.println("Массив после сортировки:");
        printArray(arr);

        scanner.close(); // закрываем Scanner (освобождаем ресурс)
    }
}
