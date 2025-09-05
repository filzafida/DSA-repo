#include<stdio.h>
int main() {
int i,n;
int arr[]={10,20,30,40,50};
n=sizeof(arr)/sizeof(arr[0]);
for(i = 0;i < n ;i++ )
{
printf("%d\n",arr[i]);
printf("\n");

}
int elem;
printf("Enter a new element : ");
scanf("%d",&elem);
for(i = n - 1;i >= 0 ;i-- )
{
arr[i + 1] = arr[i];
}
arr[0] = elem;
printf("After insertion the new array is : \n");
for(i = 0;i <= n ;i++ )
{
printf("%d",arr[i]);
printf("\n");
}
return 0;
}