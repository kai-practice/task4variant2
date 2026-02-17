#include <iostream>
#include <cmath>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
    setupEnv();

    std::cout << "=== Завдання 4: Геометричні області ===\n";

    int sel; // Використовуємо число для вибору, щоб уникнути проблем з кирилицею
    double x, y;
    bool isInRange = false;

    std::cout << "Оберіть варіант фігури:\n";
    std::cout << "1 (а)\n";
    std::cout << "2 (б)\n";
    std::cout << "3 (в)\n";
    std::cout << "4 (г)\n";
    std::cout << "5 (ґ)\n";
    std::cout << "6 (д)\n";
    std::cout << "Ваш вибір (введіть номер 1-6): ";
    std::cin >> sel;

    std::cout << "Введіть координату X та Y: ";
    std::cin >> x >> y;

    switch (sel) {
        case 1: // а
            if (y <= 1.0 && std::abs(x) <= y) {
                isInRange = true;
            }
            break;

        case 2: // б
            if (std::abs(x) <= 1.0 && std::abs(y) <= 1.0) {
                isInRange = true;
            }
            break;

        case 3: // в
            if ((x >= 0.0 && x <= 2.0) && (y >= 0.0 && y <= 1.0)) {
                isInRange = true;
            }
            break;

        case 4:
            if (x <= 0) {
                if (x * x + y * y <= 4.0) isInRange = true;
            }
            else {
                if (std::abs(y) <= 2.0 - x) isInRange = true;
            }
            break;

        case 5:
            if ((x * x + y * y <= 4.0) && (std::abs(x) + std::abs(y) >= 2.0)) {
                isInRange = true;
            }
            break;

        case 6:
        {
            bool inSquare = (std::abs(x) <= 2.0 && std::abs(y) <= 2.0);
            bool outOfCircle = (x * x + y * y >= 4.0);
            bool validQuadrant = (x <= 0 && y >= 0) || (x >= 0 && y <= 0);

            if (inSquare && outOfCircle && validQuadrant) {
                isInRange = true;
            }
        }
        break;

        default:
            std::cout << "Помилка: Ви обрали неіснуючий варіант!\n";
            return;
    }

    std::cout << "\n--------------------------\n";
    if (isInRange) {
        std::cout << "Точка НАЛЕЖИТЬ заданій області.\n";
    }
    else {
        std::cout << "Точка НЕ належить області.\n";
    }
    std::cout << "--------------------------\n";
}

// Реєстрація модуля
static Module module(
    module_init,
    "Завдання 4 (Геометрія)"
);4