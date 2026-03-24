#include <stdio.h>

int my_strlen(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

int my_strcmp(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

void my_strcpy(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int is_wavy(char* s) {
    int n = my_strlen(s);
    if (n < 2) return 1;
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            if (!(s[i] < s[i+1])) return 0;
        } else {
            if (!(s[i] > s[i+1])) return 0;
        }
    }
    return 1;
}

int increment_same_length(char* s) {
    int n = my_strlen(s);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] < 'd') {
            s[i] = s[i] + 1;
            return 1; 
        } else {
            s[i] = 'a';
        }
    }
    return 0; 
}

int count_wavy_before(char* s) {
    int n = my_strlen(s);
    char current[100];
    int count = 0;

    for (int i = 0; i < n; i++) {
        current[i] = 'a';
    }
    current[n] = '\0';

    while (my_strcmp(current, s) < 0) {
        if (is_wavy(current)) {
            count++;
        }

        if (!increment_same_length(current)) break;
    }

    return count;
}

int main() {
    char s[100];

    printf("Nhap chuoi cua s: ");
    if (scanf("%s", s) != 1) return 1;

    int result = count_wavy_before(s);

    printf("So luong day luon song truoc %s: %d\n", s, result);

    return 0;
}