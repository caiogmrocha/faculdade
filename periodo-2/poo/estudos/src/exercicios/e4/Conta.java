package exercicios.e4;

public class Conta {
    public String nomeDono;
    public String numero;
    public double saldo;

    public Conta(String nomeDono, String numero, double saldo) {
        this.setNomeDono(nomeDono);
        this.setNumero(numero);
        this.setSaldo(saldo);
    }

    public String getNomeDono() {
        return nomeDono;
    }

    public void setNomeDono(String nomeDono) {
        this.nomeDono = nomeDono;
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

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    
}
