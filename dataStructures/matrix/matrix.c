#include "./matrix.h"
#include <stdlib.h>

struct matrix* create_matrix(int lines, int columns) {
    struct matrix* mat = (struct matrix *)malloc(sizeof(struct matrix)); // Allocate memory for matrix
    if (!mat) return NULL;

    mat->lines = lines;
    mat->columns = columns;

    mat->content = (int **)malloc(lines * sizeof(int**));
    if (!mat->content) {
        free(mat); // If stuff goes wrong, free previously allocated memory
        return NULL;
    }

    for (int i = 0; i < lines; i++) {
        mat->content[i] = (int *)malloc(columns * sizeof(int)); // Allocate memory for each column
        if (!mat->content[i]) { // Correct check
            for (int j = 0; j < i; j++) {
                free(mat->content[j]);
            }
            free(mat->content);
            free(mat);
            return NULL;
        }
    }
    return mat;
}

void free_matrix(struct matrix *mat) {
    if (mat->content) { // Check if content is not null
        for (int i = 0; i < mat->lines; i++) {
            free(mat->content[i]); // Free each row
        }
        free(mat->content); // Free the row pointers
        mat->content = NULL; // Optionally set to NULL
    }
    free(mat); // Free the matrix struct itself
}

