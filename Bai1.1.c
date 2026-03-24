#include <stdio.h>

int my_strlen(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void my_strcpy(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

void next_string(char* s, char* result) {
    int n = my_strlen(s); 
    int all_d = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] != 'd') {
            all_d = 0;
            break;
        }
    }

    if (all_d) {
       
        for (int i = 0; i < n + 1; i++) {
            result[i] = 'a';
        }
        result[n + 1] = '\0';
    } else {
        my_strcpy(result, s);
        for (int i = n - 1; i >= 0; i--) {
            if (result[i] < 'd') {
                result[i] = result[i] + 1; 
                break;
            } else {
                result[i] = 'a';
            }
        }
    }
}

int main() {
    printf("--- PROBLEM 1.1 ---\n"); 
    char input[100];
    char output[101];

    printf("Nhap chuoi chi co (a, b, c, d): ");
    if (scanf("%s", input) != 1) return 1;

    next_string(input, output);

    printf("Ket qua cua next(%s) = %s\n", input, output);

    return 0;
}