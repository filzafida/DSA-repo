#include <stdio.h>

int isSubstring(char *str, char *substr) {
    int i = 0, j = 0;

    // Iterate through main string
    while (str[i] != '\0') {
        // If characters match, start comparing
        if (str[i] == substr[0]) {
            j = 0;
            int k = i;
            while (str[k] != '\0' && substr[j] != '\0' && str[k] == substr[j]) {
                k++;
                j++;
            }

            // If we reached end of substr, match found
            if (substr[j] == '\0') {
                return 1;  // True
            }
        }
        i++;
    }

    return 0;  // False
}

int main() {
    char str[] = "hello world";
    char substr[] = "world";

    if (isSubstring(str, substr)) {
        printf("Substring found!\n");
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
