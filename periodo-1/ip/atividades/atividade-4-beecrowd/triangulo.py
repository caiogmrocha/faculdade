a,b,c = [float(x) for x in input().split(" ")]

if a + b > c and b + c > a and a + c > b:
    print(f"Perimetro = {(a + b + c):.1f}")
else:
    print(f"Area = {((a + b)*c/2):.1f}")
