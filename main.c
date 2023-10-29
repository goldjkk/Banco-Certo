
#include <stdio.h>
#include "proj.h"

int main() {
    Cliente clientes[1000];
    Operacao operacoes[100];
    int numClientes = 0;
    int numOperacoes = 0;

    int opcao;
    do {
        // Exibir menu de opções
        printf("Menu de Opcoes:\n");
        printf("1. Novo cliente\n");
        printf("2. Apagar cliente\n");
        printf("3. Listar clientes\n");
        printf("4. Debito\n");
        printf("5. Deposito\n");
        printf("6. Extrato\n");
        printf("7. Transferencia Entre Contas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Novo_Cliente(clientes, &numClientes);
                break;
            case 2:
                Apagar_Cliente(clientes, &numClientes);
                break;
            case 3:
                Listar_clientes(clientes, numClientes);
                break;
            case 4:
                Debito(clientes, numClientes, operacoes, &numOperacoes);
                break;
            case 5:
                Deposito(clientes, numClientes, operacoes, &numOperacoes);
                break;
            case 6:
                Extrato(clientes, numClientes, operacoes, numOperacoes);
                break;
            case 7:
                Transferencia(clientes, numClientes, operacoes, &numOperacoes);
                break;
            case 0:
                printf("Saindo do programa. Salvando dados...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
