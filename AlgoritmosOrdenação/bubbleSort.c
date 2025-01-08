#include <stdio.h>

/*
Função Bubble Sort:
1. O algoritmo percorre o array diversas vezes.
2. A cada passagem, ele compara elementos adjacentes e troca de lugar se o 
elemento à esquerda for maior que o da direita.
3. Isso "empurra" os elementos maiores para o final do array.
4. O processo é repetido para cada elemento até que o array esteja completamente ordenado.

Passos:
- Durante a primeira passagem, o maior elemento é movido para a última posição.
- Em seguida, o processo é repetido para o restante do array, ignorando 
a última posição (que já está ordenada).
- Esse processo continua até que não seja necessário mais nenhuma troca.

A complexidade do Bubble Sort é:
- Melhor caso: O(n) quando o array já está ordenado (caso de otimização).
- Pior caso: O(n²) quando o array está em ordem inversa.
- Espaço: O(1), pois é feito in-place.

Exemplo:
Para o array {64, 34, 25, 12, 22, 11, 90}:
- A cada iteração, o maior número é "empurrado" para o final do array.

*/

void bubbleSort(int arr[], int tamanho) {
    // Loop para percorrer o array repetidamente
    for (int i = 0; i < tamanho - 1; i++) {
        // Flag para otimizar o algoritmo (caso o array já esteja ordenado)
        int trocou = 0;

        // Comparar e trocar elementos adjacentes
        for (int j = 0; j < tamanho - i - 1; j++) {
            // Se o elemento da esquerda for maior que o da direita, troca
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Marca que ocorreu uma troca
                trocou = 1;
            }
        }

        // Se não houve troca, o array já está ordenado, então termina
        if (trocou == 0) {
            break;
        }
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Array fixo para ordenação
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array antes da ordenação
    printf("Array antes da ordenação:\n");
    imprimirArray(arr, tamanho);

    // Chama o Bubble Sort
    bubbleSort(arr, tamanho);

    // Exibe o array após a ordenação
    printf("Array depois da ordenação:\n");
    imprimirArray(arr, tamanho);

    return 0;
}
