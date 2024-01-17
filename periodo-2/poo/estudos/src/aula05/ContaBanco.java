package aula05;

public class ContaBanco {
    public int numConta;
    protected String tipo;
    private String dono;
    private double saldo;
    private boolean status;

    public void abrirConta(String tipo) {
        this.setTipo(tipo);
        this.setStatus(true);

        if (tipo == "CC") {
            this.setSaldo(50);
        } else if (tipo == "CP") {
            this.setSaldo(150);
        }
    }

    public void fecharConta() {
        if (this.getSaldo() > 0) {
            System.out.println("Esta conta possui dinheiro!");
        } else if (this.getSaldo() < 0) {
            System.out.println("Esta conta está em débito!");
        } else {
            this.setStatus(false);
        }
    }

    public void depositar(double valor) {
        if (this.isStatus()) {
            this.setSaldo(this.getSaldo() + valor);
        } else {
            System.out.println("Impossível depositar");
        }
    }

    public double sacar(double valor) {
        if (this.isStatus()) {
            if (this.getSaldo() > valor) {
                this.setSaldo(this.getSaldo() - valor);

                return valor;
            } else {
                System.out.println("Saldo insuficiente!");
            }
        } else {
            System.out.println("Impossível sacar!");
        }

        return -1;
    }

    public void pagarMensal() {
        double debito = switch (this.getTipo()) {
            case "CC" -> 12;
            case "CP" -> 20;
            default -> 0;
        };

        if (this.isStatus()) {
            if (this.getSaldo() > debito) {
                this.setSaldo(this.getSaldo() - debito);
            } else {
                System.out.println("Saldo insuficiente!");
            }
        } else {
            System.out.println("Impossível pagar!");
        }
    }

    public ContaBanco(int numConta, String tipo, String dono, double saldo, boolean status) {
        this.numConta = numConta;
        this.tipo = tipo;
        this.dono = dono;
        this.saldo = saldo;
        this.status = status;
    }

    public int getnumConta() {
        return numConta;
    }
    public void setnumConta(int numConta) {
        this.numConta = numConta;
    }
    public String getTipo() {
        return tipo;
    }
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }
    public String getDono() {
        return dono;
    }
    public void setDono(String dono) {
        this.dono = dono;
    }
    public double getSaldo() {
        return saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    public boolean isStatus() {
        return status;
    }
    public void setStatus(boolean status) {
        this.status = status;
    }

    
}
