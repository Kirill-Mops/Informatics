#include <iostream>

void NumPos(const int* arr, int& c) {
	c = 0; // Инициализация счёта
	for (int i = 0; i < 5; i++) {
		if (arr[i] > 0) {
			c += 1;
		}
	}
}

void findArrayWithMaxNumPos(const int* arrA, const int* arrB) {
	int numA = 0, numB = 0;

	// Вычисляем количество положительных значений в массивах
	NumPos(arrA, numA);
	NumPos(arrB, numB);

	// Сравниваем суммы и выводим массив с наибольшим количеством положительных значений
	if (numA > numB) {
		std::cout << "Массив A имеет количество положительных значений: " << numA << std::endl;
		std::cout << "Элементы массива A: ";
		for (int i = 0; i < 5; i++) {
			std::cout << arrA[i] << " ";
		}
	}
	else {
		std::cout << "Массив B имеет количество положительных значений: " << numB << std::endl;
		std::cout << "Элементы массива B: ";
		for (int i = 0; i < 5; i++) {
			std::cout << arrB[i] << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	int* A = new int[5];
	int* B = new int[5];

	// Ввод массивов
	std::cout << "Введите 5 элементов для массива A:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cin >> A[i];
	}

	std::cout << "Введите 5 элементов для массива B:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cin >> B[i];
	}

	// Поиск массива с наибольшим количеством положительных значений
	findArrayWithMaxNumPos(A, B);

	// Освобождение выделенной памяти
	delete[] A;
	delete[] B;

	return 0;
}
