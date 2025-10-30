def new_set(A, B):
    c = set()
    for i in A:
        if abs(int(i)) % 5 == 0:
            c.add(i)
    for i in B:
        if abs(int(i)) % 5 == 0:
            c.add(i)
    return c

A = set()
B = set()

print('Введите элементы множества A. Для остановки введите -1')
while True:
    x = input()
    if x == '-1':
        break
    A.add(x)

print('Введите элементы множества B. Для остановки введите -1')
while True:
    x = input()
    if x == '-1':
        break
    B.add(x)

print(new_set(A, B))


