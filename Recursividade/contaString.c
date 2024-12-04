#include <stdio.h>
int tamstring(char s[])
{
    if (s[0] == '\0')
        return 0;
    return 1+tamstring(&s[1]);
/*recusrsao : adiciona uma unidade a
cada chamadada, ate que o valor da string for 0
Basicamente vai "pulando cada casa da string, ate a ultima casa"*/
}

int main(void)
{
    char s[20];
    int t;
    printf("Tamanho de string\n\n");
    printf("\nDigite a string: ");
    scanf("%s", s);
    t=tamstring(s);
    printf("\n\nO tamanho eh %d", t);
    getch(); 
}