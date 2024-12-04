#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocaEstoque(TEstoque *pEstoque) {
    scanf("%d", &pEstoque->qtdeProdutos);
    pEstoque->produtos = (TProduto *)malloc(pEstoque->qtdeProdutos * sizeof(TProduto));
}

void incluirProdutos(TEstoque *pEstoque){
    for (int i = 0; i < pEstoque->qtdeProdutos; i++){
        scanf("%d %d %f", 
        &pEstoque->produtos[i].id, 
        &pEstoque->produtos[i].quantidade, 
        &pEstoque->produtos[i].preco);
    }
}

void listarProdutos(TEstoque *pEstoque){
    for (int i = 0; i < pEstoque->qtdeProdutos; i++) {
        printf("ID: %d, Qt:%d, Preço: %.2f\n", 
               pEstoque->produtos[i].id, 
               pEstoque->produtos[i].quantidade, 
               pEstoque->produtos[i].preco);
    }
}

void desalocaEstoque(TEstoque *pEstoque) {
    free(pEstoque->produtos);
    pEstoque->produtos = NULL;  
    pEstoque->qtdeProdutos = 0;  
}

int main()
{
    TEstoque Estoque;
    alocaEstoque(&Estoque);
    incluirProdutos(&Estoque);
    listarProdutos(&Estoque);
    desalocaEstoque(&Estoque);
    return 0;
}