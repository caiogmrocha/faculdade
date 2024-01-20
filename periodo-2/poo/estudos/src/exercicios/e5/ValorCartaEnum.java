package exercicios.e5;
 
public enum ValorCartaEnum {
    AS(1, "Ás"),
    DOIS(2, "Dois"),
    TRES(2, "Três"),
    QUATRO(2, "Quatro"),
    CINCO(2, "Cinco"),
    SEIS(2, "Seis"),
    SETE(2, "Sete"),
    OITO(2, "Oito"),
    NOVE(2, "Nove"),
    DEZ(2, "Dez"),
    VALETE(2, "Valete"),
    DAMA(2, "Dama"),
    REI(2, "Rei");

    private int numero;
    private String exibicao;

    private ValorCartaEnum(int numero, String exibicao) {
        this.numero = numero;
        this.exibicao = exibicao;
    }

    public int getNumero() {
        return this.numero;
    }

    public String getExibicao() {
        return this.exibicao;
    }
}
