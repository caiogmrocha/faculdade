package negocio.entidade;

public class Endereco {

    private String cep;
    private String numero;
    private String complemento;

    public Endereco() {

    }

    public Endereco(String cep, String numero, String complemento) {
        this.cep = cep;
        this.numero = numero;
        this.complemento = complemento;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getComplemento() {
        return complemento;
    }

    public void setComplemento(String complemento) {
        this.complemento = complemento;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Endereco) {
            Endereco endereco = (Endereco) obj;
            if (this.cep.equals(endereco.getCep()) && this.numero.equals(endereco.getNumero())
                    && this.complemento.equals(endereco.getComplemento())) {
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {
        return cep + ", " + numero + ", " + complemento;
    }

}
