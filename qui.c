#include <stdio.h>

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int Partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do{
        while(A[i] <= pivot && i <= high){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }
        if(i < j){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while(i < j);

    // swap pivot with A[j]
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void Quick_sort(int A[], int low, int high){
    if(low < high){
        int PartitionIndex = Partition(A, low, high);

        printArray(A, high + 1); // to see partitions

        Quick_sort(A, low, PartitionIndex - 1);
        Quick_sort(A, PartitionIndex + 1, high);
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

    Quick_sort(A, 0, n - 1);

    printf("\nFinal sorted array:\n");
    printArray(A, n);

    return 0;
}
