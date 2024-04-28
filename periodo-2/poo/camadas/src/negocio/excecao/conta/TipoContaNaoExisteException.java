package negocio.excecao.conta;

@SuppressWarnings("serial")
public class TipoContaNaoExisteException extends ContaException {

    public TipoContaNaoExisteException() {
        super("Tipo de conta inválido!");
    }

}
