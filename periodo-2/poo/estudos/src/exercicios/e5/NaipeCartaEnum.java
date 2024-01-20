package exercicios.e5;

public enum NaipeCartaEnum {
    COPAS("Copas"),
    ESPADAS("Espadas"),
    OUROs("Ouros"),
    PAUS("Paus");

    private String exibicao;

    private NaipeCartaEnum(String exibicao) {
        this.exibicao = exibicao;
    }

    public String getExibicao() {
        return this.exibicao;
    }
}
