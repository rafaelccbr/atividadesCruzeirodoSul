#include <limits.h>
#include <stdio.h>


int main() {
    
    printf("=======================================\n"); // Imprime uma linha decorativa.
    printf("         Bem-vindo ao PedágioDiário!   \n"); // Imprime o nome do programa.
    printf("    Controle de Fluxo de Carros Semanal\n"); // Imprime uma descrição do programa.
    printf("=======================================\n\n"); // Imprime outra linha decorativa e duas quebras de linha.
    
    // Declaração de vetores e Variáveis
    int carrosPorDia[7];// Declara um vetor de inteiros chamado 'carrosPorDia' com 7 posições.
                        // Cada posição representará o número de carros de um dia da semana.

    char *diasDaSemana[7] = {"Domingo", "Segunda-Feira", "Terça-Feira", // Declara um vetor de ponteiros para caracteres (strings).
        "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sábado"};   // Armazena os nomes dos dias da semana para exibição, O '*' indica que é um array de strings.

    int totalCarros = 0; // Declara uma variável inteira 'totalCarros' e a inicializa com 0.
                             
    int diaPicoCarros = INT_MIN; // Declara uma variável inteira 'diaPicoCarros' e a inicializa com o menor valor possível de um int (INT_MIN).

    int indiceDiaPico = -1; // Declara uma variável inteira 'indiceDiaPico' e a inicializa com -1.
                            // Armazenará o índice (posição no vetor) do dia com o maior número de carros. -1 é um valor inválido inicial.
    
    // Leitura dos Dados (Laço de Repetição)
    printf("Por favor, insira o número de carros que passaram no pedágio:\n"); // Solicita ao usuário a entrada dos dados.
    for (int i = 0; i < 7; i++) { // Inicia um laço 'for' que se repetirá 7 vezes (de i=0 até i=6).
                                 // 'i' representa o índice do dia da semana (0 para Domingo, 1 para Segunda, etc.).
        printf(" %s: ", diasDaSemana[i]); // Imprime o nome do dia da semana correspondente ao índice 'i'.
        scanf("%d", &carrosPorDia[i]); // Lê um número inteiro digitado pelo usuário e armazena na posição 'i' do vetor 'carrosPorDia'.

    // Processamento dos Dados
    totalCarros += carrosPorDia[i]; //Adiciona o número de carros do dia atual ao 'totalCarros'.

    // Verifica se o número de carros do dia atual é maior que o 'diaPicoCarros' atual
    if (carrosPorDia[i] > diaPicoCarros) { // Estrutura de decisão.
        diaPicoCarros = carrosPorDia[i]; // Se for maior, atualiza 'diaPicoCarros' com o valor do dia atual.
        indiceDiaPico = i; // Atualiza 'indiceDiaPico' com o índice do dia atual.
        }
    }

    // Exibição dos Resultados (Saída clara e Formatada)
    printf("\n--- Relatório Semanal do Pedágio ---\n"); // Cabeçalho do relatório.

    for (int i = 0; i < 7; i++) { // Outro laço 'for' para exibir os dados de cada dia.
        if (i == indiceDiaPico) { // Verifica se o dia atual é o "Dia de Pico".
            // Destaca "Dia de Pico" com Negrito (usando códigos ANSI para cores/estilos no terminal).
            printf(" \x1b[1;31m%s: %d carros (DIA DE PICO!)\033[0m\n", diasDaSemana[i], carrosPorDia[i]);
            // \033[1m ativa o negrito
            // \033[0m reseta o estilo para o padrão
        } else {
            printf(" %s: %d carros\n", diasDaSemana[i], carrosPorDia[i]); // Exibe o número de carros para os outros dias.
        }
    }

    printf("\n------------------------------------\n"); // Linha separadora.
    printf("Total de carros na semana: %d\n", totalCarros); // Exibe o total de carros na semana.
    printf("Dia de maior movimento: %s com %d carros.\n", diasDaSemana[indiceDiaPico], diaPicoCarros); // Exibe o dia de pico e seu número de carros.
    printf("\n------------------------------------\n"); // Outra linha separadora
    printf("\nObrigado por usar o PedágioDiário!\n"); // Mensagem de despedida.

    return 0; // Indica que o programa foi executado com sucesso.
}