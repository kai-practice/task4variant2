#include <iostream>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
    setupEnv();
    std::cout << "--- Запуск Завдання 1 ---" << std::endl;

    int n;
    std::cout << "Введiть розмiр масиву: ";
    std::cin >> n;

    if (n <= 0) return;

    double* arr = new double[n];

    std::cout << "Введiть елементи масиву: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    double sum_negative = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            sum_negative += arr[i];
        }
    }
    std::cout << "Сума вiд'ємних елементiв: " << sum_negative << std::endl;

    int min_idx = 0;
    int max_idx = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_idx]) min_idx = i;
        if (arr[i] > arr[max_idx]) max_idx = i;
    }

    int start = (min_idx < max_idx) ? min_idx : max_idx;
    int end = (min_idx > max_idx) ? min_idx : max_idx;

    if (end - start > 1) {
        double product = 1.0;
        for (int i = start + 1; i < end; i++) {
            product *= arr[i];
        }
        std::cout << "Добуток мiж мiн i макс: " << product << std::endl;
    } else {
        std::cout << "Мiж мiн i макс немає елементiв." << std::endl;
    }

    bool found_duplicate = false;
    double max_duplicate = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > 1) {
            if (!found_duplicate) {
                max_duplicate = arr[i];
                found_duplicate = true;
            } else if (arr[i] > max_duplicate) {
                max_duplicate = arr[i];
            }
        }
    }

    if (found_duplicate) {
        std::cout << "Максимальне число, що повторюється: " << max_duplicate << std::endl;
    } else {
        std::cout << "В масивi немає чисел, що повторюються." << std::endl;
    }

    delete[] arr;
}

static Module module(
    module_init,
    "Завдання 1"
);