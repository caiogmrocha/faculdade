package iu;

import fachada.Banco;

import java.util.Scanner;

public class TelaPrincipal {

    private Scanner scanner;
    private TelaCadastroConta telaCadastroConta;
    private TelaCadastroCliente telaCadastroCliente;

    public TelaPrincipal(Banco fachada) {
        scanner = new Scanner(System.in);
        telaCadastroConta = new TelaCadastroConta(fachada);
        telaCadastroCliente = new TelaCadastroCliente(fachada);
    }

    public void iniciar() {
        while (true) {
            System.out.println(">>>> Menu de operações <<<<");
            System.out.println("1 - Cadastrar cliente");
            System.out.println("2 - Cadastrar conta");
            System.out.println("S - Sair");
            String operacao = scanner.nextLine();

            /*Código incompleto: deveria dar acesso à todas as funcionalidades do sistema bancário.*/
            switch (operacao) {
                case "1":
                    telaCadastroCliente.solicitarDados();
                    break;
                case "2":
                    telaCadastroConta.solicitarDados();
                    break;
                case "s":
                case "S":
                    System.exit(0);
                    break;
                default:
                    System.out.println("<Operação inválida. Tente novamente.>");
            }
        }
    }

}
