package q2;

public class Ponto2D {
    private Double x = 0.0;
    private Double y = 0.0;
    
    public Ponto2D(Double x, Double y) {
        if (y == null) {
            this.x = x;
            this.y = x;
        } else {
            this.x = x;
            this.y = y;
        }
    }

    public static Ponto2D criarOposto(Ponto2D a) {
        return new Ponto2D(-a.x, -a.y);
    }

    public Double getX() {
        return x;
    }

    public void setX(Double x) {
        this.x = x;
    }

    public Double getY() {
        return y;
    }

    public void setY(Double y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return String.format("(%.2f, %.2f)", this.getX(), this.getY());
    }
}
