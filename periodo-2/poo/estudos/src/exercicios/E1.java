package exercicios;

import java.util.Scanner;

public class E1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int anos = scanner.nextInt();
        int meses = scanner.nextInt();
        int dias = scanner.nextInt();

        int idadeEmDias = anos * 365 + meses * 30 + dias;

        System.out.println(String.format("%d dias", idadeEmDias));

        scanner.close();
    }
}
