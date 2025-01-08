#include <stdio.h>

// Função para realizar o Insertion Sort
void insertionSort(int arr[], int tamanho) {
    int i;
    for (i = 1; i < tamanho; i++) {
        int chave = arr[i]; // Elemento a ser inserido na posição correta
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição para frente
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insere a chave na posição correta
        arr[j + 1] = chave;
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Array fixo para ordenação
    int arr[] = {12, 11, 13, 5, 6};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array antes da ordenação
    printf("Array antes da ordenação:\n");
    imprimirArray(arr, tamanho);

    // Chama o Insertion Sort
    insertionSort(arr, tamanho);

    // Exibe o array após a ordenação
    printf("Array depois da ordenação:\n");
    imprimirArray(arr, tamanho);

    return 0;
}

/*
Função de Insertion Sort:
1. O algoritmo percorre o array a partir do segundo elemento (índice 1).
2. Para cada elemento, ele o compara com os elementos anteriores para encontrar a posição correta.
3. Ele move todos os elementos maiores do que o atual uma posição para a direita.
4. Depois de encontrar o local correto, o elemento é inserido na posição adequada.

Passos:
- Inicialmente, o primeiro elemento é considerado já ordenado.
- O segundo elemento é comparado com o primeiro e colocado na posição correta.
- Esse processo se repete até que todos os elementos estejam na posição correta.

Exemplo:
Para o array {12, 11, 13, 5, 6}:
- A chave começa com o elemento na posição 1 (11), que é comparado com 12 e colocado antes de 12.
- Isso é repetido para todos os outros elementos.

A complexidade do Insertion Sort é:
- Melhor caso: O(n) quando o array já está ordenado.
- Pior caso: O(n²) quando o array está em ordem inversa.
- Espaço: O(1), pois é feito in-place.

*/