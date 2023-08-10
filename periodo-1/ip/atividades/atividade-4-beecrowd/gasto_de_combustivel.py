tempo_gasto = int(input())
velocidade_media = int(input())

def calcular_distancia_percorrida(tg, vm):
    return tg * vm

def calcular_custo(d):
    return d / 12

distancia = calcular_distancia_percorrida(tempo_gasto, velocidade_media)

custo = calcular_custo(distancia)

print(f"{custo:.3f}")