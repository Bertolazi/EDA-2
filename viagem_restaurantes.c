#include <stdio.h>

int main(){
    int n;
    int dia = 1;
    int rpar, rimpar;
    int melhornota, melhorcodigo;
    while (scanf("%d", &n) != EOF) {
        melhornota = -1;
        melhorcodigo = 1e7 + 1;
        for(int i=0; i<2*n; i+=2){
        scanf("%d %d", &rpar, &rimpar);
            if (rimpar > melhornota || (rimpar == melhornota && rpar < melhorcodigo))
            {
                melhornota = rimpar;
                melhorcodigo = rpar;
            }
            
        }
        printf("Dia %d\n", dia);
        printf("%d\n", melhorcodigo);
        printf("\n");
        dia++;
    }
    return 0;
}