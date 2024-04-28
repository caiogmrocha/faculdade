package negocio.excecao.conta;

@SuppressWarnings("serial")
public class ContaNaoExisteException extends ContaException {

    public ContaNaoExisteException() {
        super("Conta não existe");
    }

}
