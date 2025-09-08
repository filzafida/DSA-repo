#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k ;

    printf("Original array:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
        printf("\n");
    }
     printf("Enter position to delete: \n");
    scanf("%d", &k);

    
    if (k < 0 || k >= n) {
        printf("Invalid index to delete.\n");
        return 1;
    }

    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1]; 
        printf("\n");
    }

    n--; 

    printf("Array after deletion :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}
