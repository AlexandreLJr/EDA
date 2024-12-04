#include <stdio.h>
#include <conio.h>
int expo(int x, int y)
{
    if (y == 0) //um numero elevado a 0 eh igual a 1
        return 1;
    if (y == 1) //um numero elevado a 1 eh igual a ele mesmo
        return x; 
    return x*expo(x,y-1); //recursividade 
    /*Funcao vai 'subindo'
    eh chamada ate o valor de y ser 0 ou 1
    depois os resultado vao subindo e se multiplicando ate a primeira chamada, que será o resultado*/
}

int main(void) {
    int x, y, e;
    printf("Exponencial de x elevado a y\n\n");
    printf("\nDigite o numero inteiro x:");
    scanf("%d", &x);
    printf("\nDigite o numero inteiro y:");
    scanf("%d", &y);
    if (y < 0) {
        printf("y tem que ser maior ou igual a zero!!");
        getch(); }
    else{
        e=expo(x,y);
        printf("\n\nX elevado a y eh: %d", e);
        getch();} 
}