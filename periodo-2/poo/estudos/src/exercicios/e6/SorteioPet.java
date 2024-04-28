package exercicios.e6;

import java.util.Random;

public class SorteioPet {
	public Animal[] pets;

	public SorteioPet(Animal[] pets) {
		this.pets = pets;
	}

	public Animal sortear() {
		return this.pets[new Random().nextInt(this.pets.length)];
	}
}