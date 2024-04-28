package dados.conta;

import negocio.entidade.Cliente;
import negocio.entidade.ContaAbstrata;

import java.util.ArrayList;

public interface IRepositorioContas {

    void adicionar(ContaAbstrata conta) throws RepositorioCheioException;

    void remover(ContaAbstrata conta);

    void atualizar(ContaAbstrata conta);

    boolean existe(String numero);

    ContaAbstrata consultar(ContaAbstrata conta);

    ContaAbstrata consultar(String numero);

    ArrayList<ContaAbstrata> consultar(Cliente cliente);

    void listar();
}
