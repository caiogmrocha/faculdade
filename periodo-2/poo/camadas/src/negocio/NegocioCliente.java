package negocio;

import dados.cliente.IRepositorioClientes;
import negocio.entidade.Cliente;
import negocio.excecao.cliente.ClienteJaExisteException;
import negocio.excecao.cliente.ClienteNaoExisteException;

public class NegocioCliente {

    private IRepositorioClientes repositorio;

    public NegocioCliente(IRepositorioClientes repositorio) {
        this.repositorio = repositorio;
    }

    public void adicionar(Cliente cliente) throws ClienteJaExisteException {
        boolean existe = repositorio.existe(cliente.getCpf());
        if (existe) {
            throw new ClienteJaExisteException();
        } else {
            repositorio.adicionar(cliente);
        }
    }

    public void remover(String cpf) throws ClienteNaoExisteException {
        Cliente cliente = repositorio.consultar(cpf);
        if (cliente != null) {
            //checar se o cliente não tem nenhuma conta
            repositorio.remover(cliente);
        } else {
            throw new ClienteNaoExisteException();
        }
    }

    public Cliente consultar(String cpf) throws ClienteNaoExisteException {
        Cliente cliente = repositorio.consultar(cpf);
        if (cliente == null) {
            throw new ClienteNaoExisteException();
        } else {
            return cliente;
        }
    }

    public void atualizar(Cliente cliente) throws ClienteNaoExisteException {
        Cliente c = repositorio.consultar(cliente);
        if (c != null) {
            repositorio.atualizar(cliente);
        } else {
            throw new ClienteNaoExisteException();
        }
    }

}
