package negocio.entidade;

import negocio.excecao.conta.SaldoInsuficienteException;

public class Conta extends ContaAbstrata {

    public Conta() {
        super();
    }

    public Conta(Cliente cliente, String numero, double saldo) {
        super(cliente, numero, saldo);
    }

    @Override
    public void debitar(double valor) throws SaldoInsuficienteException {
        if (valor < 0) {
            throw new IllegalArgumentException();
        }

        if (saldo < valor) {
            throw new SaldoInsuficienteException(saldo, valor);
        } else {
            saldo -= valor;
        }
    }

}
