package negocio.entidade;

public class ContaBonificada extends Conta {

    private double bonus;
    private double taxaBonus;

    public ContaBonificada() {
        super();
        this.taxaBonus = 0.1;
    }

    public ContaBonificada(Cliente cliente, String numero, double saldo) {
        super(cliente, numero, saldo);
        this.taxaBonus = 0.1;
    }

    @Override
    public void creditar(double valor) {
        if (valor < 0) {
            throw new IllegalArgumentException();
        }
        bonus += (valor * taxaBonus);
        super.creditar(valor);
    }

    public void renderBonus() {
        super.creditar(bonus);
        bonus = 0;
    }
}
