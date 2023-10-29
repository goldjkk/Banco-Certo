
#include <stdio.h>
#include "proj.h"

// Função para apagar um cliente pelo CPF
void Apagar_Cliente(Cliente clientes[], int *numClientes) {
    char cpf[12];
    printf("Digite o CPF do cliente a ser apagado: ");
    scanf("%s", cpf);

    int i;
    for (i = 0; i < *numClientes; i++) {
        if (compararStrings(clientes[i].cpf, cpf)) {
            // Move todos os clientes após o cliente apagado uma posição para frente
            for (int j = i; j < *numClientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (*numClientes)--;
            printf("Cliente apagado com sucesso.\n");
            return;
        }
    }

    printf("Cliente nao encontrado.\n");
}


