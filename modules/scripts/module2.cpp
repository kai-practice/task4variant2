#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include "../../format.h"
#include "../Modules.h"

static double generateRandom() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-1000, 222);
    return dis(gen) / 100.0;
}

static void module_init()
{
    setupEnv();
    std::cout << std::fixed << std::setprecision(2);

    int n = 0;
    std::string input;
    std::cout << "Введiть розмiр масиву (Enter або символ для рандому): ";
    std::getline(std::cin, input);
    try {
        n = std::stoi(input);
        if (n <= 0) throw std::invalid_argument("negative");
    } catch (...) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        n = std::uniform_int_distribution<>(3, 10)(gen);
        std::cout << "Використано рандомний розмiр: " << n << std::endl;
    }

    double* arr = new double[n];

    std::cout << "Введiть елементи масиву (дробні) або будь-який символ/пустоту для рандому: " << std::endl;
    for (int i = 0; i < n; i++){
        std::cout << "arr[" << i << "]:";
        std::getline(std::cin, input);
        try {
            arr[i] = std::stod(input);
        } catch (...) {
            arr[i] = generateRandom();
            std::cout << " (Згенеровано рандомно: " << arr[i] << ")" << std::endl;
        }
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
    std::cout << "Введiть задану величину (порiг) для Частини 2 (Enter для рандому): ";
    std::getline(std::cin, input);
    try {
        target = std::stod(input);
    } catch (...) {
        target = generateRandom();
        std::cout << "Використано рандомний порiг: " << target << std::endl;
    }

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