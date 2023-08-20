n = int(input())

for i in range(0, n):
    a,b,c = [float(x) for x in input().split(" ")]

    m = ((a*2) + (b*3) + (c*5))/(2+3+5)

    print(f"{m:.1f}")