def main():
    n1,n2,n3,n4 = [float(x) for x in input().split(" ")]

    media1 = ((n1*2)+(n2*3)+(n3*4)+(n4*1))/(2 + 3 + 4 + 1)

    print(f"Media: {media1:.1f}")

    if (media1 >= 7):
        print("Aluno aprovado.")
    elif (media1 >= 5):
        print("Aluno em exame.")

        nota_exame = float(input())

        print(f"Nota do exame: {nota_exame:.1f}")

        media2 = (media1 + nota_exame) / 2

        if (media2 >= 5):
            print("Aluno aprovado.")
        else:
            print("Aluno reprovado.")

        print(f"Media final: {media2:.1f}") 
    else:
        print("Aluno reprovado.")

main()