#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);


//Kiegeszitesek
void init_identity_matrix(float matrix[3][3]);

void matrixScalarMultiplication(float matrix[3][3], float scalar);

void multiply_matrices(float aMatrix[3][3], float bMatrix[3][3], float cMatrix[3][3]);

void pointTransformation(float matrix[3][3], float point[3], float returnVektor[3]);

void scale(float matrix[3][3], float s);

void shift(float matrix[3][3], float vector[2]);

void rotate(float matrix[3][3], float r);

#endif // MATRIX_H

