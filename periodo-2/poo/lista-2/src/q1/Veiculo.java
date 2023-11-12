enum TipoVeiculo {
    AEREO,
    TERRESTRE,
    AQUATICO
}

public class Veiculo {
    private TipoVeiculo tipo;
    private Double velocidade;
    private Double combustivel;
    private Boolean acelerando;
    private Integer qtdPassageiros;

    public Veiculo(TipoVeiculo tipo, Double velocidade, Double combustivel, Boolean acelerando, Integer qtdPassageiros) {
        this.setTipo(tipo);
        this.setVelocidade(velocidade);
        this.setCombustivel(combustivel);
        this.setAcelerando(acelerando);
        this.setQtdPassageiros(qtdPassageiros);
    }

    public void abastecer(Double combustivel) {
        if (this.getCombustivel() + combustivel > 60) {
            System.out.println("Tanque cheio!");
            return;
        }

        this.combustivel += combustivel;
    }

    public void acelerar() {
        if (this.getCombustivel() <= 0) {
            System.out.println("Combustível insuficiente!");
            return;
        }

        if (this.getAcelerando()) {
            System.out.println("Veículo já está acelerando!");
            return;
        }

        this.acelerando = true;
        this.velocidade += 10;
        this.combustivel -= 1;
    }

    public TipoVeiculo getTipo() {
        return this.tipo;
    }

    public Double getVelocidade() {
        return this.velocidade;
    }

    public Double getCombustivel() {
        return this.combustivel;
    }

    public Boolean getAcelerando() {
        return this.acelerando;
    }

    public Integer getQtdPassageiros() {
        return this.qtdPassageiros;
    }

    public void setTipo(TipoVeiculo tipo) {
        this.tipo = tipo;
    }

    public void setVelocidade(Double velocidade) {
        this.velocidade = velocidade;
    }

    public void setCombustivel(Double combustivel) {
        this.combustivel = combustivel;
    }

    public void setAcelerando(Boolean acelerando) {
        this.acelerando = acelerando;
    }

    public void setQtdPassageiros(Integer qtdPassageiros) {
        this.qtdPassageiros = qtdPassageiros;
    }
}