package dados.cliente;

import negocio.entidade.Cliente;

import java.util.ArrayList;

public class RepositorioClientesArrayList implements IRepositorioClientes {

    private ArrayList<Cliente> array;

    public RepositorioClientesArrayList() {
        array = new ArrayList<Cliente>();
    }

    @Override
    public void adicionar(Cliente cliente) {
        array.add(cliente);
    }

    @Override
    public void remover(Cliente cliente) {
        int indice = array.indexOf(cliente);
        if (indice != -1) {
            array.remove(cliente);
        }
    }

    @Override
    public Cliente consultar(String cpf) {
        Cliente clienteProcurado = null;
        for (Cliente cliente : array) {
            if (cliente.getCpf().equals(cpf)) {
                clienteProcurado = cliente;
                break;
            }
        }
        return clienteProcurado;
    }

    @Override
    public void atualizar(Cliente cliente) {
        int indice = array.indexOf(cliente);
        if (indice != -1) {
            array.set(indice, cliente);
        }
    }

    @Override
    public Cliente consultar(Cliente cliente) {
        Cliente clienteProcurado = null;
        for (Cliente c : array) {
            if (c.equals(cliente)) {
                clienteProcurado = c;
                break;
            }
        }
        return clienteProcurado;
    }

    @Override
    public void listar() {
        for (Cliente cliente : array) {
            System.out.println(cliente);
        }
    }

    @Override
    public boolean existe(String cpf) {
        boolean resultado = false;
        for (Cliente cliente : array) {
            if (cliente.getCpf().equals(cpf)) {
                resultado = true;
                break;
            }
        }
        return resultado;
    }

}
