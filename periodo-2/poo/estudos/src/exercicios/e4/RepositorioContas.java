package exercicios.e4;

public interface RepositorioContas {
    public abstract Conta getOne(String numero);
    public abstract Conta[] getAll();
    public abstract void insert(Conta conta);
    public abstract void update(Conta conta, String numero);
    public abstract boolean delete(String numero);
}
