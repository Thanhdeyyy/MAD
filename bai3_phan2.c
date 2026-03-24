#include <stdio.h>
#include <limits.h>

int findMinKnightSum(int m, int n, int A[m][n], int pos1[2], int pos2[2]) {
    int moves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    int min_sum = INT_MAX;
    int found = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 8; k++) {
                int new_i = i + moves[k][0];
                int new_j = j + moves[k][1];
                
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                    int current_sum = A[i][j] + A[new_i][new_j];

                    if (i < new_i || (i == new_i && j < new_j)) {
                        if (current_sum < min_sum) {
                            min_sum = current_sum;
                            pos1[0] = i;
                            pos1[1] = j;
                            pos2[0] = new_i;
                            pos2[1] = new_j;
                            found = 1;
                        }
                    }
                }
            }
        }
    }
    
    if (!found) {
        return INT_MAX;
    }
    return min_sum;
}

int main() {
    int m, n;
    printf("Nhap so hang m: ");
    scanf("%d", &m);
    printf("Nhap so cot n: ");
    scanf("%d", &n);
    
    int A[m][n];
    printf("\nNhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nMa tran vua nhap:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    
    int pos1[2], pos2[2];
    int min_sum = findMinKnightSum(m, n, A, pos1, pos2);
    
    if (min_sum != INT_MAX) {
        printf("\n=== KET QUA ===\n");
        printf("Tong nho nhat: %d\n", min_sum);
        printf("Hai vi tri: (%d, %d) va (%d, %d)\n", 
               pos1[0], pos1[1], pos2[0], pos2[1]);
        printf("Gia tri: %d + %d = %d\n",
               A[pos1[0]][pos1[1]], A[pos2[0]][pos2[1]], min_sum);
    } else {
        printf("\nKhong tim thay cap knight-related nao tren ban co!\n");
    }
    
    return 0;
}