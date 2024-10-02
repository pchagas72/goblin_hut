#include "./matrix.h"

struct matrix* create_matrix(int lines, int columns) {
    if (lines <= 0 || columns <= 0) return NULL; 

    struct matrix* mat = malloc(sizeof(struct matrix)); // Allocate memory for matrix
    if (!mat) return NULL;

    mat->lines = lines;
    mat->columns = columns;

    mat->content = malloc(sizeof(int*) * lines);
    if (!mat->content) { 
        free(mat); // Free the matrix struct 
        return NULL;
    }

    for (int i = 0; i < lines; i++) {
        mat->content[i] = calloc(columns, sizeof(int));
        if (!mat->content[i]) { // Check if each row allocation was successful
            for (int j = 0; j < i; j++) {
                free(mat->content[j]); // Free previously allocated rows
            }
            free(mat->content);
            free(mat); 
            return NULL;
        }
    }

    return mat;
}

void free_matrix(struct matrix *mat) {
    if (!mat) return; 
    if (mat->content) { 
        for (int i = 0; i < mat->lines; i++) {
            free(mat->content[i]); // Free each row
        }
        free(mat->content); 
        mat->content = NULL; 
    }
    free(mat); // Free the matrix struct itself
}
