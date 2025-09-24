#include <stdio.h>

// Função para imprimir o vetor
void imprimirVetor(int arr[], int tamanho, const char *mensagem) {
    printf("%s: ", mensagem);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para aplicar o Bubble Sort em ordem crescente
void bubbleSortCrescente(int arr[], int tamanho) {
    // Declaração de variáveis para os laços e para a troca
    int i, j, temp;
    // O laço externo percorre todo o vetor
    for (i = 0; i < tamanho - 1; i++) {
        // O laço interno compara os elementos adjacentes
        // A cada passagem do laço externo, o maior elemento "flutua" para a sua posição correta no final do vetor
        // Por isso, tamanho - 1 - i para otimizar, pois os últimos 'i' elementos já estão ordenados
        for (j = 0; j < tamanho - 1 - i; j++) {
            // Se o elemento atual for maior que o próximo, eles são trocados
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];        // Armazena o valor do elemento atual
                arr[j] = arr[j + 1];  // Atribui o valor do próximo ao atual
                arr[j + 1] = temp;    // Atribui o valor armazenado (original do atual) ao próximo
            }
        }
    }
}

// Função para aplicar o Bubble Sort em ordem decrescente
void bubbleSortDecrescente(int arr[], int tamanho) {
    // Declaração de variáveis para os laços e para a troca
    int i, j, temp;
    // O laço externo percorre todo o vetor
    for (i = 0; i < tamanho - 1; i++) {
        // O laço interno compara os elementos adjacentes
        // A cada passagem do laço externo, o menor elemento "flutua" para a sua posição correta no final do vetor
        // Por isso, tamanho - 1 - i para otimizar, pois os últimos 'i' elementos já estão ordenados
        for (j = 0; j < tamanho - 1 - i; j++) {
            // Se o elemento atual for MENOR que o próximo, eles são trocados
            // A diferença para a ordem crescente está aqui: ">" se torna "<"
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];        // Armazena o valor do elemento atual
                arr[j] = arr[j + 1];  // Atribui o valor do próximo ao atual
                arr[j + 1] = temp;    // Atribui o valor armazenado (original do atual) ao próximo
            }
        }
    }
}

int main() {
    // 1. Definir um vetor com 10 valores (pesos de encomendas)
    int pesos[] = {75, 23, 10, 88, 5, 42, 17, 91, 30, 64};
    int tamanho = sizeof(pesos) / sizeof(pesos[0]); // Calcula o tamanho do vetor

    // Cria cópias do vetor original para ordenação
    // Isso é importante para que possamos ordenar em crescente e decrescente
    // sem afetar o vetor original ou a ordenação anterior.
    int pesosCrescente[tamanho];
    int pesosDecrescente[tamanho];

    // Copia os elementos do vetor original para as cópias
    for (int i = 0; i < tamanho; i++) {
        pesosCrescente[i] = pesos[i];
        pesosDecrescente[i] = pesos[i];
    }

    // 2. Exibir os dados originais do vetor
    imprimirVetor(pesos, tamanho, "Pesos Originais das Encomendas");

    // 3. Aplicar o algoritmo de ordenação Bubble Sort em ordem crescente
    bubbleSortCrescente(pesosCrescente, tamanho);

    // 4. Exibir o vetor ordenado em ordem crescente
    imprimirVetor(pesosCrescente, tamanho, "Pesos Ordenados em Ordem Crescente");

    // Aplicar o algoritmo de ordenação Bubble Sort em ordem decrescente
    bubbleSortDecrescente(pesosDecrescente, tamanho);

    // Exibir o vetor ordenado em ordem decrescente
    imprimirVetor(pesosDecrescente, tamanho, "Pesos Ordenados em Ordem Decrescente");

    printf("\nProcesso de ordenação concluído com sucesso!\n");

    return 0; // Indica que o programa terminou com sucesso
}