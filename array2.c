#include<stdio.h>
int main() {
    int i,n;
    int arr[]={10,20,30,40,50};
    n=sizeof(arr)/sizeof(arr[0]);
    printf("Original array is : \n");
    for(i = 0;i < n ;i++ )
    {
        printf("%d ",arr[i]);
        printf("\n");
    }
    int elem,k;
    printf("Enter position to insert : \n");
    scanf("%d", &k);

    if (k < 0 || k > n) {
        printf("Invalid position!\n");
        return 1;
    }

    printf("Enter value to insert:\n ");
    scanf("%d", &elem);

   
    for (i = n; i > k; i--) {
        arr[i] = arr[i - 1];
    }

    arr[k] = elem;
    n++; 

    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        printf("\n");
    }
    printf("\n");

    return 0;
}
