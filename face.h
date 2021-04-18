#ifndef FACE_H
#define FACE_H

typedef struct s_Face
{
    int v1;
    int v2;
    int v3;
} Face;

int print_face(Face *pf);

#endif