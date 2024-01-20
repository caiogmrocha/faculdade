package exercicios;

public class E2 {
    public static void main(String[] args) {
        double media1 = (8 + 9 + 7) / 3;
        double media2 = (4 + 5 + 6) / 3;
        double somaMedias = media1 + media2;
        double mediaMedias = somaMedias / 2;

        System.out.println(String.format("media1: %.2f", media1));
        System.out.println(String.format("media2: %.2f", media2));
        System.out.println(String.format("somaMedias: %.2f", somaMedias));
        System.out.println(String.format("mediaMedias: %.2f", mediaMedias));
    }
}
