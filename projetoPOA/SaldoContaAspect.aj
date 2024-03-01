public aspect SaldoContaAspect {
    pointcut SacarPointcut(float valor, String mensagem): call(void ContaBancaria.Sacar(float, String) && args(valor, mensagem));

    before(float valor): SacarPointcut(valor){
        if(valor > ContaBancaria.Saldo){
            
            System.out.println("Saldo Insuficiente");
        }
        else{
            System.out.println("Saque realizado com sucesso");
            ContaBancaria.Saldo -= valor;
        }
    }
}