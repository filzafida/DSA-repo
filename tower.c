#include<stdio.h>
#include<math.h>
void toh(int n,char source,char destination,char auxiliary)
{
    if(n==1)            
    {
        printf("Move disk 1 from rod %c to rod %c\n",source,destination);
        return;
    }
    toh(n-1,source,auxiliary,destination);
    printf("Move disk %d from rod %c to rod %c\n",n,source,destination);
    toh(n-1,auxiliary,destination,source);
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    toh(n,'A','C','B');
    printf("Total number of moves: %d\n", (int)(pow(2,n)-1));
    return 0;
}