def findArrayWithMaxNumPos(A, B):
    numposA = len([i for i in A if i > 0])
    numposB = len([i for i in B if i > 0])

    if numposA > numposB:
        return A
    else:
        return B


A = []
B = []

print('Введите значения для массива A:')
for i in range(5):
    A.append(int(input()))

print('Введите значения для массива B:')
for i in range(5):
    B.append(int(input()))

print('Массив с большим количеством положительных элементов:')
print(findArrayWithMaxNumPos(A, B))



