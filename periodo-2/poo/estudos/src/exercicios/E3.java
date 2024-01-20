package exercicios;

import java.util.Scanner;

public class E3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double saldo = scanner.nextDouble();

        System.out.println(String.format("Saldo reajustado: %.2f", saldo + (saldo * 0.01)));

        scanner.close();
    }
}
