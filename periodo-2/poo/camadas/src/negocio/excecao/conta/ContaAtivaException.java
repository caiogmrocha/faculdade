package negocio.excecao.conta;

@SuppressWarnings("serial")
public class ContaAtivaException extends ContaException {

    public ContaAtivaException() {
        super("Essa conta não pode ser removida porque ainda está ativa.");
    }
}
