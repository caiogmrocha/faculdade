package dados.conta;

import negocio.entidade.Cliente;
import negocio.entidade.ContaAbstrata;

import java.util.ArrayList;

public class RepositorioContasVetor implements IRepositorioContas {

    private ContaAbstrata[] contas;
    private int indice; //sinaliza a posicao disponivel para armazenar uma conta no vetor
    private static final int TAMANHO = 5;

    public RepositorioContasVetor() {
        contas = new ContaAbstrata[TAMANHO];
        indice = 0;
    }

    private void atualizarIndice() {
        this.indice = -1;
        for (int i = 0; i < this.contas.length; i++) {
            if (this.contas[i] == null) {
                this.indice = i;
                break;
            }
        }
    }

    private int procurarIndice(String numero) {
        int indiceProcurado = -1;

        for (int i = 0; i < this.contas.length; i++) {
            if (this.contas[i] != null && this.contas[i].getNumero().equals(numero)) {
                indiceProcurado = i;
                break;
            }
        }
        return indiceProcurado;
    }

    @Override
    public void adicionar(ContaAbstrata conta) throws RepositorioCheioException {
        if (this.indice >= 0 && this.indice < this.contas.length && this.contas[this.indice] == null) {
            this.contas[this.indice] = conta;
            this.atualizarIndice();
        } else {
            throw new RepositorioCheioException();
        }
    }

    @Override
    public void remover(ContaAbstrata conta) {
        int i = this.procurarIndice(conta.getNumero());
        if (i != -1) {
            this.contas[i] = null;
            this.indice = i;
        }
    }

    @Override
    public void atualizar(ContaAbstrata conta) {
        int i = this.procurarIndice(conta.getNumero());
        if (i != -1) {
            contas[i] = conta;
        }
    }

    @Override
    public ContaAbstrata consultar(ContaAbstrata conta) {
        return this.consultar(conta.getNumero());
    }

    @Override
    public ContaAbstrata consultar(String numero) {
        ContaAbstrata contaProcurada = null;
        int i = this.procurarIndice(numero);
        if (i != -1) {
            contaProcurada = this.contas[i];
        }
        return contaProcurada;
    }

    @Override
    public void listar() {
        for (ContaAbstrata conta : contas) {
            if (conta != null) {
                System.out.println(conta);
            }
        }
    }

    @Override
    public boolean existe(String numero) {
        boolean resposta = false;
        int i = this.procurarIndice(numero);
        if (i != -1) {
            resposta = true;
        }
        return resposta;
    }

    @Override
    public ArrayList<ContaAbstrata> consultar(Cliente cliente) {
        ArrayList<ContaAbstrata> result = new ArrayList<ContaAbstrata>();
        for (ContaAbstrata conta : this.contas) {
            if (conta.getCliente().equals(cliente)) {
                result.add(conta);
            }
        }
        return result;
    }
}
