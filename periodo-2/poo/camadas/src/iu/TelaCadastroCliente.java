package iu;

import fachada.Banco;
import negocio.excecao.cliente.ClienteJaExisteException;

import java.util.Scanner;

public class TelaCadastroCliente {

    private Scanner scanner;
    private Banco fachada;

    public TelaCadastroCliente(Banco fachada) {
        this.fachada = fachada;
        this.scanner = new Scanner(System.in);
    }

    public void solicitarDados() {
        System.out.println(">>>> Dados Pessoais <<<<");
        System.out.println("Nome: ");
        String nome = scanner.nextLine();
        System.out.println("CPF: ");
        String cpf = scanner.nextLine();
        System.out.println(">>>> Endereço <<<<");
        System.out.println("CEP: ");
        String cep = scanner.nextLine();
        System.out.println("Numero: ");
        String num = scanner.nextLine();
        System.out.println("Rua: ");
        String rua = scanner.nextLine();
        System.out.println("Bairro: ");
        String bairro = scanner.nextLine();
        String complemento = rua + ", " + bairro;

        try {
            fachada.adicionarCliente(cpf, nome, cep, num, complemento);
        } catch (ClienteJaExisteException e) {
            System.out.println(e.getMessage());
            System.out.println("<O cadastro será reiniciado...>");
            solicitarDados();
        }

        System.out.println("<O cadastro foi realizado com sucesso!>");
    }
}
