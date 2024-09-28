#include "./matrix.h"
#include <stdlib.h>

struct matrix* create_matrix(int lines, int columns) {
    if (lines <= 0 || columns <= 0) return NULL; // Check for valid dimensions

    struct matrix* mat = malloc(sizeof(struct matrix)); // Allocate memory for matrix
    if (!mat) return NULL;

    mat->lines = lines;
    mat->columns = columns;

    mat->content = malloc(sizeof(int*) * lines);
    if (!mat->content) { // Check if content allocation was successful
        free(mat); // Free the matrix struct if content allocation fails
        return NULL;
    }

    for (int i = 0; i < lines; i++) {
        mat->content[i] = calloc(columns, sizeof(int));
        if (!mat->content[i]) { // Check if each row allocation was successful
            for (int j = 0; j < i; j++) {
                free(mat->content[j]); // Free previously allocated rows
            }
            free(mat->content);
            free(mat); // Free the matrix struct
            return NULL;
        }
    }

    return mat;
}

void free_matrix(struct matrix *mat) {
    if (!mat) return; // Check if mat is not null
    if (mat->content) { // Check if content is not null
        for (int i = 0; i < mat->lines; i++) { // Change <= to <
            free(mat->content[i]); // Free each row
        }
        free(mat->content); // Free the row pointers
        mat->content = NULL; // Optionally set to NULL
    }
    free(mat); // Free the matrix struct itself
}
