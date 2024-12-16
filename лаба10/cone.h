#ifndef CONE_H
#define CONE_H
#include <math.h>

typedef struct {
    double r;
    double h;
} Cone;

double coneV(Cone cone);
double coneS(Cone cone);

#endif