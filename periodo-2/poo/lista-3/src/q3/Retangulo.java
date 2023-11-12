package q3;

import q2.Ponto2D;

public class Retangulo {
    /**
     * Se trata de uma relação de agregação. Pois pontos são uteis
     * mesmo sem a necessidade dos retângulos e vice-versa, portanto,
     * não é uma relação obrigatória, e.g., os pontos podem existir
     * para caracterizar um ponto, simplesmente, * ou a origem/extremidade
     * de um vetor.
     */
    private Ponto2D a;
    private Ponto2D b;
    private Ponto2D c;
    private Ponto2D d;

    public Retangulo(Ponto2D a, Ponto2D b) {
        this.setA(new Ponto2D(a.getX(), a.getY()));
        this.setB(new Ponto2D(b.getX(), a.getY()));
        this.setC(new Ponto2D(b.getX(), b.getY()));
        this.setD(new Ponto2D(a.getX(), b.getY()));
    }

    public Boolean contem(Ponto2D g) {
        if (
            g.getX() >= this.getA().getX() &&
            g.getX() <= this.getB().getX() &&
            g.getY() >= this.getD().getY() &&
            g.getY() <= this.getA().getY()
        ) return true;

        return false;
    }

    @Override
    public String toString() {
        return "Retangulo [a=" + this.getA().toString() + ", b=" + this.getB().toString() + ", c=" + this.getC().toString() + ", d=" + this.getD().toString() + "]";
    }

    public Ponto2D getA() {
        return a;
    }

    public void setA(Ponto2D a) {
        this.a = a;
    }

    public Ponto2D getB() {
        return b;
    }

    public void setB(Ponto2D b) {
        this.b = b;
    }

    public Ponto2D getC() {
        return c;
    }

    public void setC(Ponto2D c) {
        this.c = c;
    }

    public Ponto2D getD() {
        return d;
    }

    public void setD(Ponto2D d) {
        this.d = d;
    }

    
}
