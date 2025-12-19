#include <stdio.h>

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(A[j] > A[j + 1]){
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSort_efficient(int *B, int n){
    int isSorted;

    for(int i = 0; i < n - 1; i++){
        printf("Working on pass %d\n", i + 1);
        isSorted = 1;

        for(int j = 0; j < n - i - 1; j++){
            if(B[j] > B[j + 1]){
                int temp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = temp;
                isSorted = 0;
            }
        }

        if(isSorted){
            return;
        }
    }
}

int main(){
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    printf("\nOriginal array:\n");
    printArray(A, n);

    printf("\nChoose Bubble Sort type:\n");
    printf("1. Normal Bubble Sort\n");
    printf("2. Efficient Bubble Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        bubbleSort(A, n);
    } else if(choice == 2){
        bubbleSort_efficient(A, n);
    } else {
        printf("Invalid choice\n");
        return 0;
    }

    printf("\nSorted array:\n");
    printArray(A, n);

    return 0;
}
