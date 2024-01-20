package exercicios.e5;

public enum CombinacaoTriduEnum {
    TRIO(1),
    DUPLA(2),
    NENHUMA(3),
    INDEFINIDO(4);

    private int valor;

    CombinacaoTriduEnum(int valor) {
        this.valor = valor;
    }

    public int getValor() {
        return valor;
    }
}
