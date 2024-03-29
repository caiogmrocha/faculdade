package exercicios.e5;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class Tridu {
    private List<Jogador> jogadores;
    private Baralho baralho;
    private Jogador vencedor;

    public Tridu(List<Jogador> jogadores, Baralho baralho) {
        this.jogadores = new ArrayList<Jogador>();

        for (Jogador jogador : jogadores) {
            this.jogadores.add(jogador);
        }

        this.baralho = baralho;
        this.vencedor = null;
    }

    public void sortearCartas(String nomeJogador) {
        for (Jogador jogador : this.jogadores) {
            if (jogador.getNome().equals(nomeJogador)) {
                for (int i = 0; i < 50; i++) {
                    this.baralho.embaralhar();
                }

                jogador.setCartas(new Carta[]{
                    this.baralho.darCarta(),
                    this.baralho.darCarta(),
                    this.baralho.darCarta(),
                });
                
                break;
            }
        }
    }

    public void mostrarCartas() {
        for (Jogador jogador : this.jogadores) {
            System.out.println(jogador);
        }
    }

    public boolean calcularEmpate() {
        int maior = 0;
        int quantidade = 0;

        for (Jogador jogador : this.jogadores) {
            if (jogador.getCombinacaoCartas().getValor() > maior) {
                maior = jogador.getCombinacaoCartas().getValor();
                quantidade = 1;
            } else if (jogador.getCombinacaoCartas().getValor() == maior) {
                quantidade++;
            }
        }

        return quantidade > 1;
    }

    public void calcularResultado() {
        for (Jogador jogador : this.jogadores) {
            Carta[] cartas = jogador.getCartas();
            
            if (cartas[0].getNome().getNumero() == cartas[1].getNome().getNumero() && cartas[1].getNome().getNumero() == cartas[2].getNome().getNumero()) {
                jogador.setCombinacaoCartas(CombinacaoTriduEnum.TRIO);
            } else if (cartas[0].getNome().getNumero() == cartas[1].getNome().getNumero() || cartas[1].getNome().getNumero() == cartas[2].getNome().getNumero() || cartas[0].getNome().getNumero() == cartas[2].getNome().getNumero()) {
                jogador.setCombinacaoCartas(CombinacaoTriduEnum.DUPLA);
            } else {
                jogador.setCombinacaoCartas(CombinacaoTriduEnum.NENHUMA);
            }
        }
        
        if (this.calcularEmpate()) {
            this.setVencedor(null);
            return;
        }

        Collections.sort(this.jogadores, new ComparadorTridu());

        this.setVencedor(this.jogadores.get(this.jogadores.size() - 1));
    }

    public List<Jogador> getJogadores() {
        return this.jogadores;
    }
    
    public void setJogadores(List<Jogador> jogadores) {
        this.jogadores = jogadores;
    }
    
    public Baralho getBaralho() {
        return this.baralho;
    }
    
    public void setBaralho(Baralho baralho) {
        this.baralho = baralho;
    }

    public Jogador getVencedor() {
        return vencedor;
    }

    public void setVencedor(Jogador vencedor) {
        this.vencedor = vencedor;
    }

}
