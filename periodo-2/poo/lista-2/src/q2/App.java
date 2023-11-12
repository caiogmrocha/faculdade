package q2;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<ContaLuz> listaContas = new ArrayList<ContaLuz>();

        listaContas.add(new ContaLuz(30.0, true, LocalDate.of(2023, 1, 10), 3.0));
        listaContas.add(new ContaLuz(40.0, true, LocalDate.of(2023, 2, 10), 2.0));
        listaContas.add(new ContaLuz(25.9, true, LocalDate.of(2023, 3, 10), 4.5));
        listaContas.add(new ContaLuz(29.9, true, LocalDate.of(2023, 4, 07), 4.2));

        for (ContaLuz conta: listaContas) {
            if (conta.getConsumo() >= 4.0) {
                System.out.println(String.format(
                    "A conta do mês %s teve um alto consumo de energia (%.2f kW/h)",
                    conta.getDataVencimento().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")),
                    conta.getConsumo()
                ));
            }
        }

        for (ContaLuz conta: listaContas) {
            if (conta.getConsumo() < 4.0) {
                System.out.println(String.format(
                    "A conta do mês %s teve um baixo consumo de energia (%.2f kW/h)",
                    conta.getDataVencimento().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")),
                    conta.getConsumo()
                ));
            }
        }
    }
}
