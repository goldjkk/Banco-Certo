#include <stdio.h>
#include "proj.h"


void Transferencia(Cliente clientes[], int numClientes, Operacao operacoes[], int *numOperacoes) {
    char cpfOrigem[12];
    char senhaOrigem[20];
    char cpfDestino[12];
    float valor;
    printf("CPF (Origem): ");
    scanf("%s", cpfOrigem);
    printf("Senha (Origem): ");
    scanf("%s", senhaOrigem);
    printf("CPF (Destino): ");
    scanf("%s", cpfDestino);
    printf("Valor: ");
    scanf("%f", &valor);

    int clienteOrigemEncontrado = 0;
    int clienteDestinoEncontrado = 0;
    // Encontre o cliente de origem
    int indiceOrigem = -1;
    for (int i = 0; i < numClientes; i++) {
        if (compararStrings(clientes[i].cpf, cpfOrigem) && compararStrings(clientes[i].senha, senhaOrigem)) {
            clienteOrigemEncontrado = 1;
            indiceOrigem = i;
            break;
        }
    }

    // Encontre o cliente de destino
    int indiceDestino = -1;
    for (int i = 0; i < numClientes; i++) {
        if (compararStrings(clientes[i].cpf, cpfDestino)) {
            clienteDestinoEncontrado = 1;
            indiceDestino = i;
            break;
        }
    }

    if (clienteOrigemEncontrado && clienteDestinoEncontrado) {
        if (compararStrings(clientes[indiceOrigem].tipo_conta, "comum")) {
            if (clientes[indiceOrigem].saldo - valor >= -1000) {
                clientes[indiceOrigem].saldo -= valor;
                clientes[indiceDestino].saldo += valor;
                printf("Transferencia realizada com sucesso.\n");

                // Registre as operações
                copiarString(operacoes[*numOperacoes].cpf, cpfOrigem);
                copiarString(operacoes[*numOperacoes].tipo_operacao, "Transferencia (saída)");
                operacoes[*numOperacoes].valor = valor;
                (*numOperacoes)++;
                copiarString(operacoes[*numOperacoes].cpf, cpfDestino);
                copiarString(operacoes[*numOperacoes].tipo_operacao, "Transferencia (entrada)");
                operacoes[*numOperacoes].valor = valor;
                (*numOperacoes)++;
            } else {
                printf("Saldo insuficiente para realizar a transferencia.\n");
            }
        } else if (compararStrings(clientes[indiceOrigem].tipo_conta, "plus")) {
            if (clientes[indiceOrigem].saldo - valor >= -5000) {
                clientes[indiceOrigem].saldo -= valor;
                clientes[indiceDestino].saldo += valor;
                printf("Transferencia realizada com sucesso.\n");

                // Registre as operações
                copiarString(operacoes[*numOperacoes].cpf, cpfOrigem);
                copiarString(operacoes[*numOperacoes].tipo_operacao, "Transferencia (saída)");
                operacoes[*numOperacoes].valor = valor;
                (*numOperacoes)++;
                copiarString(operacoes[*numOperacoes].cpf, cpfDestino);
                copiarString(operacoes[*numOperacoes].tipo_operacao, "Transferencia (entrada)");
                operacoes[*numOperacoes].valor = valor;
                (*numOperacoes)++;
            } else {
                printf("Saldo insuficiente para realizar a transferencia.\n");
            }
        } else {
            printf("Tipo de conta de origem invaalido.\n");
        }
    } else {
        printf("CPF ou senha incorretos ou clientes nao encontrados.\n");
    }
}

