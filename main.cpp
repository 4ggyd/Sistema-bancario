#include <iostream>
#include <string>
using namespace std;

// Cliente
class Cliente {
private:
    string nome;
    string cpf;

public:
    // Construtor
    Cliente(string nome, string cpf) {
        this->nome = nome;
        this->cpf = cpf;
    }

    // função
    string getNome() {
        return nome;
    }

    string getCpf() {
        return cpf;
    }
};

// ContaBancaria
class ContaBancaria {
private:
    int numero;
    double saldo;
    Cliente titular;

public:
    // Construtor com saldo opcional
    ContaBancaria(int numero, Cliente titular, double saldo = 0.0) : titular(titular) {
        this->numero = numero;
        this->saldo = saldo;
    }

    // depositar
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        } else {
            cout << "Valor de depósito inválido." << endl;
        }
    }

    // sacar
    void sacar(double valor) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
        } else {
            cout << "Saque não realizado. Saldo insuficiente ou valor inválido." << endl;
        }
    }

    // transferir para uma conta
    void transferir(double valor, ContaBancaria &destino) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            destino.depositar(valor);
            cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.numero << endl;
        } else {
            cout << "Transferência falhou. Saldo insuficiente ou valor inválido." << endl;
        }
    }

    // transferir valor dividido entre duas contas
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        double metade = valor / 2.0;
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            destino1.depositar(metade);
            destino2.depositar(metade);
            cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.numero << " e " << destino2.numero << ") da conta " << numero << endl;
        } else {
            cout << "Transferência múltipla falhou. Saldo insuficiente ou valor inválido." << endl;
        }
    }

    // Exibir saldo
    void exibirSaldo() {
        cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
    }

    // Exibir informações da conta
    void exibirInformacoes() {
        cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
        cout << "Número da Conta: " << numero << ", Saldo: R$ " << saldo << endl;
    }
};

// Função principal
int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    
    conta1.exibirSaldo();

    
    conta1.transferir(200.0, conta2);

    
    conta1.transferir(300.0, conta2, conta3);

    
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
