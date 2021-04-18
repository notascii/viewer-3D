#include <stdlib.h>
#include <stdio.h>
#include "point.h"

int print_point(Point *pa)
{
    if (pa == NULL) {
        printf("(3) error : NULL pointer\n");
        return (-1);
    }
    printf("(%f, %f, %f)\n", pa->x, pa->y, pa->z);
    return (0);
}

Point *create_point(double x, double y, double z)
{
    Point *pa;
    pa = malloc(sizeof(Point));

    pa->x = x;
    pa->y = y;
    pa->z = z;
    return (pa);
}