def fibonacci_search(arr, target):
    """
    Алгоритм поиска по Фибоначчи.
    Работает с отсортированным массивом arr и ищет элемент target.
    Возвращает индекс найденного элемента или -1, если не найден.
    """

    n = len(arr)  # длина массива

    # Инициализируем числа Фибоначчи
    fibMMm2 = 0  # (m-2)-е число Фибоначчи
    fibMMm1 = 1  # (m-1)-е число Фибоначчи
    fibM = fibMMm2 + fibMMm1  # m-е число Фибоначчи

    # Находим минимальное число Фибоначчи, которое >= n
    while fibM < n:
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm2 + fibMMm1

    # Смещение от начала массива
    offset = -1

    # Пока есть элементы для проверки
    while fibM > 1:
        # Проверяем индекс i = min(offset + fibMMm2, n - 1)
        i = min(offset + fibMMm2, n - 1)

        # Если элемент меньше искомого — сдвигаем окно вправо
        if arr[i] < target:
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i  # смещаем "нижнюю границу" поиска

        # Если элемент больше искомого — сдвигаем окно влево
        elif arr[i] > target:
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1

        # Если нашли элемент — возвращаем индекс
        else:
            return i

    # Проверяем последний возможный элемент
    if fibMMm1 and offset + 1 < n and arr[offset + 1] == target:
        return offset + 1

    # Если не найдено — возвращаем -1
    return -1


# -----------------------------
# Основная программа
# -----------------------------
if __name__ == "__main__":
    print("Введите элементы массива (через пробел, в порядке возрастания):")
    arr = list(map(int, input().split()))

    target = int(input("Введите элемент для поиска: "))

    print("\nМассив:", arr)

    index = fibonacci_search(arr, target)

    if index != -1:
        print(f"Элемент {target} найден на позиции {index} (индекс {index}).")
    else:
        print(f"Элемент {target} не найден в массиве.")

