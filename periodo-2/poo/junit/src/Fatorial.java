public class Fatorial {
    public static int fatorial(int n) {
        int fatorial = 1;

        for (int i = 1; i <= n; i++) {
            fatorial *= i;
        }

        return fatorial;
    }
}
