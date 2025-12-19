#include <stdio.h>

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;

    for(int i = 1; i < n; i++){   // passes
        key = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > key){
            A[j + 1] = A[j];     // shifting elements
            j--;
        }
        A[j + 1] = key;          // placing key at correct position
    }
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    printf("\nOriginal array:\n");
    printArray(A, n);

    insertionSort(A, n);

    printf("\nSorted array:\n");
    printArray(A, n);

    return 0;
}
