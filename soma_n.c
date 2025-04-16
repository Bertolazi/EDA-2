#include <stdio.h>

int main(){
    int qntdd;
    int num, resultado = 0;
    scanf("%d", &qntdd);
    for(int i=0; i<qntdd; i++){
        scanf(" %d", &num);
        resultado += num;
    }
    printf("%d\n", resultado);
    return 0;
}