#include <stdio.h>

int main() {
    int N;                
    int count = 0;        
    while (scanf("%d", &N) != EOF) {
        count++;          
    }
    printf("%d\n", count);
    return 0;
}
