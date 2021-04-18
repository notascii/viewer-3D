#include <stdlib.h>
#include <stdio.h>
#include "face.h"

int print_face(Face *pf)
{
    if (pf == NULL) {
        printf("(3) error : NULL pointer\n");
        return (-1);
    }
    printf("(%d, %d, %d)\n", pf->v1, pf->v2, pf->v3);
    return (0);
}