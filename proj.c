

#include <stdio.h>
#include "proj.h"


// Função para gerar um extrato bancário
void Extrato(Cliente clientes[], int numClientes, Operacao operacoes[], int numOperacoes) {
    char cpf[12];
    char senha[20];
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Senha: ");
    scanf("%s", senha);

    int clienteEncontrado = 0;

    for (int i = 0; i < numClientes; i++) {
        if (compararStrings(clientes[i].cpf, cpf) && compararStrings(clientes[i].senha, senha)) {
            // Nome do arquivo de extrato
            char nomeArquivo[50];
            copiarString(nomeArquivo, "extrato_");
            copiarString(nomeArquivo + 8, cpf);
            copiarString(nomeArquivo + 20, ".txt");

            // Abra o arquivo para escrita
            FILE *arquivo = fopen(nomeArquivo, "w");
            if (arquivo == NULL) {
                printf("Erro ao criar o arquivo de extrato.\n");
                return;
            }

            fprintf(arquivo, "Extrato Bancaario para o Cliente: %s\n", clientes[i].nome);
            fprintf(arquivo, "CPF: %s\n", clientes[i].cpf);
            fprintf(arquivo, "Tipo de conta: %s\n", clientes[i].tipo_conta);
            fprintf(arquivo, "Saldo atual: %.2f\n\n", clientes[i].saldo);

            fprintf(arquivo, "Operacoes:\n");
            for (int j = 0; j < numOperacoes; j++) {
                if (compararStrings(operacoes[j].cpf, cpf)) {
                    fprintf(arquivo, "%s: %.2f\n", operacoes[j].tipo_operacao, operacoes[j].valor);
                }
            }

            fclose(arquivo);
            printf("Extrato gerado com sucesso. Consulte o arquivo: %s\n", nomeArquivo);
            clienteEncontrado = 1; // Cliente encontrado, atualize a flag
            break; 
        }
    }

    if (!clienteEncontrado) {
        printf("CPF ou senha incorretos ou cliente nao encontrado.\n");
    }
}





