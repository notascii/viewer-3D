#ifndef POINT_H
#define POINT_H

typedef struct s_Point
{
    double x;
    double y;
    double z;
} Point;

int print_point(Point *pa);
Point *create_point(double x, double y, double z);

#endif