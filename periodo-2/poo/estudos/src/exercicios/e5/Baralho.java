package exercicios.e5;

import java.util.Arrays;
import java.util.Random;

public class Baralho {
    private Carta[] cartas;
    private int tamanho;

    public Baralho() {
        this.tamanho = 56;
        this.cartas = new Carta[this.tamanho];

        int c = 0;

        for (ValorCartaEnum valor : ValorCartaEnum.values()) {
            for (NaipeCartaEnum naipe : NaipeCartaEnum.values()) {
                this.cartas[c++] = new Carta(valor, naipe);
            }
        }
    }

    public void embaralhar() {
        int posicao1 = new Random().nextInt(this.tamanho);
        int posicao2 = new Random().nextInt(this.tamanho);

        Carta temp = this.cartas[posicao1];
        this.cartas[posicao1] = this.cartas[posicao2];
        this.cartas[posicao2] = temp;
    }

    public Carta darCarta() {
        if (this.temCarta()) {
            this.tamanho--;
            Carta temp = this.cartas[this.tamanho - 1];

            this.cartas[this.tamanho] = null;

            return temp;
        }

        return null;
    }

    public boolean temCarta() {
        if (this.cartas == null) {
            return false;
        }

        for (int i = 0; i < this.cartas.length; i++) {
            if (this.cartas[i] != null) {
                return true;
            }
        }

        return false;
    }
    
    public void imprimirBaralho() {
        for (Carta carta : this.cartas) {
            System.out.println(carta);
        }
    }

    @Override
    public String toString() {
        return "Baralho{" +
                "cartas=" + Arrays.toString(cartas) +
                '}';
    }
}
