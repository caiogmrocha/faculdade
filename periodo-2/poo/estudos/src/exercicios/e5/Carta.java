package exercicios.e5;

public class Carta {
    private ValorCartaEnum valor;
    private NaipeCartaEnum naipe;

    public Carta(ValorCartaEnum valor, NaipeCartaEnum naipe) {
        this.valor = valor;
        this.naipe = naipe;
    }

    public ValorCartaEnum getNome() {
        return valor;
    }

    public void setNome(ValorCartaEnum valor) {
        this.valor = valor;
    }

    public NaipeCartaEnum getNaipe() {
        return naipe;
    }

    public void setNaipe(NaipeCartaEnum naipe) {
        this.naipe = naipe;
    }

    @Override
    public String toString() {
        return "Carta{" +
                "valor='" + valor + '\'' +
                ", naipe='" + naipe + '\'' +
                '}';
    }
}
