package negocio.excecao.conta;

@SuppressWarnings("serial")
public class ContaException extends Exception {

    private String msg;

    public ContaException(String msg) {
        super(msg);
        this.msg = msg;
    }

    @Override
    public String getMessage() {
        return msg;
    }

}
