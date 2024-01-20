import exercicios.e5.Baralho;
import exercicios.e5.Carta;

public class App {
    public static void main(String[] args) {
        Baralho baralho = new Baralho();

        baralho.embaralhar();
        baralho.embaralhar();
        baralho.embaralhar();
        baralho.embaralhar();
        baralho.embaralhar();

        Carta carta = baralho.darCarta();

        System.out.println(carta);

        // baralho.imprimirBaralho();
    }
}
