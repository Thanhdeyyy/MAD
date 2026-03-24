#include <stdio.h>
#include <string.h>
#include <math.h>

// Hàm kiểm tra xâu s có xuất hiện trong xâu t hay không
int containsSubstring(char *t, char *s) {
    int len_t = strlen(t);
    int len_s = strlen(s);
    
    if (len_s > len_t) return 0;
    
    for (int i = 0; i <= len_t - len_s; i++) {
        int found = 1;
        for (int j = 0; j < len_s; j++) {
            if (t[i + j] != s[j]) {
                found = 0;
                break;
            }
        }
        if (found) return 1;
    }
    return 0;
}

void nextString(char *str, int n) {
    int i = n - 1;
    while (i >= 0 && str[i] == 'd') {
        str[i] = 'a';
        i--;
    }
    if (i >= 0) {
        str[i]++;
    }
}

int countStringsContaining(char *s, int n) {
    int len_s = strlen(s);
    if (len_s > n) return 0;
    int totalStrings = pow(4, n);
    int countWithout = 0;
    char current[100];
    for (int i = 0; i < n; i++) {
        current[i] = 'a';
    }
    current[n] = '\0';
    for (int i = 0; i < totalStrings; i++) {
        if (!containsSubstring(current, s)) {
            countWithout++;
        }
        nextString(current, n);
    }
    return totalStrings - countWithout;
}

int main() {
    int n;
    char s[100];
    printf("=== Dem so xau chua xau con ===\n\n");
    printf("Nhap do dai n: ");
    scanf("%d", &n);
    printf("Nhap xau s (chi gom cac ky tu a, b, c, d): ");
    scanf("%s", s);
    int valid = 1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] < 'a' || s[i] > 'd') {
            valid = 0;
            break;
        }
    }
    
    if (!valid) {
        printf("Xau s khong hop le! Chi duoc chua cac ky tu a, b, c, d.\n");
        return 1;
    }
    
    int result = countStringsContaining(s, n);
    
    printf("\nket qua\n");
        printf("So xau do dai %d chua xau \"%s\" la: %d\n", n, s, result);
    
    return 0;
}