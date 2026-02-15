#include <iostream>
#include <vector>
#include <cmath>      // для sqrt
#include "../../format.h"
#include "../Modules.h"
bool isPerfectSquare(long num) {
    if (num < 0) return false;
    long root = std::sqrt(num);
    return (root * root == num);
}

static void module_init()
{
    setupEnv();

    int n;
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Помилка: n має бути >= 1\n";
        return;
    }

    std::vector<long> a(n);
    std::cout << "Введіть " << n << " цілих чисел:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "a[" << i << "]:";
        std::cin >> a[i];
    }

    int count_even_for = 0;   // а)
    int count_sq_for = 0;     // б)
    int count_odd_sq_for = 0; // в)

    for (int i = 0; i < n; i++) {
        long x = a[i];

        if (x % 2 == 0) {
            count_even_for++;
        }

        if (isPerfectSquare(x)) {
            count_sq_for++;

            if (x % 2 != 0) {
                count_odd_sq_for++;
            }
        }
    }

    int count_even_while = 0;
    int count_sq_while = 0;
    int count_odd_sq_while = 0;

    int j = 0;
    while (j < n) {
        long x = a[j];

        if (x % 2 == 0) count_even_while++;

        if (isPerfectSquare(x)) {
            count_sq_while++;
            if (x % 2 != 0) count_odd_sq_while++;
        }

        j++;
    }

    std::cout << "\n--- Результати (FOR / WHILE) ---\n";
    std::cout << "а) Парних чисел: "
              << count_even_for << " / " << count_even_while << "\n";

    std::cout << "б) Повних квадратів: "
              << count_sq_for << " / " << count_sq_while << "\n";

    std::cout << "в) Квадратів непарних чисел: "
              << count_odd_sq_for << " / " << count_odd_sq_while << "\n";
}


static Module module(module_init, "4. Дано натуральне число n, цілі числа а1, а2,…, аn. Написати програми знаходження кількості:\nа) парних серед а1, а2,…, аn;б) повних квадратів серед а1, а2,…, аn;в) квадратів непарних чисел серед а1, а2,…, аn.");
