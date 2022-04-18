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

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    print_matrix(c);

    //kiegeszitesek
    float uresmatrix_A[3][3];
    float uresmatrix_B[3][3];
    float uresmatrix_C[3][3];
    float matrix_A[3][3] = {{1.8f, -4.0f, 9.5f},{7.65f, 6.45f, 4.56f},{-9.45f, 4.4f, -9.48f}};
    uresmatrix_C[2][2] = 1;

    float point1[3] = {9, 5, 1};
    float point2[3] = {0,0,0};
    float point3[2] = {5,3};


    init_identity_matrix(uresmatrix_A);
    print_matrix(uresmatrix_A);
    

    matrixScalarMultiplication(matrix_A, 4.6);
    print_matrix(matrix_A);

    multiply_matrices(uresmatrix_A, matrix_A, uresmatrix_B);
    print_matrix(uresmatrix_B);

    scale(uresmatrix_C, 7);
    print_matrix(uresmatrix_C);


    shift(uresmatrix_C, point3);
    print_matrix(uresmatrix_C);

    rotate(uresmatrix_C, 180);
    print_matrix(uresmatrix_C);

    pointTransformation(uresmatrix_C, point1, point2);
    printf("%lf, %lf, %lf\n", point1[0], point2[1], point3[2]);
	return 0;
}

