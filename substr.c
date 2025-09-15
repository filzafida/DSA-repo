#include <stdio.h>
#define SIZE 100

// Function to compute string length manually
int str_len(char* str) {
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }
    return i;
}

// Function to check for substring
void substring_func(char* str, char* substr) {
    int len1 = str_len(str);
    int len2 = str_len(substr);
    int i, j, found;

    if (len1 < len2) {
        printf("Substring too long\n");
        return;
    }

    for (i = 0; i <= len1 - len2; i++) {
        found = 1;  // assume match
        for (j = 0; j < len2; j++) {
            if (str[i + j] != substr[j]) {
                found = 0;  // mismatch
                break;
            }
        }

        if (found) {
            printf("Substring is found starting from position %d\n", i + 1);
            return;
        }
    }

    printf("Substring not found\n");
}

int main() {
    char str[SIZE], substr[SIZE];

    printf("Input the string: ");
    fgets(str, SIZE, stdin);

    printf("Enter the substring to be searched for: ");
    fgets(substr, SIZE, stdin);

    substring_func(str, substr);

    return 0;
}
