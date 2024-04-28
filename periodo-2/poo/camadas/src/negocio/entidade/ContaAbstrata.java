package negocio.entidade;

import negocio.excecao.conta.SaldoInsuficienteException;

public abstract class ContaAbstrata {

    protected Cliente cliente;
    protected String numero;
    protected double saldo;

    public ContaAbstrata() {

    }

    public ContaAbstrata(Cliente cliente, String numero, double saldo) {
        this.cliente = cliente;
        this.numero = numero;
        this.saldo = saldo;
    }

    public boolean valida(){
        if(cliente == null || numero == null || numero =="" || saldo<0) return false;
        else return true;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public double getSaldo() {
        return saldo;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public void creditar(double valor) {
        if (valor < 0) {
            throw new IllegalArgumentException();
        }
        saldo += valor;
    }

    public abstract void debitar(double valor) throws SaldoInsuficienteException;

    public void transferir(ContaAbstrata conta, double valor) throws SaldoInsuficienteException {
        if (valor < 0) {
            throw new IllegalArgumentException();
        }
        this.debitar(valor);
        conta.creditar(valor);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof ContaAbstrata) {
            ContaAbstrata conta2 = (ContaAbstrata) obj;
            if (this.numero.equals(conta2.getNumero())) {
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {
        return "numero da conta: " + numero + "; titular: " + cliente.getNome();
    }
}
