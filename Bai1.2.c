#include <stdio.h>

int my_strlen(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
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


void next_string(char* s, char* res) {
    int n = my_strlen(s);
    int all_d = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] != 'd') {
            all_d = 0;
            break;
        }
    }

    if (all_d) {
        for (int i = 0; i < n + 1; i++) res[i] = 'a';
        res[n + 1] = '\0';
    } else {
        my_strcpy(res, s);
        for (int i = n - 1; i >= 0; i--) {
            if (res[i] < 'd') {
                res[i] = res[i] + 1;
                break;
            } else {
                res[i] = 'a';
            }
        }
    }
}

int is_wavy(char* s) {
    int n = my_strlen(s);
    if (n < 2) return 1; 

    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
      
            if (!(s[i] < s[i + 1])) return 0;
        } else {
            
            if (!(s[i] > s[i + 1])) return 0;
        }
    }
    return 1;
}

void closest_wavy_behind(char* s, char* res) {
    char current[100];
    char temp[101];
    my_strcpy(current, s);

    while (1) {
        
        next_string(current, temp);
        
       
        if (is_wavy(temp)) {
            my_strcpy(res, temp);
            return; 
        }
        
        my_strcpy(current, temp);
    }
}

int main() {
    char s[100];
    char res[101];
    
    printf("--- PROBLEM 1.2 ---\n");
    printf("Nhap chuoi cua s: ");
    scanf("%s", s);

    closest_wavy_behind(s, res);

    printf("Day luon song gan nhat phia sau: %s\n", res);

    return 0;
}