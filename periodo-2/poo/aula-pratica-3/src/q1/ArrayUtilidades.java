package q1;

public class ArrayUtilidades {
    public static void main(String[] args) {
        ArrayUtilidades au = new ArrayUtilidades();
        
        int[] inteiros = { 1, -1, 2, -2, 3, 4, -100 };
        boolean[] booleanos = au.processarInteiros(inteiros);

        for (int i = 0; i < booleanos.length; i++) {
            System.out.println(String.format(
                "inteiros[%d] = %d; booleanos[%d] = %b",
                i,
                inteiros[i],
                i,
                booleanos[i]
            ));
        }
    }

    public boolean[] processarInteiros(int[] inteiros) {
        boolean[] booleanos = new boolean[inteiros.length];
        
        for (int i = 0; i < inteiros.length; i++) {
            booleanos[i] = inteiros[i] > 0;
        }

        return booleanos;
    }
}