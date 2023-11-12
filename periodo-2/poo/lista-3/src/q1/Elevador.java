package q1;

public class Elevador {
    private Boolean subindo = false;
    private Boolean descendo = false;
    private Boolean parado = true;
    private Boolean aberto = false;
    private Integer qtdAndares = 5;
    private Integer andarAtual = 0;
    private Integer capacidadeTotal = 5;
    private Integer capacidadeOcupada = 0;

    public Elevador(Boolean subindo, Boolean descendo, Boolean parado, Boolean aberto, Integer qtdAndares, Integer andarAtual) {
        this.subindo = subindo;
        this.descendo = descendo;
        this.parado = parado;
        this.aberto = aberto;
        this.qtdAndares = qtdAndares;
        this.andarAtual = andarAtual;
    }

    // Behavioral Methods

    public Boolean subir(int andar) {
        if (andar < 0 || andar > this.getQtdAndares()) {
            System.out.println(String.format("O andar %d não existe.", andar));
            
            return false;
        }

        this.setSubindo(true);
        this.setDescendo(false);
        this.setParado(false);
        
        if (this.getAndarAtual() == andar) {
            this.setSubindo(false);
            this.setDescendo(false);
            this.setParado(true);
            
            System.out.println(String.format("O elevador chegou ao andar %d.", andar));

            return true;
        } else {
            this.setAndarAtual(andarAtual + 1);

            System.out.println(String.format("O elevador está no andar %d.", this.getAndarAtual()));

            try { Thread.sleep(500); } catch (Exception e) {}
    
            return this.subir(andar);
        }
    }

    public Boolean descer(int andar) {
        if (andar < 0 || andar > this.getQtdAndares()) {
            System.out.println(String.format("O andar %d não existe.", andar));

            return false;
        }

        this.setSubindo(false);
        this.setDescendo(true);
        this.setParado(false);
        
        if (this.getAndarAtual() == andar) {
            System.out.println(String.format("O elevador chegou ao andar %d.", andar));
            System.out.println(String.format("O elevador chegou ao andar %d.", andar));

            this.setSubindo(false);
            this.setSubindo(false);
            this.setParado(true);

            return true;
        } else {
            this.setAndarAtual(andarAtual - 1);

            System.out.println(String.format("O elevador está no andar %d.", this.getAndarAtual()));

            try { Thread.sleep(500); } catch (Exception e) {}
    
            return this.descer(andar);
        }
    }

    public Boolean receberPessoas(Integer qtdPessoas) {
        if (!this.getParado()) {
            System.out.println("O elevador precisa está parado para receber pessoas.");

            return false;
        }

        if (this.getCapacidadeOcupada() == this.getCapacidadeTotal()) {
            System.out.println(String.format("A capacidade máxima do elevador (%d pessoas) já foi atingida.", this.getCapacidadeTotal()));

            return false;
        }

        
        if (this.getCapacidadeOcupada() + qtdPessoas > this.getCapacidadeTotal()) {
            System.out.println(String.format("A entrada das %d pessoas excede a capacidade total do elevador (%d pessoas).", qtdPessoas, this.getCapacidadeTotal()));
            
            return false;
        }

        this.setAberto(true);        
        this.setCapacidadeOcupada(this.getCapacidadeOcupada() + qtdPessoas);
        this.setAberto(false);
        
        System.out.println(String.format("%d pessoas entraram no elevador.", qtdPessoas));

        return true;
    }

    public Boolean liberarPessoas(Integer qtdPessoas) {
        if (!this.getParado()) {
            System.out.println("O elevador precisa está parado para liberar pessoas.");

            return false;
        }

        this.setAberto(true);
        
        if (this.getCapacidadeOcupada() - qtdPessoas < 0) {
            this.setCapacidadeOcupada(0);
            
            System.out.println("Todas as pessoas foram liberadas do elevador.");
        } else {
            this.setCapacidadeOcupada(this.getCapacidadeOcupada() - qtdPessoas);
            
            System.out.println(String.format("%d pessoas foram liberadas do elevador.", qtdPessoas));
        }
        
        this.setAberto(false);

        return true;
    }

    // Getters and Setters

    public Boolean getSubindo() {
        return subindo;
    }

    public void setSubindo(Boolean subindo) {
        this.subindo = subindo;
    }

    public Boolean getDescendo() {
        return descendo;
    }

    public void setDescendo(Boolean descendo) {
        this.descendo = descendo;
    }
    
    public Boolean getParado() {
        return parado;
    }

    public void setParado(Boolean parado) {
        this.parado = parado;
    }

    public Integer getQtdAndares() {
        return qtdAndares;
    }

    public void setQtdAndares(Integer qtdAndares) {
        this.qtdAndares = qtdAndares;
    }

    public Integer getAndarAtual() {
        return andarAtual;
    }

    public void setAndarAtual(Integer andarAtual) {
        this.andarAtual = andarAtual;
    }

    public Integer getCapacidadeOcupada() {
        return capacidadeOcupada;
    }

    public void setCapacidadeOcupada(Integer capacidadeOcupada) {
        this.capacidadeOcupada = capacidadeOcupada;
    }

    public Integer getCapacidadeTotal() {
        return capacidadeTotal;
    }

    public void setCapacidadeTotal(Integer capacidadeTotal) {
        this.capacidadeTotal = capacidadeTotal;
    }

    public Boolean getAberto() {
        return aberto;
    }

    public void setAberto(Boolean aberto) {
        this.aberto = aberto;
    }
}
