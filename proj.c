#include <stdio.h>
#include "proj.h"


// Função para realizar um débito na conta de um cliente
void Debito(Cliente clientes[], int numClientes, Operacao operacoes[], int *numOperacoes) {
    char cpf[12];
    char senha[20];
    float valor;
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Senha: ");
    scanf("%s", senha);
    printf("Valor: ");
    scanf("%f", &valor);

    int clienteEncontrado = 0;

    for (int i = 0; i < numClientes; i++) {
        if (compararStrings(clientes[i].cpf, cpf) && compararStrings(clientes[i].senha, senha)) {
            clienteEncontrado = 1;
            if (compararStrings(clientes[i].tipo_conta, "comum")) {
                if (clientes[i].saldo - valor >= -1000) {
                    clientes[i].saldo -= valor;
                    printf("Debito realizado com sucesso.\n");
                    copiarString(operacoes[*numOperacoes].cpf, cpf);
                    copiarString(operacoes[*numOperacoes].tipo_operacao, "Debito");
                    operacoes[*numOperacoes].valor = valor;
                    (*numOperacoes)++;
                } else {
                    printf("Saldo insuficiente para realizar o débito.\n");
                }
            } else if (compararStrings(clientes[i].tipo_conta, "plus")) {
                if (clientes[i].saldo - valor >= -5000) {
                    clientes[i].saldo -= valor;
                    printf("Debito realizado com sucesso.\n");
                    copiarString(operacoes[*numOperacoes].cpf, cpf);
                    copiarString(operacoes[*numOperacoes].tipo_operacao, "Debito");
                    operacoes[*numOperacoes].valor = valor;
                    (*numOperacoes)++;
                } else {
                    printf("Saldo insuficiente para realizar o debito.\n");
                }
            } else {
                printf("Tipo de conta inválido.\n");
            }
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("CPF ou senha incorretos ou cliente não encontrado.\n");
    }
}
