

#ifndef MATRIX_H
#define MATRIX_H

struct matrix{
    int columns;   
    int lines;
    int **content;
};

struct matrix* create_matrix(int lines, int columns);

void free_matrix(struct matrix *mat);

#endif
