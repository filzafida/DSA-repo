//Bubble Sort an arrary

#include<stdio.h>
int main()
{
  int arr[10]={10,9,8,7,6,5,4,3,2,1},i,j,k;

  for(i=0;i<9;i++)
  {
    for(j=0;j<9-i;j++)
    {
      if(arr[j]>arr[j+1])
      {
        k=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=k;
      }
    }
  }

  for(i=0;i<10;i++)
  {
    printf("%d\n",arr[i]);
  }

  return 0; 
}