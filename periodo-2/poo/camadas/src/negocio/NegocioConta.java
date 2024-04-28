package negocio;

import dados.conta.IRepositorioContas;
import dados.conta.RepositorioCheioException;
import negocio.entidade.Cliente;
import negocio.entidade.ContaAbstrata;
import negocio.excecao.conta.ContaAtivaException;
import negocio.excecao.conta.ContaJaExisteException;
import negocio.excecao.conta.ContaNaoExisteException;
import negocio.excecao.conta.SaldoInsuficienteException;

import java.util.ArrayList;

public class NegocioConta {

    private IRepositorioContas repositorio;

    public NegocioConta(IRepositorioContas repositorio) {
        this.repositorio = repositorio;
    }

    public void adicionar(ContaAbstrata conta)
            throws ContaJaExisteException, RepositorioCheioException {
        boolean existe = repositorio.existe(conta.getNumero());
        if (existe) {
            throw new ContaJaExisteException();
        } else {
            repositorio.adicionar(conta);
        }
    }

    public void remover(String numero) throws ContaNaoExisteException, ContaAtivaException {
        ContaAbstrata conta = repositorio.consultar(numero);
        if (conta != null) {
            if (conta.getSaldo() == 0) {
                repositorio.remover(conta);
            } else {
                throw new ContaAtivaException();
            }
        } else {
            throw new ContaNaoExisteException();
        }
    }

    public ContaAbstrata consultar(String numero)
            throws ContaNaoExisteException {
        ContaAbstrata conta = repositorio.consultar(numero);
        if (conta == null) {
            throw new ContaNaoExisteException();
        } else {
            return conta;
        }
    }

    public ArrayList<ContaAbstrata> consultarPorCliente(Cliente cliente)
            throws ContaNaoExisteException {
        ArrayList<ContaAbstrata> contas = repositorio.consultar(cliente);
        if (contas == null || contas.isEmpty()) {
            throw new ContaNaoExisteException();
        } else {
            return contas;
        }
    }

    public void creditar(String numero, double valor)
            throws ContaNaoExisteException {
        ContaAbstrata conta = repositorio.consultar(numero);
        if (conta != null) {
            conta.creditar(valor);
        } else {
            throw new ContaNaoExisteException();
        }
    }

    public void debitar(String numero, double valor)
            throws ContaNaoExisteException, SaldoInsuficienteException {
        ContaAbstrata conta = repositorio.consultar(numero);
        if (conta != null) {
            conta.debitar(valor);
        } else {
            throw new ContaNaoExisteException();
        }
    }

    public void transferir(String origem, String destino, double valor)
            throws ContaNaoExisteException, SaldoInsuficienteException {
        ContaAbstrata contaOrigem = repositorio.consultar(origem);
        ContaAbstrata contaDestino = repositorio.consultar(destino);
        if (contaOrigem != null && contaDestino != null) {
            contaOrigem.transferir(contaDestino, valor);
        } else {
            throw new ContaNaoExisteException();
        }
    }

    public void atualizar(ContaAbstrata conta) throws ContaNaoExisteException {
        ContaAbstrata c = repositorio.consultar(conta);
        if (c != null) {
            repositorio.atualizar(conta);
        } else {
            throw new ContaNaoExisteException();
        }
    }

}
