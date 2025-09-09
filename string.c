#include <stdio.h>
// length of the string
int stringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Copy one string into another
void stringCopy(char str1[], char str2[]) {
    int i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

// Compare two strings
int stringCompare(char str1[], char str2[],int length1,int length2) {
    int i = 0;
    if (length1==length2)
    {
          while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {

         return 0; 
        }
        else{
            return 1; 
        }
        i++;
    }
    }
    else{
    return str1[i] - str2[i];
    }
    return 0;
}

//  Concatenate two strings
void stringConcat(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0') {
        i++; 
    }

    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main() {
    char str1[100] = "Hello";
    char str2[] = "Wor";
    char str3[100]; 

   
    int len1 = stringLength(str1);
    printf("Length of str1: %d\n", len1);
    int len2=stringLength(str2);
    printf("Length of str12: %d\n", len2);
    
    stringCopy(str3, str1);
    printf("str3 after cpy: %s\n", str3);

   
    int cmp = stringCompare(str1,str2,len1,len2);
    if (cmp == 0) {
        printf("str1 and str2 are equal\n");
    } else if (cmp > 0) {
        printf("str1 is greater than str2\n");
    } else {
        printf("str1 is less than str2\n");
    }

    stringConcat(str1, str2);
    printf("After concatenation, str1: %s\n", str1);

    return 0;
}
