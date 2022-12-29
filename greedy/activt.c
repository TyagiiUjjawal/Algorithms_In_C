#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct activity
{
    int start;
    int finish;
}act;


void sort(act *it, int n)
{
    for (int i = 2; i <= n; i++)
    {
        int j = i - 1;
        act m = it[i];
        int key = it[i].finish;
        while (j >= 1 && it[j].finish > key)
        {
            it[j + 1] = it[j];
            j--;
        }
        it[j + 1] = m;
    }
}


int A_S(act *arr,int i,int j)
{
    sort(arr,j);
    act selected = arr[i];
    int count = 1;
    for (int k = 2; k <= j; k++)
    {
        if (arr[k].start >= selected.finish)
        {
            count++;
            selected = arr[k];
        }
        
    }
    return count;
}


int main()
{
    int n;
    printf("\nEnter the number of activities : ");
    scanf("%d",&n);
    act arr[n+1];
    printf("\nEnter the data for each activity : \n");
    for (int i = 1; i <= n; i++)
    {
        printf("\nEnter the start time and finish time for activity no. %d : ",i);
        scanf("%d%d",&arr[i].start,&arr[i].finish);
    }
    
    int count = A_S(arr,1,n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d : %d  %d\n",i,arr[i].start,arr[i].finish);
    }
    
    
    printf("\nCount of Answer set is : %d",count);
    return 0;
}
