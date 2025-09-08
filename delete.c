#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        printf("\n");
    }

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}
