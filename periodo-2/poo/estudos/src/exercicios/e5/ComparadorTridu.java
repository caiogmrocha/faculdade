package exercicios.e5;

import java.util.Comparator;

public class ComparadorTridu implements Comparator<Jogador> {
    @Override
    public int compare(Jogador jogador1, Jogador jogador2) {
        if (jogador1.getCombinacaoCartas() == CombinacaoTriduEnum.TRIO) {
            if (jogador2.getCombinacaoCartas() == CombinacaoTriduEnum.TRIO) {
                if (jogador1.getCartas()[0].getNome().getNumero() > jogador2.getCartas()[0].getNome().getNumero()) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                return 1;
            }
        } else if (jogador1.getCombinacaoCartas() == CombinacaoTriduEnum.DUPLA) {
            if (jogador2.getCombinacaoCartas() == CombinacaoTriduEnum.TRIO) {
                return -1;
            } else if (jogador2.getCombinacaoCartas() == CombinacaoTriduEnum.DUPLA) {
                if (jogador1.getCartas()[0].getNome().getNumero() > jogador2.getCartas()[0].getNome().getNumero()) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                return 1;
            }
        } else {
            if (jogador2.getCombinacaoCartas() == CombinacaoTriduEnum.TRIO) {
                return -1;
            } else if (jogador2.getCombinacaoCartas() == CombinacaoTriduEnum.DUPLA) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}
