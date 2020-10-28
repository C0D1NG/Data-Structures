#Exercício Python 053: Crie um programa que leia uma frase qualquer e diga se ela é um palíndromo, desconsiderando os espaços.

n = str(input('Escreva uma frase:\n')).strip().upper()
palavras = n.split()
junto = ''.join(palavras)
inverso = str('')

for letra in range (len(junto)-1, -1, -1):
    inverso += junto[letra]

print(f'O inverso de {junto} é {inverso}!')
if inverso == junto:
    print(f'A frase {n} é um palíndromo!')
else:
    print(f'A frase {n} não é um palíndromo!')