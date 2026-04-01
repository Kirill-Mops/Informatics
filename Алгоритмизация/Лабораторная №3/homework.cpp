#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

template <typename Func, typename... Args>
auto measure_execution_time(Func&& func, Args&&... args) {
    auto start_time = std::chrono::high_resolution_clock::now();  // Начинаем отсчет времени
    auto result = func(std::forward<Args>(args)...);  // Выполняем переданную функцию с аргументами
    auto end_time = std::chrono::high_resolution_clock::now();  // Останавливаем отсчет времени

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);  // Вычисляем продолжительность
    return std::make_pair(result, duration.count());  // Возвращаем результат и время выполнения
}

std::vector<int> MergeSort(std::vector<int>& vec) {
    if (vec.size() > 1)
    {
        int mid = vec.size() / 2;
        std::vector<int> left(vec.begin(), vec.begin() + mid);
        std::vector<int> right(vec.begin() + mid, vec.end());

        MergeSort(left);
        MergeSort(right);

        int i = 0;
        int j = 0;
        int k = 0;


        while ((i < left.size()) and (j < right.size()))
        {
            if (left[i] < right[j])
            {
                vec[k] = left[i];
                i++;
            }
            else
            {
                vec[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.size()) {
            vec[k] = left[i];
            i++;
            k++;
        }

        while (j < right.size())
        {
            vec[k] = right[j];
            j++;
            k++;
        }
    }

    return vec;
}

std::vector<int> UnionBuckets(std::vector<std::vector<int>>& buckets) {
    std::vector<int> UnionVec;
    for (std::vector<int>& bucket : buckets) {
        UnionVec.insert(UnionVec.end(), bucket.begin(), bucket.end());
    }
    return UnionVec;
}

void sortRad(std::vector<int>& vec, int& Rad) {
    std::vector<std::vector<int>> buckets(10);

    for (int value : vec)
    {
        int indBacket = (value / Rad) % 10;
        buckets[indBacket].push_back(value);
    }
    vec = UnionBuckets(buckets);
}

std::vector<int> RadixSort(std::vector<int>& vec) {
    int maxValue = *std::max_element(vec.begin(), vec.end());
    int Rad = 1;
    while (maxValue / Rad > 0)
    {
        sortRad(vec, Rad);
        Rad = Rad * 10;
    }

    return vec;
}

int Slicer(std::vector<int>& vec, int down, int high)
{
    int main = vec[high];
    int i = down - 1;
    for (int j = down; j <= high - 1; j++)
    {
        if (vec[j] <= main)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

void QuickSort(std::vector<int>& vec, int down, int high) {
    if (down < high)
    {
        int mainIndex = Slicer(vec, down, high);
        QuickSort(vec, down, mainIndex - 1);
        QuickSort(vec, mainIndex + 1, high);
    }
}

std::vector<int> make_vector(int& n) {
    std::vector<int> vec(n);
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = std::rand() % 1000000;
    }
    return vec;
}

std::vector<int> make_Quick_sort(std::vector<int>& vec) {
    QuickSort(vec, 0, vec.size() - 1);
    return vec;
}

int main() {

    int sizes[] = { 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };

    for (int n : sizes) {
        std::vector<int> vec = make_vector(n);
        auto [result, execution_time] = measure_execution_time(MergeSort, vec);
        std::cout << execution_time << std::endl;
    }

    std::cout << "" << std::endl;

    for (int n : sizes) {
        std::vector<int> vec = make_vector(n);
        auto [result, execution_time] = measure_execution_time(RadixSort, vec);
        std::cout << execution_time << std::endl;
    }

    std::cout << "" << std::endl;

    for (int n : sizes) {
        std::vector<int> vec = make_vector(n);
        auto [result, execution_time] = measure_execution_time(make_Quick_sort, vec);
        std::cout << execution_time << std::endl;
    }

    return 0;
}