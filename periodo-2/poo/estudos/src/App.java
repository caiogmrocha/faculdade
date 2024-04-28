import java.util.ArrayList;

import exercicios.e5.Baralho;
import exercicios.e5.Carta;
import exercicios.e5.Jogador;
import exercicios.e5.Tridu;

public class App {
    public static void main(String[] args) {
        Baralho baralho = new Baralho();
        ArrayList<Jogador> jogadores = new ArrayList<Jogador>();

        jogadores.add(new Jogador("Jogador 1", new Carta[]{}, null));
        jogadores.add(new Jogador("Jogador 2", new Carta[]{}, null));
        jogadores.add(new Jogador("Jogador 3", new Carta[]{}, null));
        jogadores.add(new Jogador("Jogador 4", new Carta[]{}, null));

        Tridu tridu = new Tridu(jogadores, baralho);
        
        tridu.sortearCartas("Jogador 1");
        tridu.sortearCartas("Jogador 2");
        tridu.sortearCartas("Jogador 3");
        tridu.sortearCartas("Jogador 4");
        
        tridu.calcularResultado();

        tridu.mostrarCartas();

        if (tridu.getVencedor() == null) {
            System.out.println("Vencedor: Nenhum");
        } else {
            System.out.println("Vencedor: " + tridu.getVencedor().getNome());
        }

    }
}
