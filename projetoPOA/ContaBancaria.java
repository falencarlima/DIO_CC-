public class ContaBancaria{

    private int TipoConta;
    private int TipoCliente;
    private String DataAbertura;
    private float Saldo;
    
    public void Conta (int tipoConta, int tipoCliente, String dataAbertura, float saldo){
        this.TipoConta = tipoConta;
        this.TipoCliente = tipoCliente;
        this.DataAbertura = dataAbertura;
        this.Saldo = saldo;
    }
    
    public void Sacar(float valor){}

    public float Depositar(float valor){
        this.Saldo += valor;
        return this.Saldo;
    }
}