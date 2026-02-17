#include <iostream>
#include <cmath>
#include <iomanip>

#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
    setupEnv();

    std::cout << "=== Завдання 3 (Task 3) ===\n";

    double a, b, c, xStart, xEnd, h;

    std::cout << "Введіть a, b, c, Xпоч, Xкін, H: ";
    std::cin >> a >> b >> c >> xStart >> xEnd >> h;

    int Ac = (int)a;
    int Bc = (int)b;
    int Cc = (int)c;

    // Умова: A & (B | C)
    bool showReal = (Ac & (Bc | Cc)) != 0;

    std::cout << "\nРезультат (" << (showReal ? "Дійсний" : "Цілий") << "):\n";
    std::cout << "------------------------\n";
    std::cout << "|    X     |     F     |\n";
    std::cout << "------------------------\n";

    for (double x = xStart; x <= xEnd + 0.00001; x += h) {
        double F;

        // Формули Завдання 3
        if (a < 0) {
            F = a * x * x + b * x + c;
        } else if (a > 0 && c != 0) {
            F = -a / (x - c);
        } else {
            F = a * (x + c);
        }

        std::cout << "| " << std::setw(8) << x << " | ";

        if (showReal) {
            std::cout << std::setw(9) << std::fixed << std::setprecision(2) << F << " |\n";
        } else {
            std::cout << std::setw(9) << (int)F << " |\n";
        }
    }
    std::cout << "------------------------\n";
}

static Module module(
    module_init,
    "Завдання 3"
);