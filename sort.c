#include <stdio.h>

int main() {
        int n=2;
        int array[n]={4,0};
                for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < n-i-1; j++) {
                if (array[j] > array[j+1]) {
                        int temp = array[j];
                        array[j] = array[j+1]
                        array[j+1] = temp
                }
                }
        for (int i=0; i<n; i++)
                printf(" %d", array[i]);
        return 0;
        }
}
//комментарий для пункта9
//комментарий для пункта13

