# Definição

A tabela hash desse diretório tem as seguintes características:

- os elementos da tabela são números inteiros maiores que 1
- é esperado que a tabela armazene no máximo 20 elementos
    - logo, o tamanho da tabela será 41, pois:
        - 2 * quantidade de elementos => 2 * 20 = 40
        - e o número primo mais próximo de 40 é 41.
        - o fator de espalhamento, nesse caso, é de ~= 0.48
    