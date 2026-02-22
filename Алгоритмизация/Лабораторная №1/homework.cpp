#include <iostream>
#include <chrono>
#include <map>

template <typename Func, typename... Args>
auto measure_execution_time(Func&& func, Args&&... args) {
    auto start_time = std::chrono::high_resolution_clock::now();  // Начинаем отсчет времени
    auto result = func(std::forward<Args>(args)...);  // Выполняем переданную функцию с аргументами
    auto end_time = std::chrono::high_resolution_clock::now();  // Останавливаем отсчет времени

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);  // Вычисляем продолжительность
    return std::make_pair(result, duration.count());  // Возвращаем результат и время выполнения
}


auto make_map(int& n) {
    std::map<int, unsigned> dict;
    for (int i = 0; i < (n+1); i++) {
        dict[i] = i;
    }
    return dict;
}

int search_map(int n, std::map<int, unsigned>& dict) {
    return dict[n];
}

int main() {
    int sizes[] = {10, 100, 200, 500, 1000, 2000, 5000, 10000, 50000, 100000, 1000000, 10000000, 100000000};
    for (int n : sizes) {
        std::map<int, unsigned> dict = make_map(n);
        auto [result, execution_time] = measure_execution_time(search_map, n, dict);
        std::cout << "Result: " << result << ", Time: " << execution_time << " ns" << std::endl;
    }
    return 0;
}