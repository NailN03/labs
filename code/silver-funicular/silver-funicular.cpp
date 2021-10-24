﻿#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	// Входной контроль
	long double Eps;
	cout << "Введите Eps: ";
	cin >> Eps;
	cout << "\n";
	if (Eps <= 0 || Eps >=1) {
		cout << "ОШИБКА! Eps должен быть больше 0 и меньше 1!" << endl;;
		return 0;
	}

	// Инициализация переменных
	double Sum = 0;
	unsigned long long N = 1;
	double prevDelta = 1;
	bool interrupted = false;

	// Рассчет суммы
	do {
		Sum += 1.0 / N / (N + 1);
		N++;
		if (prevDelta + Sum - 1 == 0) { //
			interrupted = true;			// Если точность не увеличилась за последнюю итерацию,
			break;						// достигнут предел точности
		}								//
		prevDelta = 1 - Sum;			//
	} while ((1 - Sum) > Eps);

	// Вывод результатов
	cout.precision(60);
	if (interrupted) {
		cout << fixed << "Достигнуто ограничение по точности подсчета\nРазность достигнутой точности и Eps = " << 1 - Sum - Eps << endl;
	}
	cout << "Cумма получена\nКоличество просумированных элементов N = " << N-1 << endl;
	cout << "Сумма Sum = " << Sum << endl;
	cout << fixed << "Разность суммы и точного значения (1 - Sum) = " << (1 - Sum) << endl;

	return 1;
}
