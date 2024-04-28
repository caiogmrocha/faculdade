package exercicios.e6;

public class Gato implements Animal {
	public String raca;

	public Gato(String raca) {
		this.raca = raca;
	}

	@Override
	public void emitirSom() {
		System.out.println("Miau!");
	}
}