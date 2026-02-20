#include <iostream>
#include <cmath>
#include "../../format.h"
#include "../Modules.h"
enum Figure{
    TRIANGLE = 1,    // а
    SQUARE = 2,      // б
    RECTANGLE = 3,   // в
    COMPLEX_G = 4,   // г
    RING_SECTOR = 5, // ґ
    CORNERS = 6      // д
};
bool isInRange(Figure sel, double x, double y)
{

    switch (sel) {
    case TRIANGLE: // а
        if (y <= 1.0 && std::abs(x) <= y) {
            return true;
        }
        break;

    case SQUARE: // б
        if (std::abs(x) <= 1.0 && std::abs(y) <= 1.0) {
            return true;
        }
        break;

    case RECTANGLE: // в
        if ((x >= 0.0 && x <= 2.0) && (y >= 0.0 && y <= 1.0)) {
            return true;
        }
        break;

    case COMPLEX_G: // г
        if (x <= 0) {
            if (x * x + y * y <= 4.0) return true;
        }
        else {
            if (std::abs(y) <= 2.0 - x) return true;
        }
        break;

    case RING_SECTOR: // ґ
        if ((x * x + y * y <= 4.0) && (std::abs(x) + std::abs(y) >= 2.0)) {
            return true;
        }
        break;

    case CORNERS: // д
        {
            bool inSquare = (std::abs(x) <= 2.0 && std::abs(y) <= 2.0);
            bool outOfCircle = (x * x + y * y >= 4.0);
            bool validQuadrant = (x <= 0 && y >= 0) || (x >= 0 && y <= 0);

            if (inSquare && outOfCircle && validQuadrant) {
                return true;
            }
        }
        break;

    default:
        std::cout << "Помилка: Ви обрали неіснуючий варіант!\n";
        return false;
    }
    return false;
}
static void module_init()
{
    setupEnv();

    std::cout << "=== Завдання 4: Геометричні області ===\n";

    int sel; // Використовуємо число для вибору, щоб уникнути проблем з кирилицею
    double x, y;

    std::cout << "Оберіть варіант фігури(за номером):\n";
    std::cout << "1. (а)\n";
    std::cout << "2. (б)\n";
    std::cout << "3. (в)\n";
    std::cout << "4. (г)\n";
    std::cout << "5. (ґ)\n";
    std::cout << "6. (д)\n";
    std::cout << "Ваш вибір (введіть номер 1-6): ";
    std::cin >> sel;

    std::cout << "Введіть координату X та Y: ";
    std::cin >> x >> y;




    std::cout << "\n--------------------------\n";
    if (isInRange(static_cast<Figure>(sel), x, y)){
        std::cout << "Точка НАЛЕЖИТЬ заданій області.\n";
    }
    else {
        std::cout << "Точка НЕ належить області.\n";
    }
    std::cout << "--------------------------\n";
}

static Module module(
    module_init,
    "Завдання 4 (Геометрія)"
);