package dados.conta;

public class RepositorioCheioException extends Exception {

    private static final long serialVersionUID = 1L;

    public RepositorioCheioException() {
        super("<Não é possível adicionar a conta porque o repositório está cheio.>");
    }
}
