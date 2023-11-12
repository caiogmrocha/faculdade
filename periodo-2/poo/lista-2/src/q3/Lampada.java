package q3;

public class Lampada {
    private Boolean estadoDaLampada;

    public Lampada(Boolean estadoDaLampada) {
        this.setEstadoDaLampada(estadoDaLampada);
    }

    public void acende() {
        if (this.getEstadoDaLampada()) {
            System.out.println("A lampada já está acesa");
        } else {
            this.setEstadoDaLampada(true);
        }
    }

    public void apaga() {
        if (!this.getEstadoDaLampada()) {
            System.out.println("A lampada já está apagada");
        } else {
            this.setEstadoDaLampada(false);
        }
    }

    public void mostraEstado() {
        if (this.getEstadoDaLampada()) {
            System.out.println("A lampada está acesa");
        } else {
            System.out.println("A lampada está apagada");
        }
    }

    public Boolean getEstadoDaLampada() {
        return estadoDaLampada;
    }

    public void setEstadoDaLampada(Boolean estadoDaLampada) {
        this.estadoDaLampada = estadoDaLampada;
    }
}
