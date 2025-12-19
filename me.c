#include <stdio.h>

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high){
    int i = low, j = mid + 1, k = low;
    int B[100];

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while(i <= mid){
        B[k++] = A[i++];
    }

    while(j <= high){
        B[k++] = A[j++];
    }

    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void Merge_sort(int A[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        Merge_sort(A, low, mid);
        Merge_sort(A, mid + 1, high);
        merge(A, mid, low, high);
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

    Merge_sort(A, 0, n - 1);

    printf("\nFinal sorted array:\n");
    printArray(A, n);

    return 0;
}
