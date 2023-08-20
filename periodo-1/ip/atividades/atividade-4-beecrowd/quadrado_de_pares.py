x = int(input())

if (x % 2 == 0):
    for i in range(2, x+1, 2):
        print(f"{i}^2 = {i**2}")
else:
    for i in range(2, x, 2):
        print(f"{i}^2 = {i**2}")