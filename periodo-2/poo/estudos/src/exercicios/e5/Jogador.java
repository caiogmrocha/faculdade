package exercicios.e5;

public class Jogador {
    private String nome;
    private Carta[] cartas;

    public Jogador(String nome, Carta[] cartas) {
        this.nome = nome;
        this.cartas = cartas;
    }

    public void receberCartas(Carta[] cartas) {
        this.setCartas(cartas);
    }

    public void devolverCartas(Baralho baralho) {
        baralho.setCartas(cartas);

        this.setCartas(new Carta[]{});
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Carta[] getCartas() {
        return cartas;
    }

    public void setCartas(Carta[] cartas) {
        this.cartas = cartas;
    }
}
