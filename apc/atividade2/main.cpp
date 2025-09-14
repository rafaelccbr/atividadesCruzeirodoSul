#include <cstdlib> // Inclui funções para controle de processo, como system()
#include <cstring> // Inclui funções para manipulação de strings, como strcpy()
#include <stdio.h> // Inclui funções padrão de entrada e saída, como printf() e scanf()
#include <stdlib.h> // Inclui funções de utilidade geral, como exit() e malloc()

// Caixa2: Programa Simples de gerenciamento bancário
// Funções principais: Depósito, saque, saldo e extrato de transações da sessão
// Função Bonus: Autenticação por senha

// Função para pausar a execução do programa até o usuário pressionar Enter
void espereParaContinuar() {
    int c;
    // Limpa o buffer de entrada para evitar problemas com o getchar()
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Pressione Enter para continuar...");
    getchar(); // Espera o usuário pressionar Enter
}

// Função para realizar um depósito na conta
void deposito(double* saldo, int* historicoIndice, char historico[100][100]) {
    double deposito = 0;
    printf("Quanto você quer depositar?\n");
    scanf("%lf", &deposito); // Lê o valor a ser depositado
    if (deposito <= 0) { // Verifica se o valor do depósito é válido
        printf("Não é possivel depositar valores menores que R$0.01\n");
        espereParaContinuar();
        return; // Sai da função se o depósito for inválido
    }
    *saldo = *saldo + deposito; // Adiciona o valor depositado ao saldo
    char frase[100];
    // Formata a string para o histórico de transações
    sprintf(frase, "Deposito de R$ %.2f", deposito);
    // Copia a string formatada para o histórico
    strcpy(historico[*historicoIndice], frase);
    *historicoIndice = *historicoIndice + 1; // Incrementa o índice do histórico
    espereParaContinuar();
}

// Função para realizar um saque da conta
void saque(double* saldo, int* historicoIndice, char historico[100][100]) {
    double sacar = 0;
    printf("Quanto você quer sacar?\n");
    scanf("%lf", &sacar); // Lê o valor a ser sacado
    if (*saldo <= 0.01) { // Verifica se há saldo suficiente para o saque
        printf("Não há saldo disponível para saque\n");
        espereParaContinuar();
        return; // Sai da função se não houver saldo
    }
    if (sacar <= 0) { // Verifica se o valor do saque é válido
        printf("Não é possivel sacar valores menores que R$0.01\n");
        espereParaContinuar();
        return; // Sai da função se o saque for inválido
    }
    *saldo = *saldo - sacar; // Subtrai o valor sacado do saldo
    char frase[100];
    // Formata a string para o histórico de transações
    sprintf(frase, "Saque de R$ %.2f", sacar);
    // Copia a string formatada para o histórico
    strcpy(historico[*historicoIndice], frase);
    *historicoIndice = *historicoIndice + 1; // Incrementa o índice do histórico
    espereParaContinuar();
}

// Função para exibir o extrato de transações da sessão
void extrato(int historicoIndice, char historico[100][100]) {
    if (historicoIndice - 1 == 0) { // Verifica se há transações para exibir
        printf("Não há extrato a ser exibido\n");
        espereParaContinuar();
        return; // Sai da função se não houver extrato
    }
    for (int i = 0; i < historicoIndice; i++) {
        printf("%s\n", historico[i]); // Exibe cada transação do histórico
    }
    espereParaContinuar();
}

// Função para exibir o saldo atual
void verSaldo(double saldo) {
    printf("Seu saldo é de R$ %.2f\n", saldo); // Exibe o saldo formatado
    espereParaContinuar();
}

// Função para autenticação do usuário por senha
int autenticar() {
    int senha;
    printf("Digite sua senha: ");
    scanf("%d", &senha); // Lê a senha digitada pelo usuário
    if (senha == 5432) { // Verifica se a senha está correta
        return 1; // Retorna 1 se a senha estiver correta
    }
    return 0; // Retorna 0 se a senha estiver incorreta
}

// Função principal do programa
int main() {
    int menu = 0; // Variável para armazenar a opção do menu
    double saldo = 0; // Inicializa o saldo da conta
    int historicoIndice = 1; // Inicializa o índice do histórico de transações
    char historico[100][100] = {
        "Seus extratos: ", // Mensagem inicial do histórico
    };

    // Tenta autenticar o usuário
    int logado = autenticar();
    if (logado == 1) {
        printf("Senha aprovada\n"); // Mensagem de sucesso na autenticação
    } else {
        printf("Senha incorreta, tente novamente\n"); // Mensagem de falha na autenticação
        return 0; // Sai do programa se a autenticação falhar
    }
    // Loop principal para exibir o menu do banco e processar as opções
    while (menu != 5)
    {
        system("clear"); // Limpa a tela do console
        printf("Caixa2 simula um banco com depósitos, saques, saldos e extratos báncarios\n");
        printf("Bem Vindo a Caixa2\n");
        printf("1 - Depósito\n");
        printf("2 - Saque\n");
        printf("3 - Saldo\n");
        printf("4 - Extrato de transação da sessão\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &menu); // Lê a opção escolhida pelo usuário

        // Estrutura switch para lidar com as diferentes opções do menu
        switch (menu)
        {
        case 1: {
            deposito(&saldo, &historicoIndice, historico); // Chama a função de depósito
            break;
        }
        case 2: {
            saque(&saldo, &historicoIndice, historico); // Chama a função de saque
            break;
        }
        case 3: {
            verSaldo(saldo); // Chama a função para ver o saldo
            break;
        }
        case 4: {
            extrato(historicoIndice, historico); // Chama a função para ver o extrato
            break;
        }
        case 5: {
            printf("Obrigado pela preferência, volte sempre\n"); // Mensagem de despedida
            espereParaContinuar();
            break;
        }
        default: {
            printf("Essa opção não existe\n"); // Mensagem para opção inválida
            espereParaContinuar();
            break;
        }
        }
    }

    return 0; // Indica que o programa terminou com sucesso
}