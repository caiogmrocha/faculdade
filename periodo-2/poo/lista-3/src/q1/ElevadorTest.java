package q1;

public class ElevadorTest {
    public static void main(String[] args) {
        Elevador elevador = new Elevador(false, false, true, false, 8, 0);

        elevador.receberPessoas(4);
        elevador.subir(5);
        elevador.liberarPessoas(2);
        elevador.descer(2);

        // Deveriam lançar erros

        elevador.subir(500);
        elevador.descer(500);
        elevador.receberPessoas(60);
    }
}