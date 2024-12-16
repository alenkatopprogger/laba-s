#include <stdio.h>
#include <stdlib.h>
#include "cone.h"

int main() {
    int N;
    printf("Введите количество конусов (N): ");
    scanf("%d", &N);
    Cone *cones = (Cone *)malloc(N * sizeof(Cone)); //выделение памяти
    for (int i = 0; i < N; i++) { //ввод данных
        printf("Введите радиус основания и высоту конуса %d: ", i + 1);
        scanf("%lf %lf", &cones[i].r, &cones[i].h);
    }
    printf("\nPeзyльтaты:\n");
    for (int i = 0; i < N; i++) {
        printf("Конус %d:\n", i + 1);
        printf("Объём: %.2lf\n", coneV(cones[i]));
        printf("Площадь поверхности: %.2lf\n", coneS(cones[i]));
    }
    free(cones);

    return 0;
}