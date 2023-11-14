package q2;

public class Carta {
    String nome;
    String naipe;

    public Carta(String nome, String naipe) {
        this.setNome(nome);
        this.setNaipe(naipe);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNaipe() {
        return naipe;
    }

    public void setNaipe(String naipe) {
        this.naipe = naipe;
    }
}
