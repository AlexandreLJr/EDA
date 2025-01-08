#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Passa por cada elemento do array
    for (i = 0; i < n - 1; i++) {
        // Encontra o índice do menor elemento na parte não ordenada
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro da parte não ordenada
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array depois da ordenação:\n");
    printArray(arr, n);

    return 0;
}

/*
O algoritmo Selection Sort funciona da seguinte forma:

1. Dividimos o array em duas partes:
   - A parte "ordenada" (que começa vazia).
   - A parte "não ordenada" (que contém todos os elementos inicialmente).

2. Em cada iteração:
   - Localizamos o menor elemento da parte não ordenada.
   - Trocamos esse menor elemento com o primeiro elemento da parte não ordenada.
   - Isso expande a parte ordenada e reduz a parte não ordenada.

3. Continuamos o processo até que toda a parte não ordenada tenha sido processada.

Complexidade do algoritmo:
- Pior caso: O(n²) (devido ao uso de dois loops aninhados).
- Melhor caso: O(n²) (pois sempre percorremos o array para encontrar o menor elemento).
- Espaço: O(1) (é um algoritmo "in-place", ou seja, não usa memória extra significativa).

Exemplo:
Dado o array [64, 25, 12, 22, 11]:

1ª Iteração:
- Menor elemento na parte não ordenada: 11.
- Troca com o primeiro elemento (64).
- Resultado: [11, 25, 12, 22, 64].

2ª Iteração:
- Menor elemento na parte restante: 12.
- Troca com o segundo elemento (25).
- Resultado: [11, 12, 25, 22, 64].

3ª Iteração:
- Menor elemento na parte restante: 22.
- Troca com o terceiro elemento (25).
- Resultado: [11, 12, 22, 25, 64].

4ª Iteração:
- Menor elemento na parte restante: 25.
- Já está no lugar correto (nenhuma troca necessária).
- Resultado final: [11, 12, 22, 25, 64].
*/
