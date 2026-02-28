#include <iostream>
#include <cmath>

double simpson_rule(double (*f)(double), double a, double b, int n) {
    if (n % 2 == 1) n++; // Делаем n четным
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
        sum += 4 * f(a + i * h);

    for (int i = 2; i < n - 1; i += 2)
        sum += 2 * f(a + i * h);

    return (h / 3) * sum;
}

double function1(double x) {
    return 2 * pow(x, 2) + 1;
}

double function2(double x) {
    return -2 * pow(x, 2) + 7; 
}

int main() {
    for (int n = 1;  n < 100001; n*=10) {
        double result1 = simpson_rule(function1, 5, 6, n);
        double result2 = simpson_rule(function2, 5, 6, n);
        double result = result1 - result2;
        std::cout << "Approximate value of the integral: " << result << std::endl;
    }
    return 0;
}