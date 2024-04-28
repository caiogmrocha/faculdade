package negocio.excecao.conta;

@SuppressWarnings("serial")
public class ContaJaExisteException extends ContaException {

    public ContaJaExisteException() {
        super("Essa conta já existe, não é possível adicioná-la novamente.");
    }
}
