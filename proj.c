
// Função para listar todos os clientes
void Listar_clientes(Cliente clientes[], int numClientes) {
    printf("Lista de Clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo de conta: %s\n", clientes[i].tipo_conta);
        printf("Saldo: %.2f\n", clientes[i].saldo);
        printf("\n");
    }
}


