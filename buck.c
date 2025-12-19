#include <stdio.h>

// Function to print array
void printArray(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Bucket Sort function
void bucketSort(int A[], int n){
    int max = A[0];

    // Find maximum element
    for(int i = 1; i < n; i++){
        if(A[i] > max){
            max = A[i];
        }
    }

    // Create buckets
    int bucket[max + 1];

    // Initialize buckets with 0
    for(int i = 0; i <= max; i++){
        bucket[i] = 0;
    }

    // Store frequencies
    for(int i = 0; i < n; i++){
        bucket[A[i]]++;
    }

    // Reconstruct the array
    int index = 0;
    for(int i = 0; i <= max; i++){
        while(bucket[i] > 0){
            A[index++] = i;
            bucket[i]--;
        }
    }
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements (non-negative integers):\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    printf("\nOriginal array:\n");
    printArray(A, n);

    bucketSort(A, n);

    printf("\nSorted array:\n");
    printArray(A, n);

    return 0;
}
