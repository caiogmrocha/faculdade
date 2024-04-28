package negocio.entidade;

public class Cliente {

    private String cpf;
    private String nome;
    private Endereco endereco;

    public Cliente(String cpf, String nome, Endereco endereco) {
        this.nome = nome;
        this.cpf = cpf;
        this.endereco = endereco;
    }

    public Cliente(String cpf, String nome) {
        this.nome = nome;
        this.cpf = cpf;
        this.endereco = null;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public Endereco getEndereco() {
        return this.endereco;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Cliente) {
            Cliente cliente = (Cliente) obj;
            if (this.cpf.equals(cliente.getCpf())) {
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {
        return "nome do cliente: " + nome + "; cpf: " + cpf + "; endereco: " + endereco.toString();
    }
}
