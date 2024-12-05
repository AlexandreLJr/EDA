#include <stdio.h>

int AckermannRecursivo(int m, int n){
    if (m == 0){
        return n + 1;
     }else if(m > 0 && n==0){
        return AckermannRecursivo(m-1, 1);
     }else{
        return AckermannRecursivo(m-1, AckermannRecursivo(m, n-1));
    }
}

int main (){
    int m, n, result;
    printf("Digite dois numeros positivos \n");
    scanf("%d %d", &m, &n);
    result=AckermannRecursivo(m,n);

    printf("O valor da funcao de Ackermann para m = %d e n = %d eh %d\n", m, n, result);
    return 0;
}