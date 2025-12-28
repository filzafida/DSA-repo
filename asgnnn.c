#include <stdio.h>

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    printf("Pairs with sum %d:\n", target);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    int hash[MAX] = {0};

    printf("Pairs with sum %d:\n", target);

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];

        if (complement >= 0 && complement < MAX && hash[complement] > 0) {
            printf("(%d, %d)\n", arr[i], complement);
        }

        if (arr[i] >= 0 && arr[i] < MAX)
            hash[arr[i]]++;
    }

    return 0;
}
*/
