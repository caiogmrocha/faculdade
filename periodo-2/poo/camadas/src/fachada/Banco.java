package fachada;

import dados.cliente.RepositorioClientesArrayList;
import dados.conta.RepositorioCheioException;
import dados.conta.RepositorioContasVetor;
import negocio.NegocioCliente;
import negocio.NegocioConta;
import negocio.entidade.*;
import negocio.excecao.cliente.ClienteJaExisteException;
import negocio.excecao.cliente.ClienteNaoExisteException;
import negocio.excecao.conta.*;

import java.util.ArrayList;

public class Banco {

    private NegocioConta cadastroConta;
    private NegocioCliente cadastroCliente;

    public Banco() {
        cadastroConta = new NegocioConta(new RepositorioContasVetor());
        cadastroCliente = new NegocioCliente(new RepositorioClientesArrayList());
    }

    public void adicionarCliente(
        String codigo,
        String nome,
        String cep,
        String numero,
        String complemento
    ) throws ClienteJaExisteException {
        Endereco endereco = new Endereco(cep, numero, complemento);
        Cliente cliente = new Cliente(nome, codigo, endereco);
        cadastroCliente.adicionar(cliente);
    }

    public void adicionarConta(String numeroConta, int tipoConta, String cpfCliente, double saldo) throws ClienteNaoExisteException, ContaJaExisteException, RepositorioCheioException, TipoContaNaoExisteException {
        ContaAbstrata conta = null;
        Cliente cliente = cadastroCliente.consultar(cpfCliente);//recupera o cadastro do cliente

        //cria a conta conforme o tipo especificado
        switch (tipoConta) {
            case 1: // Tipo Conta
                conta = new Conta(cliente, numeroConta, saldo);
                break;
            case 2: // Tipo Poupanca
                conta = new Poupanca(cliente, numeroConta, saldo);
                break;
            case 3: // Tipo ContaBonificada
                conta = new ContaBonificada(cliente, numeroConta, saldo);
                break;
            case 4: // Tipo ContaImposto
                conta = new ContaImposto(cliente, numeroConta, saldo);
                break;
            default:
                throw new TipoContaNaoExisteException();
        }

        cadastroConta.adicionar(conta); //adiciona conta
    }

    public void removerCliente(String cpf) throws ClienteNaoExisteException, ContaNaoExisteException, ContaAtivaException {
        Cliente cliente = cadastroCliente.consultar(cpf);
        ArrayList<ContaAbstrata> contas = cadastroConta.consultarPorCliente(cliente);

        for (ContaAbstrata c : contas) {
            cadastroConta.remover(c.getNumero());
        }

        cadastroCliente.remover(cpf);
    }

    public void atualizarCliente(String codigo, String nome, String cep, String numero, String complemento) throws ClienteNaoExisteException {
        Cliente cliente = cadastroCliente.consultar(codigo);
        cliente.setNome(nome);

        Endereco endereco = cliente.getEndereco();
        endereco.setCep(cep);
        endereco.setNumero(numero);
        endereco.setComplemento(complemento);

        cliente.setEndereco(endereco);
    }

    public void removerConta(String numeroConta) throws ContaNaoExisteException, ContaAtivaException {
        cadastroConta.remover(numeroConta);
    }

    public void transferir(String numeroConta1, String numeroConta2, double valor) throws ContaNaoExisteException, SaldoInsuficienteException {
        cadastroConta.transferir(numeroConta1, numeroConta2, valor);
    }

    public void debitar(String numeroConta, double valor) throws ContaNaoExisteException, SaldoInsuficienteException {
        cadastroConta.debitar(numeroConta, valor);
    }

    public void creditar(String numeroConta, double valor) throws ContaNaoExisteException {
        cadastroConta.creditar(numeroConta, valor);
    }

    public String consultarCliente(String codigo) throws ClienteNaoExisteException {
        Cliente cliente = cadastroCliente.consultar(codigo);
        Endereco endereco = cliente.getEndereco();
        String resultado = "Nome: " + cliente.getNome() + "\n";
        resultado += "Endereco: " + endereco.getCep() + ", " + endereco.getNumero() + ", " + endereco.getComplemento() + "\n";
        return resultado;
    }

    public String consultarConta(String numeroConta) throws ContaNaoExisteException, ClienteNaoExisteException {
        ContaAbstrata conta = cadastroConta.consultar(numeroConta);
        Cliente cliente = cadastroCliente.consultar(conta.getCliente().getCpf());
        String resultado = "Cliente: " + cliente.getNome() + "\n";
        resultado += "Conta: " + numeroConta + "\n";
        resultado += "Saldo: " + conta.getSaldo() + "\n";
        return resultado;
    }

}
