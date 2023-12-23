# Fluxo do programa

## Entrada de Dados

1. Ler o arquivo do labirinto linha a linha, e para cada posição:
    1. Verificar e atribuir adjacência à esquerda.
    2. Verificar e atribuir adjacência à direita.
    3. Verificar e atribuir adjacência acima.
    4. Verificar e atribuir adjacência abaixo.
    5. Sendo a entrada uma matriz de entrada **n** por **m**, considere as seguintes restrições:
        1. as posições a[0][j] não possuem adjacências acima.
        2. as posições a[i][0] não possuem adjacências à esquerda.
        3. as posições a[n][j] não possuem adjacências abaixo.
        4. as posições a[i][m] não possuem adjacências à direita.

## Processamento

Considere que o grafo já está definido e que a pilha de posições do percurso já foi inicializada.

1. Iterando sobre cada vértice do grafo.
    1. Se o vertice atual tem uma adjacência não visitada, deve-se visitar essa adjacência e marcá-la como visitada.
        1. Adicionar o vértice à pilha de posições do percurso.
    2. Se não.
        1. Se o vértice atual não é o vértice do canto inferior esquerdo, deve-se desempilhar os caminhos percorridos e voltar a iteração do grafo até encontrar um vértice que possua adjacências não visitadas. Aqui deve-se voltar à verificação 1.1.
        2. Se não, o caminho chegou ao fim ✅.

## Saída

Deve-se exibir o grafo original com o caminho da saída, onde as posições serão representadas com sinais de **+**.