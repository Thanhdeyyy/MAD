#include <stdio.h>

void product(int M[2][2], int N[2][2], int result[2][2]) {
    result[0][0] = M[0][0] * N[0][0] + M[0][1] * N[1][0];
    result[0][1] = M[0][0] * N[0][1] + M[0][1] * N[1][1];
    result[1][0] = M[1][0] * N[0][0] + M[1][1] * N[1][0];
    result[1][1] = M[1][0] * N[0][1] + M[1][1] * N[1][1];
}

void printMatrix(int matrix[2][2], char* name) {
    printf("%s = \n", name);
    printf("[%d, %d]\n", matrix[0][0], matrix[0][1]);
    printf("[%d, %d]\n", matrix[1][0], matrix[1][1]);
    printf("\n");
}

int main() {
    int A[2][2] = {{3, -4}, {2, -1}};
    int B[2][2] = {{2, -3}, {1, 4}};
    int result1[2][2];
    int result2[2][2];  
    printf("Kiem tra ham nhan ma tran 2x2 \n");
    printMatrix(A, "Ma tran A");
    printMatrix(B, "Ma tran B");
    product(A, B, result1);
    printf("A * B = \n");
    printMatrix(result1, "");
    product(B, A, result2);
    printf("B * A = \n");
    printMatrix(result2, "");
    printf("Kiem tra tinh khong giao hoan\n");
    printf("A * B != B * A\n");
    printf("(A*B)[0][0] = %d, (B*A)[0][0] = %d\n", result1[0][0], result2[0][0]);
    
    return 0;
}