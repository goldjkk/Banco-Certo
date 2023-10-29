#include <stdio.h>
#include "proj.h"

// Função para realizar um depósito na conta de um cliente
void Deposito(Cliente clientes[], int numClientes, Operacao operacoes[], int *numOperacoes) {
    char cpf[12];
    float valor;
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Valor: ");
    scanf("%f", &valor);

    int clienteEncontrado = 0;

    for (int i = 0; i < numClientes; i++) {
        if (compararStrings(clientes[i].cpf, cpf)) {
            clienteEncontrado = 1;
            clientes[i].saldo += valor;
            printf("Deposito realizado com sucesso.\n");
            copiarString(operacoes[*numOperacoes].cpf, cpf);
            copiarString(operacoes[*numOperacoes].tipo_operacao, "Deposito");
            operacoes[*numOperacoes].valor = valor;
            (*numOperacoes)++;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente naao encontrado.\n");
    }
}





