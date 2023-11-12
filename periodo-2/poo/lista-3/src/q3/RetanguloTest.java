package q3;

import java.util.ArrayList;

import q2.Ponto2D;

public class RetanguloTest {
    public static void main(String[] args) {
        Retangulo retangulo = new Retangulo(
            new Ponto2D(0.0, 3.0),
            new Ponto2D(3.0, 0.0)
        );

        ArrayList<Ponto2D> pontos = new ArrayList<Ponto2D>();

        pontos.add(new Ponto2D(3.0, 4.0)); // nao contem
        pontos.add(new Ponto2D(4.0, 3.0)); // nao contem
        pontos.add(new Ponto2D(-1.0, 3.0)); // nao contem
        pontos.add(new Ponto2D(3.0, -1.0)); // nao contem
        pontos.add(new Ponto2D(2.0, 2.0)); // contem

        for (Ponto2D ponto : pontos) {
            if (retangulo.contem(ponto)) {
                System.out.println(String.format("O ponto %s pertence ao retangulo %s", ponto.toString(), retangulo.toString())); 
            } else {
                System.out.println(String.format("O ponto %s não pertence ao retangulo %s", ponto.toString(), retangulo.toString())); 
            }
        }
    }
}
