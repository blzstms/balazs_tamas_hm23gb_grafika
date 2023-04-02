#include "matrix.h"

#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}


void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (i == j) {
                matrix[i][j] = 1.0;
            }
            else {
                matrix[i][j] = 0.0;
            }
        }
    }



}

void mult_scalar_matrix(float result [3][3], float scalar, const float matrix [3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            result[i][j] = scalar * matrix[i][j];
        }
    }



}

 void multiply_matrices( const float a[3][3], const float b[3][3], float result[3][3])
 {

    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }




 }

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void transform_point(const float matrix[3][3], float point[3], float transformed_point[3])
{
    int i, j;
    for (i = 0; i < 3; i++) {
        transformed_point[i] = 0;
        for (j = 0; j < 3; j++) {
            transformed_point[i] = transformed_point[i] + matrix[i][j] * point[j];
        }
    }
}

void scale(float matrix[3][3], float sx, float sy)
{

    matrix[0][0] *= sx;
    matrix[0][1] *= sx;
    matrix[1][0] *= sy;
    matrix[1][1] *= sy;
}

void shift(float matrix[3][3], float tx, float ty)
{
    matrix[0][2] += tx;
    matrix[1][2] += ty;

}

 void rotate(float matrix[3][3], float angle)
 {
    float rad = angle * M_PI / 180.0;
    float c = cos(rad);
    float s = sin(rad);
    float temp[3][3] = {{c, -s, 0}, {s, c, 0}, {0, 0, 1}};
    float result[3][3];

    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (k = 0; k < 3; k++) {
                result[i][j] += temp[i][k] * matrix[k][j];
            }
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrix[i][j] = result[i][j];
        }
    }
 }





