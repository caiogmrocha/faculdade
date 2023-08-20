while True:
    notas = []

    c = 0

    while (c < 2):
        a = float(input())

        if (not (0 <= a <= 10)):
            print("nota invalida")
            continue
        
        notas.append(a)

        c += 1
    
    print(f"media = {(sum(notas)/len(notas)):.2f}")

    r = 0

    while True:
        r = int(input("novo calculo (1-sim 2-nao)\n"))

        if (r == 1 or r == 2):
            break
        else:
            continue
    
    if (r == 1):
        continue
    else:
        break