#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Initializes an identity matrix.
 */

void init_identity_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
 * Multiply a matrix by a real value.
 */

void mult_scalar_matrix(float result [3][3], float scalar, const float matrix [3][3]);

/**
 * Multiply two matrix.
 */

 void multiply_matrices( const float a[3][3], const float b[3][3], float result[3][3]);

 /**
 * Transform a point from matrix.
 */

void transform_point(const float matrix[3][3], float point[3], float transformed_point[3]);

 /**
 * Scale a matrix.
 */

void scale(float matrix[3][3], float sx, float sy);

/**
 * Shift a matrix.
 */

void shift(float matrix[3][3], float tx, float ty);

 /**
 * Rotate a matrix.
 */

void rotate(float matrix[3][3], float angle);

#endif // MATRIX_H

