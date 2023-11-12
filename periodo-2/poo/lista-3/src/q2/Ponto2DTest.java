package q2;

import java.util.Scanner;

public class Ponto2DTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite a abscissa: ");
        Double x = scanner.nextDouble();
        
        System.out.print("Digite a ordenada: ");
        Double y = scanner.nextDouble();

        Ponto2D pontoA = new Ponto2D(x, y);

        System.out.println("Coordenadas do ponto A: " + pontoA.toString());
        
        scanner.close();
        
        Ponto2D pontoB = Ponto2D.criarOposto(pontoA);
        
        System.out.println("Coordenadas do ponto B: " + pontoB.toString());
    }
}
