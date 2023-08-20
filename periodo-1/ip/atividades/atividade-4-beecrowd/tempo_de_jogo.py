hi,hf = [int(x) for x in input().split(" ")]

if (hi == hf):
    print("O JOGO DUROU 24 HORA(S)")
elif (hi > hf):
    print(f"O JOGO DUROU {(24 - hi) + hf} HORA(S)")
else:
    print(f"O JOGO DUROU {hf - hi} HORA(S)")
