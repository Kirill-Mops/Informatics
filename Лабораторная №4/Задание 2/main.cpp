#include <iostream>
#include <set>

std::set<int> new_set(std::set<int> A, std::set<int> B) {
	std::set<int> c;
	for (int element : A) {
		if (element % 5 == 0) {
			c.insert(element);
		}
	}
	
	for (int element : B) {
		if (element % 5 == 0) {
			c.insert(element);
		}
	}
	return c;
}

int main() {
	std::set<int> A;
	std::set<int> B;
	int x;

	std::cout << "Enter the elements of the set A. At the end of the input, write -1:" << std::endl;
	while (std::cin >> x and x != -1) {
		A.insert(x);
	}

	std::cout << "Enter the elements of the set B. At the end of the input, write -1:" << std::endl;
	while (std::cin >> x and x != -1) {
		B.insert(x);
	}

	std::set<int> c = new_set(A, B);

	std::cout << "New set: ";

	for (int element : c) {
		std::cout << element << " ";
	}

	return 0;
}