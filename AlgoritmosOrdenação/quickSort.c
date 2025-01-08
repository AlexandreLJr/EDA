#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array
int particionar(int arr[], int inicio, int fim) {
    int pivo = arr[fim]; // Escolhe o último elemento como pivô
    int i = (inicio - 1); // Índice do menor elemento

    int j;
    for (j = inicio; j < fim; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            trocar(&arr[i], &arr[j]);
        }
    }
    // Coloca o pivô na posição correta
    trocar(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

// Função recursiva do Quick Sort
void quickSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Índice do particionamento
        int pi = particionar(arr, inicio, fim);

        // Ordena recursivamente as sublistas
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, fim);
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
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array antes da ordenação
    printf("Array antes da ordenação:\n");
    imprimirArray(arr, tamanho);

    // Chama o Quick Sort
    quickSort(arr, 0, tamanho - 1);

    // Exibe o array após a ordenação
    printf("Array depois da ordenação:\n");
    imprimirArray(arr, tamanho);

    return 0;
}

/*
O algoritmo Quick Sort funciona da seguinte forma:

1. Escolha de um pivô:
   - Um elemento do array é escolhido como "pivô". Neste caso, escolhemos o último elemento.

2. Particionamento:
   - Reorganizamos o array de forma que:
     - Todos os elementos menores ou iguais ao pivô fiquem à esquerda.
     - Todos os elementos maiores fiquem à direita.
   - Após o particionamento, o pivô estará na sua posição final e correta.

3. Divisão recursiva:
   - Chamamos recursivamente o Quick Sort para as sublistas à esquerda e à direita do pivô.
   - O processo continua até que as sublistas tenham tamanho 0 ou 1 (o que significa que já estão ordenadas).

4. Complexidade:
   - Melhor caso: O(n log n), ocorre quando o array é dividido de forma balanceada.
   - Pior caso: O(n²), ocorre quando o pivô escolhido é o maior ou o menor elemento repetidamente (desbalanceamento).
   - Espaço: O(log n) de memória adicional para as chamadas recursivas.

Exemplo:
Dado o array [10, 80, 30, 90, 40, 50, 70]:
1. Escolha do pivô: 70.
2. Particionamento:
   - Menores ou iguais a 70: [10, 30, 40, 50].
   - Maiores que 70: [80, 90].
   - Resultado após particionar: [10, 30, 40, 50, 70, 80, 90].
3. Chamadas recursivas:
   - Quick Sort para a sublista [10, 30, 40, 50].
   - Quick Sort para a sublista [80, 90].
4. Após todas as chamadas, o array estará ordenado.

Vantagens:
- Muito eficiente para grandes conjuntos de dados.
- Não requer memória adicional significativa (é um algoritmo "in-place").

Desvantagens:
- Sensível à escolha do pivô (pior caso ocorre com escolhas ruins).
*/
