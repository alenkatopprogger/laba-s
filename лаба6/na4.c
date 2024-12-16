#include <stdio.h>

#define k 5

int main(){

int a[k] = {1, 2, 3, 4, 5};
int b[k] = {6, -7, -8, -9, 2};
int c[k];
float s_c;
int max_a = a[0];
int n = 0;

for (int i = 0; i < k; i ++){
    c[i] = a[i] + b[i]; 
    s_c += c[i]; 
    
    if (i % 2 == 0){
        
        if (max_a < a[i]){
            max_a = a[i];
        }
    }
    
    if ( (i % 2 != 0) && (b[i] < 0)){
        n += 1; 
    }
}

printf("Максимальное реальное число в а: %d\n", max_a);
printf("Количество мнимых частей, которые меньше 0: %d\n", n);
printf("Cреднее арифметическое массива с:%f\n", s_c/k);
}