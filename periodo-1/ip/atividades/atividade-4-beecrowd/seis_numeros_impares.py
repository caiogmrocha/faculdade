x = int(input())

if (x % 2 == 0):
    for i in range(1, 13, 2):
        print(x + i)
else:
    for i in range(0, 12, 2):
        print(x + i)