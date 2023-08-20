entradas = input()
valores = entradas.split()
hi = int(valores[0])
mi = int(valores[1])
hf = int(valores[2])
mf = int(valores[3])

diferenca_total_minutos = (hf * 60 + mf) - (hi * 60 + mi)

diferenca_horas = diferenca_total_minutos // 60
diferenca_minutos = diferenca_total_minutos % 60

if hi==hf and hf==hi and mi==mf and mf==mi:
    diferenca_horas = 24

print("O JOGO DUROU",diferenca_horas,"HORA(S) E",diferenca_minutos,"MINUTO(S)")