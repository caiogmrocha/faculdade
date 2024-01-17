package aula03;

import java.util.Random;

public class Caneta {
    public String modelo;
    public String cor;
    private double ponta;
    protected int carga;
    protected boolean tampada;

    public Caneta(String modelo, String cor, double ponta, int carga, boolean tampada) {
        this.setModelo(modelo);
        this.setCor(cor);
        this.setPonta(ponta);
        this.setCarga(carga);
        this.setTampada(tampada);
    }

    public void escrever(String texto) {
        System.out.println(texto);
    }

    public void rabiscar() {
        System.out.println(new Random().hashCode());
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public double getPonta() {
        return ponta;
    }

    public void setPonta(double ponta) {
        this.ponta = ponta;
    }

    public int getCarga() {
        return carga;
    }

    public void setCarga(int carga) {
        this.carga = carga;
    }

    public boolean isTampada() {
        return tampada;
    }

    public void setTampada(boolean tampada) {
        this.tampada = tampada;
    }
}
