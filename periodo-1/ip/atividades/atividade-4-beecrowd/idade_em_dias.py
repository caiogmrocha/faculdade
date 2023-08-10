idade = int(input())

anos = int(idade / 365)
meses = int(idade % 365 / 30)
dias = int(idade % 365 % 30)

print(f"{anos} ano(s)")
print(f"{meses} mes(es)")
print(f"{dias} dia(s)")