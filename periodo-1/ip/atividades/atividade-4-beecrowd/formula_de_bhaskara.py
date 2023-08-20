from math import sqrt

def main():
    a,b,c = [float(x) for x in input().split(" ")]

    if (a == 0):
        print("Impossivel calcular")
        return

    def calcular_delta(a, b, c) -> float:
        return (b ** 2) - 4 * a * c

    def calcular_bhaskara_duas_raizes(a, b, delta) -> dict:
        return {
            "x1": (-b + sqrt(delta)) / (2 * a),
            "x2": (-b - sqrt(delta)) / (2 * a)
        }

    delta = calcular_delta(a, b, c)

    if (delta < 0):
        print("Impossivel calcular")
        return
    
    raizes = calcular_bhaskara_duas_raizes(a, b, delta)

    print(f"R1 = {raizes.get('x1'):.5f}")
    print(f"R2 = {raizes.get('x2'):.5f}")

main()
