package q2;

import java.util.Random;

public class Baralho {
    public static void main(String[] args) {
        Baralho baralho = new Baralho(new Carta[56]);

        baralho.baralho[0] = new Carta("Ás", "Paus");
        baralho.baralho[1] = new Carta("Dois", "Paus");
        baralho.baralho[2] = new Carta("Três", "Paus");
        baralho.baralho[3] = new Carta("Quatro", "Paus");
        baralho.baralho[4] = new Carta("Cinco", "Paus");
        baralho.baralho[5] = new Carta("Seis", "Paus");
        baralho.baralho[6] = new Carta("Sete", "Paus");
        baralho.baralho[7] = new Carta("Oito", "Paus");
        baralho.baralho[8] = new Carta("Nove", "Paus");
        baralho.baralho[9] = new Carta("Dez", "Paus");
        baralho.baralho[10] = new Carta("Valete", "Paus");
        baralho.baralho[11] = new Carta("Dama", "Paus");
        baralho.baralho[12] = new Carta("Rei", "Paus");
        baralho.baralho[13] = new Carta("Ás", "Copas");
        baralho.baralho[14] = new Carta("Dois", "Copas");
        baralho.baralho[15] = new Carta("Três", "Copas");
        baralho.baralho[16] = new Carta("Quatro", "Copas");
        baralho.baralho[17] = new Carta("Cinco", "Copas");
        baralho.baralho[18] = new Carta("Seis", "Copas");
        baralho.baralho[19] = new Carta("Sete", "Copas");
        baralho.baralho[20] = new Carta("Oito", "Copas");
        baralho.baralho[21] = new Carta("Nove", "Copas");
        baralho.baralho[22] = new Carta("Dez", "Copas");
        baralho.baralho[23] = new Carta("Valete", "Copas");
        baralho.baralho[24] = new Carta("Dama", "Copas");
        baralho.baralho[25] = new Carta("Rei", "Copas");
        baralho.baralho[26] = new Carta("Ás", "Ouros");
        baralho.baralho[27] = new Carta("Dois", "Ouros");
        baralho.baralho[28] = new Carta("Três", "Ouros");
        baralho.baralho[29] = new Carta("Quatro", "Ouros");
        baralho.baralho[30] = new Carta("Cinco", "Ouros");
        baralho.baralho[31] = new Carta("Seis", "Ouros");
        baralho.baralho[32] = new Carta("Sete", "Ouros");
        baralho.baralho[33] = new Carta("Oito", "Ouros");
        baralho.baralho[34] = new Carta("Nove", "Ouros");
        baralho.baralho[35] = new Carta("Dez", "Ouros");
        baralho.baralho[36] = new Carta("Valete", "Ouros");
        baralho.baralho[37] = new Carta("Dama", "Ouros");
        baralho.baralho[38] = new Carta("Rei", "Ouros");
        baralho.baralho[39] = new Carta("Ás", "Espadas");
        baralho.baralho[40] = new Carta("Dois", "Espadas");
        baralho.baralho[41] = new Carta("Três", "Espadas");
        baralho.baralho[42] = new Carta("Quatro", "Espadas");
        baralho.baralho[43] = new Carta("Cinco", "Espadas");
        baralho.baralho[44] = new Carta("Seis", "Espadas");
        baralho.baralho[45] = new Carta("Sete", "Espadas");
        baralho.baralho[46] = new Carta("Oito", "Espadas");
        baralho.baralho[47] = new Carta("Nove", "Espadas");
        baralho.baralho[48] = new Carta("Dez", "Espadas");
        baralho.baralho[49] = new Carta("Valete", "Espadas");
        baralho.baralho[50] = new Carta("Dama", "Espadas");
        baralho.baralho[51] = new Carta("Rei", "Espadas");
        baralho.baralho[52] = new Carta("Coringa", "Coringa");
        baralho.baralho[53] = new Carta("Coringa", "Coringa");
        baralho.baralho[53] = new Carta("Coringa", "Coringa");
        baralho.baralho[53] = new Carta("Coringa", "Coringa");
        
        int iteracoes = new Random().nextInt(100);

        for (int i = 0; i < iteracoes; i++) {
            baralho.embaralhar();
        }

        System.out.println(String.format("Embaralhado %d vezes.", iteracoes));

        baralho.imprimir();
    }
    
    Carta[] baralho = null;

    public Baralho(Carta[] baralho) {
        this.baralho = baralho;
    }

    public void embaralhar() {
        int posicao1 = new Random().nextInt(56);
        int posicao2 = new Random().nextInt(56);
        
        Carta temp = this.baralho[posicao1];
        this.baralho[posicao1] = this.baralho[posicao2];
        this.baralho[posicao2] = temp;
    }

    public Carta darCarta() {
        Carta temp = null;

        for (int i = this.baralho.length; i >= 0; i--) {
            if (this.baralho[i] != null) {
                temp = this.baralho[this.baralho.length];
                break;
            }
        }
        
        this.baralho[this.baralho.length] = null;

        return temp;
    }

    public boolean temCarta(Carta carta) {
        for (int i = 0; i < this.baralho.length; i++) {
            if (this.baralho[i].getNome() == carta.getNome()) {
                return true;
            }
        }

        return false;
    }

    public void imprimir() {
        for (int i = 0; i < this.baralho.length; i++) {
            if (this.baralho[i] != null) {
                System.out.println(String.format("Nome: %s; Naipe: %s.", this.baralho[i].getNome(), this.baralho[i].getNaipe()));
            }
        }
    }
}
