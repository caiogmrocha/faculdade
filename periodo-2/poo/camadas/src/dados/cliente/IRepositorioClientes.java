package dados.cliente;

import negocio.entidade.Cliente;

public interface IRepositorioClientes {

    void adicionar(Cliente cliente);

    void remover(Cliente cliente);

    void atualizar(Cliente cliente);

    Cliente consultar(Cliente cliente);

    Cliente consultar(String cpf);

    void listar();

    boolean existe(String cpf);
}
