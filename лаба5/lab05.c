#include <stdio.h>

int main() {
    int a;
    printf("Введите целое число:");
    scanf("%d", &a);
    
    int pos = 0;
    int mask = 1; 

    while ((a & mask) != 0) {
        mask <<= 1; 
        pos++; 
    }
    
    printf("Номер последнего нулевого бита: %d\n\n", pos);
    
    return 0;
}