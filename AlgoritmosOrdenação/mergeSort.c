#include <stdio.h>

// Função para mesclar duas metades do array de forma ordenada
void mesclar(int arr[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1; // Tamanho do subarray da esquerda
    int n2 = direita - meio; // Tamanho do subarray da direita

    // Cria subarrays temporários
    int esquerdaArray[n1], direitaArray[n2];

    // Copia os dados para os subarrays temporários
    for (int i = 0; i < n1; i++) {
        esquerdaArray[i] = arr[esquerda + i];
    }
    for (int j = 0; j < n2; j++) {
        direitaArray[j] = arr[meio + 1 + j];
    }

    // Mescla os subarrays de volta para o array original
    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (esquerdaArray[i] <= direitaArray[j]) {
            arr[k] = esquerdaArray[i];
            i++;
        } else {
            arr[k] = direitaArray[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes, se houver
    while (i < n1) {
        arr[k] = esquerdaArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = direitaArray[j];
        j++;
        k++;
    }
}

/*
Função Merge Sort:
1. O Merge Sort é um algoritmo de ordenação baseado na técnica de "dividir para conquistar".
2. Ele divide o array em duas metades, ordena essas metades 
recursivamente e, em seguida, mescla as metades ordenadas de volta.
3. O processo de divisão continua até que as sublistas 
tenham apenas um elemento (que está considerado ordenado).
4. Em seguida, as sublistas são mescladas de forma ordenada 
até que o array inteiro esteja ordenado.

Passos:
- Dividir o array em duas metades.
- Ordenar recursivamente cada metade.
- Mesclar as duas metades de forma ordenada.

A complexidade do Merge Sort é:
- Melhor caso: O(n log n), pois o array é sempre dividido e mesclado de forma eficiente.
- Pior caso: O(n log n), o que é melhor que outros 
algoritmos como o Bubble Sort ou Insertion Sort.
- Espaço: O(n) devido à necessidade de arrays temporários durante a mesclagem.

Exemplo:
Para o array {38, 27, 43, 3, 9, 82, 10}:
- O array é dividido repetidamente até que cada subarray tenha apenas um elemento.
- As metades são mescladas e ordenadas até que o array esteja completamente ordenado.

*/

void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        // Calcula o meio do array
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        // Mescla as duas metades ordenadas
        mesclar(arr, esquerda, meio, direita);
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
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array antes da ordenação
    printf("Array antes da ordenação:\n");
    imprimirArray(arr, tamanho);

    // Chama o Merge Sort
    mergeSort(arr, 0, tamanho - 1);

    // Exibe o array após a ordenação
    printf("Array depois da ordenação:\n");
    imprimirArray(arr, tamanho);

    return 0;
}
