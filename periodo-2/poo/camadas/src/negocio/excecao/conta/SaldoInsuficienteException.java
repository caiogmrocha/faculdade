package negocio.excecao.conta;

@SuppressWarnings("serial")
public class SaldoInsuficienteException extends ContaException {

    private double saldo;
    private double valor;

    public SaldoInsuficienteException(double saldo, double valor) {
        super("Saldo insuficiente. Saldo atual: "+saldo+"; Valor desejado: "+valor);
        this.saldo = saldo;
        this.valor = valor;
    }

    public double getSaldo() {
        return saldo;
    }

    public double getValor() {
        return valor;
    }
}
