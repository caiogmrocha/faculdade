package negocio.entidade;

import negocio.excecao.conta.SaldoInsuficienteException;

public class ContaImposto extends ContaAbstrata {

    private double taxaImposto;

    public ContaImposto() {
        super();
        this.taxaImposto = 0.02;
    }

    public ContaImposto(Cliente cliente, String numero, double saldo) {
        super(cliente, numero, saldo);
        this.taxaImposto = 0.02;
    }

    @Override
    public void debitar(double valor) throws SaldoInsuficienteException {
        if (valor < 0) {
            throw new IllegalArgumentException();
        }
        double valorComImposto = valor + (valor * taxaImposto);

        if (valorComImposto > this.saldo) {
            throw new SaldoInsuficienteException(saldo, valor);
        } else {
            saldo -= valorComImposto;
        }
    }

}
