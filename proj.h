#ifndef UNTITLED1_PROJ_H
#define UNTITLED1_PROJ_H
#ifndef PROJ_H
#define PROJ_H

=======


// Definição da estrutura Cliente
typedef struct {
    char nome[50];
    char cpf[12];
    char tipo_conta[10];
    float saldo;
    char senha[20];
} Cliente;
// Definição da estrutura Operacao
typedef struct {
    char cpf[12];
    char tipo_operacao[20];
    float valor;
} Operacao;

void Transferencia(Cliente clientes[], int numClientes, Operacao operacoes[], int *numOperacoes);

#endif

#endif //UNTITLED1_PROJ_H
