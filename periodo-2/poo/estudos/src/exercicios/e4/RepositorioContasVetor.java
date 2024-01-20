package exercicios.e4;

public class RepositorioContasVetor implements RepositorioContas {
    private Conta[] contas;
    public RepositorioContasVetor() {
        this.contas = new Conta[20];
    }

    public void printAll() {
        for (int i = 0; i < this.contas.length; i++) {
            if (this.contas[i] != null) {
                System.out.println(this.contas[i].getNumero());
            }
        }
    }

    @Override
    public boolean delete(String numero) {
        for (int i = 0; i < this.contas.length; i++) {
            if (this.contas[i] != null && this.contas[i].getNumero().equals(numero)) {
                this.contas[i] = null;

                return true;
            }
        }

        return false;
    }

    @Override
    public Conta[] getAll() {        
        return this.contas;
    }

    @Override
    public Conta getOne(String numero) {
        for (int i = 0; i < this.contas.length; i++) {
            if (this.contas[i] != null && this.contas[i].getNumero().equals(numero)) {
                return this.contas[i];
            }
        }
        
        return null;
    }

    @Override
    public void insert(Conta conta) {
        int tamanho = 0;

        for (int i = 0; i < this.contas.length; i++) {
            if (this.contas[i] != null) {
                tamanho++;
            } else {
                break;
            }
        }

        if (tamanho == this.contas.length) {
            Conta[] novoContas = new Conta[this.contas.length + 1];

            for (int i = 0; i < this.contas.length; i++) {
                if (this.contas[i] != null) {
                    novoContas[i] = this.contas[i];
                }
            }
            
            novoContas[this.contas.length] = conta;

            this.contas = novoContas;
        } else {
            for (int i = 0; i < this.contas.length; i++) {
                if (this.contas[i] == null) {
                    this.contas[i] = conta;
                    break;
                }
            }
        }
    }

    @Override
    public void update(Conta conta, String numero) {
        for (int i = 0; i < this.contas.length; i++) {
            if (this.contas[i] != null && this.contas[i].getNumero().equals(numero)) {
                this.contas[i] = conta;
                break;
            }
        }

        System.out.println("RepositorioContasVetor.update(): Conta não encontrada.");
    }
}
