# Algoritmo de Inserção na RB Tree

# Algoritmo de Remoção na RB Tree

1. Caso o nó seja vermelho
    1. Caso o nó não tenha filhos:
        1. Remover o nó atual.
    2. Caso o nó tenha somente um filho:
        1. Esse caso é impossível para as red-black trees.
    3. Caso o nó tenha 2 filhos:
        1. Substituir o valor do nó atual pelo valor do nó antecessor, i.e., o nó maior nó da subárvore esquerda.
        2. Remover o maior nó da subárvore esquerda (recursão).
2. Caso o nó seja preto:
    1. Caso o nó não tenha filhos:
        1. Substituir o nó atual por um nó duplo-preto
    2. Caso o nó tenha somente um filho:
        1. Caso o filho do nó seja vermelho:
            1. Substituir o nó atual pelo filho.
            2. Pintar o nó atual de preto.
        2. Caso o filho do nó seja preto:
            1. Caso o irmão do nó seja vermelho:    
                1. Substituir o nó atual por um nó duplo-preto
                2. Pintar o pai de vermelho.
                3. Pintar o irmão de preto.
                4. Rotacionar o pai para a esquerda.
                5. Realizar as verificações a partir do passo 2.2.2.2. (o passo abaixo)
            2. Caso o irmão seja preto:
                2. Caso os filhos do irmão sejam pretos:
                    1. Pintar o irmão de vermelho.
                    2. Caso o pai seja vermelho:
                        1. Pintar o pai de preto.
                    3. Caso o pai seja preto:
                        1. O pai do nó é duplo-preto.
                        2. Realizar as verificações a partir do passo 2.2.2.2.
                3. Caso o filho direito do irmão seja negro:
                    1. Pintar o filho esquerdo do irmão do nó de preto.
                    2. Pintar o irmão do nó de vermelho.
                    3. Rotacionar o irmão do nó para a direita.
                    4. Atualizar o irmão ????
                4. Caso o filho direito do irmão seja vermelho:
                    1. Pintar o irmão do nó com a cor do pai do nó.
                    2. Pintar o pai do nó de preto.
                    3. Pintar o filho direito do irmão do nó de preto.
                    4. Rotacionar o pai para a esquerda.
                    5. Pintar a raiz de preto.
