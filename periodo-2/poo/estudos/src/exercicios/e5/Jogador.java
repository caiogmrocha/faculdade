package exercicios.e5;

public class Jogador {
    private String nome;
    private Carta[] cartas;
    private CombinacaoTriduEnum combinacaoCartas;

    public Jogador(String nome, Carta[] cartas, CombinacaoTriduEnum combinacaoCartas) {
        this.nome = nome;
        this.cartas = cartas;
        this.combinacaoCartas = combinacaoCartas;
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

    public CombinacaoTriduEnum getCombinacaoCartas() {
        return combinacaoCartas;
    }

    public void setCombinacaoCartas(CombinacaoTriduEnum combinacaoCartas) {
        this.combinacaoCartas = combinacaoCartas;
    }

    @Override
    public String toString() {

        System.out.println(cartas);

        String retorno = "Jogador{" +
                "nome='" + nome + "'" +
                ", cartas=";

        for (Carta carta : cartas) {
            retorno += carta.toString() + ", ";
        }

        retorno += ", combinacaoCartas=" + combinacaoCartas +
                '}';

        return retorno;
    }
}
