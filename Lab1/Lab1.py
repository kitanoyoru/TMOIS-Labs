def u(a, b):
    return a.union(b)

def i(a, b):
    return a.intersection(b)

if __name__ == '__main__':

    n = int()

    print('Введите множество А: ')
    a = set(map(int, input().split()))
    print('Введите множество В: ')
    b = set(map(int, input().split()))

    print()

    print('Множество А: {0}\nМножество B: {1}\n'.format(a, b))

    n = int(input('Введите номер операции(1 - объединение, 0 - пересечение): ') )
    print()

    if n:
        print('Результат:', u(a, b))
    else:
        print('Результат:', i(a, b))
