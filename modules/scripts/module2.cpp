#include <iostream>
#include <cmath>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
    setupEnv();
    int n;
    std::cout << "Введiть розмiр масиву: ";
    std::cin >> n;

    if (n <= 0) return;

    double* arr = new double[n];

    std::cout << "Введiть елементи масиву: ";
    for (int i = 0; i < n; i++){
        std::cout << "arr[" << i << "]:";
        std::cin >> arr[i];
    }

    double max_mod = std::abs(arr[0]);
    for (int i = 1; i < n; i++) {
        if (std::abs(arr[i]) > max_mod) max_mod = std::abs(arr[i]);
    }
    std::cout << "Макс. за модулем: " << max_mod << std::endl;

    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (p1 == -1) p1 = i;
            else { p2 = i; break; }
        }
    }

    if (p1 != -1 && p2 != -1) {
        double sum = 0;
        for (int i = p1 + 1; i < p2; i++) sum += arr[i];
        std::cout << "Сума мiж додатними: " << sum << std::endl;
    } else {
        std::cout << "У масивi менше двох додатних елементiв." << std::endl;
    }

    double* temp = new double[n];
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0 && arr[i] != 1) temp[idx++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0 || arr[i] == 1) temp[idx++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;

    std::cout << "Масив пiсля перенесення 0 та 1: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n\n";

    double target;
    std::cout << "Введiть задану величину (порiг) для Частини 2(дробне число): ";
    std::cin >> target;

    double sum_less = 0;
    int count_less = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < target) {
            sum_less += arr[i];
            count_less++;
        }
    }

    if (count_less > 0) {
        std::cout << "Середнє елементiв, менших за " << target << ": "
                  << (sum_less / count_less) << std::endl;
    } else {
        std::cout << "Немає елементiв, менших за " << target << std::endl;
    }

    delete[] arr;
}

static Module module(
    module_init,
    "Завдання 9"
);