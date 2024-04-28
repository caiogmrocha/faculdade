package exercicios.e6;

public class Cachorro implements Animal {
	public String raca;

	public Cachorro(String raca) {
		this.raca = raca;
	}

	@Override
	public void emitirSom() {
		System.out.println("Au au!");
	}
}
