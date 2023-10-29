
#include <stdio.h>
#include "proj.h"



// Função para adicionar um novo cliente
void Novo_Cliente(Cliente clientes[], int *numClientes) {
    if (*numClientes < 1000) {
        Cliente novoCliente;
        printf("Nome: ");
        scanf("%s", novoCliente.nome);
        printf("CPF: ");
        scanf("%s", novoCliente.cpf);
        printf("Tipo de conta (comum ou plus): ");
        scanf("%s", novoCliente.tipo_conta);
        printf("Valor inicial da conta: ");
        scanf("%f", &novoCliente.saldo);
        printf("Senha: ");
        scanf("%s", novoCliente.senha);

        clientes[*numClientes] = novoCliente;
        (*numClientes)++;
        printf("Cliente adicionado com sucesso.\n");
    } else {
        printf("Limite maximo de clientes atingido.\n");
    }
}


