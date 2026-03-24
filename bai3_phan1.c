#include <stdio.h>

void getKnightRelatedPositions(int m, int n, int i, int j, int results[][2], int *count) {
    int moves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    *count = 0;
    
    for (int k = 0; k < 8; k++) {
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];
        if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
            results[*count][0] = new_i;
            results[*count][1] = new_j;
            (*count)++;
        }
    }
}

int main() {
    int m, n, i, j;
    printf("Nhap kich thuoc ban co:\n");
    printf("So hang m: ");
    scanf("%d", &m);
    printf("So cot n: ");
    scanf("%d", &n);
    printf("\nNhap vi tri hien tai:\n");
    printf("Toa do i: ");
    scanf("%d", &i);
    printf("Toa do j: ");
    scanf("%d", &j);
    if (i < 0 || i >= m || j < 0 || j >= n) {
        printf("\nVi tri (%d, %d) khong hop le tren ban co %dx%d!\n", i, j, m, n);
        return 1;
    }

    int results[8][2];
    int count;
    getKnightRelatedPositions(m, n, i, j, results, &count);
    printf("\n=== KET QUA ===\n");
    printf("Tu vi tri (%d, %d) tren ban co %dx%d:\n", i, j, m, n);
    
    if (count == 0) {
        printf("Khong co vi tri knight-related nao (vi tri nam o goc ban co)!\n");
    } else {
        printf("Co %d vi tri knight-related:\n", count);
        for (int k = 0; k < count; k++) {
            printf("(%d, %d)\n", results[k][0], results[k][1]);
        }
    }
    
    return 0;
}