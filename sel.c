#include <stdio.h>

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selection_sort(int *A, int n){
    int indexOfMin;

    for(int i = 0; i < n - 1; i++){
        indexOfMin = i;

        for(int j = i + 1; j < n; j++){
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;   // index of smallest element
            }
        }

        // swap A[i] and A[indexOfMin]
        int temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
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

    selection_sort(A, n);

    printf("\nSorted array:\n");
    printArray(A, n);

    return 0;
}
