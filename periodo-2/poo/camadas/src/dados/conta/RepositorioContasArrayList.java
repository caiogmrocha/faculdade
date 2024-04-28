package dados.conta;

import negocio.entidade.Cliente;
import negocio.entidade.ContaAbstrata;

import java.util.ArrayList;

public class RepositorioContasArrayList implements IRepositorioContas {

    private ArrayList<ContaAbstrata> array;

    public RepositorioContasArrayList() {
        array = new ArrayList<ContaAbstrata>();
    }

    @Override
    public void adicionar(ContaAbstrata conta) {
        array.add(conta);
    }

    @Override
    public void atualizar(ContaAbstrata conta) {
        int indice = array.indexOf(conta);
        if (indice != -1) {
            array.set(indice, conta);
        }
    }

    @Override
    public void remover(ContaAbstrata conta) {
        int indice = array.indexOf(conta);
        if (indice != -1) {
            array.remove(conta);
        }
    }

    @Override
    public ContaAbstrata consultar(ContaAbstrata conta) {
        ContaAbstrata contaProcurada = null;
        int indice = array.indexOf(conta);
        if (indice != -1) {
            contaProcurada = array.get(indice);
        }
        return contaProcurada;
    }

    public ArrayList<ContaAbstrata> consultarPorCliente(Cliente cliente) {
        ArrayList<ContaAbstrata> contas = new ArrayList<ContaAbstrata>();
        for (ContaAbstrata conta : array) {
            if (conta.getCliente().getCpf().equals(cliente.getCpf())) {
                contas.add(conta);
            }
        }
        return contas;
    }

    @Override
    public ContaAbstrata consultar(String numero) {
        ContaAbstrata contaProcurada = null;
        for (ContaAbstrata conta : array) {
            if (conta.getNumero().equals(numero)) {
                contaProcurada = conta;
                break;
            }
        }
        return contaProcurada;
    }

    @Override
    public void listar() {
        for (ContaAbstrata conta : array) {
            System.out.println(conta);
        }

    }

    @Override
    public boolean existe(String numero) {
        boolean resultado = false;
        for (ContaAbstrata conta : array) {
            if (conta.getNumero().equals(numero)) {
                resultado = true;
                break;
            }
        }
        return resultado;
    }

    @Override
    public ArrayList<ContaAbstrata> consultar(Cliente cliente) {
        ArrayList<ContaAbstrata> contas = new ArrayList<ContaAbstrata>();
        for (ContaAbstrata conta : array) {
            if (conta.getCliente().equals(cliente)) {
                contas.add(conta);
            }
        }
        return contas;
    }

}
