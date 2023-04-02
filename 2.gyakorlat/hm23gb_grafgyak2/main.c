#include "matrix.h"

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

	float p[3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);

    print_matrix(b);

    add_matrices(a, b, c);

    print_matrix(c);
    printf("\n");

    /*init_identity_matrix(a);
    printf("Identity matrix:\n");
    print_matrix(a);
    printf("\n");*/

    /*mult_scalar_matrix(b, 1000, a);
    printf("Multiple by scalar:\n");
    print_matrix(b);
    printf("\n");*/

    /*multiply_matrices(a, b, c);
    printf("Multiple two matrix:\n");
    print_matrix(c);
    printf("\n");*/

    float matrix[3][3] = {{1, 0, 2}, {0, 1, 3}, {0, 0, 1}};
    float point[3] = {1, 1, 1};
    float transformed_point[3];
    transform_point(matrix, point, transformed_point);
    printf("Transformed point: (%.2f, %.2f, %.2f)\n", transformed_point[0], transformed_point[1], transformed_point[2]);


    scale(matrix, 2, 3);
    printf("Scaled matrix: \n");
    print_matrix(matrix);

    shift(matrix, 5, 2);
    printf("Shifted matrix: \n");
    print_matrix(matrix);
    printf("\n");

    rotate(matrix, 45);
    printf("Rotated matrix: \n");
    print_matrix(matrix);







	return 0;
}
