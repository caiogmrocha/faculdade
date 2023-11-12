public class App {
    public static void main(String[] args) throws Exception {
        Veiculo veiculo = new Veiculo(TipoVeiculo.TERRESTRE, 0.0, 60.0, false, 0);

        veiculo.acelerar();
        veiculo.acelerar();
        veiculo.acelerar();

        System.out.println(veiculo.getVelocidade());

        veiculo.abastecer(10.0);
        
        System.out.println(veiculo.getCombustivel());
    }
}
