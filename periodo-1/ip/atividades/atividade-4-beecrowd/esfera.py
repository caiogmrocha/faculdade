pi = 3.14159

def calcular_volume_esfera(raio):
    return (4/3.0) * pi * (raio ** 3)

raio = float(input())

print(f"VOLUME = {calcular_volume_esfera(raio):.3f}")