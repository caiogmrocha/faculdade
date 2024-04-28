package negocio.excecao.cliente;

@SuppressWarnings("serial")
public class ClienteJaExisteException extends ClienteException {

    public ClienteJaExisteException() {
        super("Esse cliente já existe, não é possível adicioná-lo novamente.");
    }
}
