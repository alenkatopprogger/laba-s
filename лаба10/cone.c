#include "cone.h"
//объем
double coneV(Cone cone) {
    return (1.0/3.0) * M_PI * cone.r * cone.r * cone.h;
}
//площадь
double coneS(Cone cone) {
    double l = sqrt(cone.r * cone.r + cone.h * cone.h); 
    return M_PI * cone.r * (cone.r + l);
}