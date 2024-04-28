package exercicios.e6;

public class E6 {
    public static void main(String[] args) throws Exception {
		SorteioPet sorteio = new SorteioPet(new Animal[]{
			new Cachorro("Husky"),
			new Cachorro("Pastor Alemão"),
			new Gato("Vira Lata"),
		});

		Animal pet = sorteio.sortear();

        pet.emitirSom();
	}
}
