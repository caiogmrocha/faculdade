import aula03.Caneta;

public class App {
    public static void main(String[] args) throws Exception {
        Caneta caneta = new Caneta("BIC", "preta", 0.5, 100, true);

        caneta.rabiscar();
    }
}
