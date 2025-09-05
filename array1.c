#include<stdio.h>
int main() {
int i,n;
int arr[]={10,20,30,40,50};
n=sizeof(arr)/sizeof(arr[0]);
printf("Original array is : \n");
for(i = 0;i < n ;i++ )
{
printf("%d\n",arr[i]);
printf("\n");
}
int elem;
printf("Enter a new element : ");
scanf("%d",&elem);
arr[n] = elem; 
printf("After insertion the new array is : \n");
for(i = 0;i <= n ;i++ )
{
printf("%d",arr[i]);
printf("\n");
}
return 0;
}