#include <stdio.h>
#include <stdlib.h>

const int prct_questoes_portugues = 40;
const int prct_questoes_matematica = 21;
const int corte_redacao = 7;

typedef struct {
    int nota_portugues;
    int nota_matematica;
    double nota_redacao;
} candidato;

int validar(candidato c);

int main() {
    int qtd_candidatos = 0, qtd_candidatos_aprovados = 0;

    while (1) {        
        candidato c;

        scanf("%d", &c.nota_portugues);
        
        if (c.nota_portugues < 0)
            break;
        
        scanf("%d", &c.nota_matematica);
        scanf("%lf", &c.nota_redacao);

        qtd_candidatos++;

        if (validar(c))
            qtd_candidatos_aprovados++;
    }

    printf("%d\n", qtd_candidatos_aprovados);

    return 0;
}

int validar(candidato c) {
    int validacao_portugues = c.nota_portugues >= prct_questoes_portugues;
    int validacao_matematica = c.nota_matematica >= prct_questoes_matematica;
    int validacao_redacao = c.nota_redacao >= 7;

    return validacao_matematica && validacao_portugues && validacao_redacao;
}