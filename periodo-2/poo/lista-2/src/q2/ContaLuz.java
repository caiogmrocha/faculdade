package q2;

import java.time.LocalDate;

public class ContaLuz {
    private Double valor;
    private Double juros;
    private Boolean pago;
    private LocalDate dataVencimento;
    // kW/h
    private Double consumo;
    
    public ContaLuz(Double valor, Boolean pago, LocalDate dataVencimento, Double consumo) {
        this.setValor(valor);
        this.setPago(pago);
        this.setDataVencimento(dataVencimento);
        this.setJuros(0.0);
        this.setConsumo(consumo);
    }

    public void pagar() {
        if (this.dataVencimento.isAfter(LocalDate.now())) {
            this.setJuros(this.getValor() * 0.05);
            this.setPago(true);
            System.out.println("Pago com juros");
        } else {
            this.setPago(true);
        }
    }

    public Double getValor() {
        return valor;
    }

    public void setValor(Double valor) {
        this.valor = valor;
    }

    public Double getJuros() {
        return juros;
    }

    public void setJuros(Double juros) {
        this.juros = juros;
    }

    public Boolean getPago() {
        return pago;
    }

    public void setPago(Boolean pago) {
        this.pago = pago;
    }

    public LocalDate getDataVencimento() {
        return dataVencimento;
    }

    public void setDataVencimento(LocalDate dataVencimento) {
        this.dataVencimento = dataVencimento;
    }

    public Double getConsumo() {
        return consumo;
    }

    public void setConsumo(Double consumo) {
        this.consumo = consumo;
    }
}
