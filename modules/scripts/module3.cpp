#include <iostream>
#include <cmath>
#include <iomanip>

#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
	setupEnv();

	std::cout << "=== Завдання 15 (Task 15) ===\n";

	double a, b, c, xStart, xEnd, h;

	std::cout << "Введіть a, b, c, Xпоч, Xкін, H: ";
	std::cin >> a >> b >> c >> xStart >> xEnd >> h;

	int Ac = (int)a;
	int Bc = (int)b;
	int Cc = (int)c;

	bool showReal = (~(Ac | Bc | Cc)) != 0;

	std::cout << "\nРезультат (" << (showReal ? "Дійсний" : "Цілий") << "):\n";
	std::cout << "------------------------\n";
	std::cout << "|    X     |     F     |\n";
	std::cout << "------------------------\n";

	for (double x = xStart; x <= xEnd + 0.00001; x += h) {
		double F;

		if (x < 0) {
			F = -a * x * x + b;
		} else if (x > 0 && b != 0) {
			F = x / (x - c);
		} else {
			F = x / -c;
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
	"Завдання 15"
);