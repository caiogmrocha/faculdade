package iu;

import dados.conta.RepositorioCheioException;
import fachada.Banco;
import negocio.excecao.cliente.ClienteNaoExisteException;
import negocio.excecao.conta.ContaJaExisteException;
import negocio.excecao.conta.TipoContaNaoExisteException;

import java.util.Scanner;

public class TelaCadastroConta {

    private Scanner scanner;
    private Banco fachada;

    public TelaCadastroConta(Banco fachada) {
        this.fachada = fachada;
        scanner = new Scanner(System.in);
    }

    public void solicitarDados() {
        boolean erro = false;
        do {
            System.out.println(">>>> Dados da Conta <<<<");
            String cpf = solicitarCliente();
            String num = solicitarNumero();
            int tipoConta = solicitarTipo();

            try {
                fachada.adicionarConta(num, tipoConta, cpf, 0); //String numeroConta, int tipoConta, String cpfCliente, double saldo
                System.out.println("<O cadastro foi realizado com sucesso!>");
                erro = false;
            } catch (ContaJaExisteException | ClienteNaoExisteException | TipoContaNaoExisteException e) {
                System.out.println(e.getMessage());
                System.out.println("<O cadastro da conta será reiniciado...>");
                erro = true;
            } catch (RepositorioCheioException e) {
                System.out.println(e.getMessage());
                erro = false;
            }
        } while (erro);
    }

    private String solicitarCliente() {
        System.out.println("CPF do cliente: ");
        String cpf = scanner.nextLine();
        return cpf;
    }

    private String solicitarNumero() {
        System.out.println("Numero da conta: ");
        String num = scanner.nextLine();
        return num;
    }

    private int solicitarTipo() {
        System.out.println("Tipo da conta: ");
        System.out.println("1 - Conta corrente");
        System.out.println("2 - Poupan�a");
        System.out.println("3 - Conta bonificada");
        System.out.println("4 - Conta imposto");
        String tipo = scanner.nextLine();
        return Integer.parseInt(tipo);
    }
}
