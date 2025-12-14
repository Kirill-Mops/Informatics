import ctypes
from ctypes import CDLL
import random
import time

cpp_lib = CDLL('./Dll2.dll')

def multiply(v1, v2):
    return sum(x * y for x, y in zip(v1, v2))

def python(v1, v2, iterations):
    start_time = time.time()

    for _ in range(iterations):
        result = multiply(v1, v2)
    end_time = time.time()  
    time_taken = end_time - start_time  

    return time_taken

def cpp(v1, v2, size, iterations):
    multiplyvec_c = cpp_lib.multiplyvec
    multiplyvec_c.restype = ctypes.c_double

    # берем вектор и передаём в него все элементы из списка
    v1_c_array = (ctypes.c_double * size)(*v1)
    v2_c_array = (ctypes.c_double * size)(*v2)

    time_taken = cpp_lib.multiplyvec(v1_c_array, v2_c_array, size, iterations)
    
    return time_taken


if __name__ == "__main__":
    VECTOR_SIZE = 1000  
    ITERATION_TESTS = [10000, 50000, 100000]

    vec1 = [random.random() for _ in range(VECTOR_SIZE)]
    vec2 = [random.random() for _ in range(VECTOR_SIZE)]

    results = []
    
    for iters in ITERATION_TESTS:
        print(f"Тест из {iters} итераций")

        cpp_time = cpp(vec1, vec2, VECTOR_SIZE, iters)
        print(f"Время выполнения C++: {cpp_time} с")
        py_time = python(vec1, vec2, iters)
        print(f"Время выполнения Python: {py_time:} с")
        results.append([iters, round(cpp_time, 2), round(py_time, 2)])
        print("\n")

    if results:
        print("\nИтоговая таблица замеров:")
        print("№ Теста Количество итераций C++ (с) Python (с)")
        c = 0
        for i in results:
            c += 1
            print(f"{c} {i[0]} {i[1]} {i[2]}")
