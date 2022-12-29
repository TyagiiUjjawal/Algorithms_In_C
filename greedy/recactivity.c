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


int A_S(act *arr,int i,int j,act *selected)
{
    if(i >= j)
    {
        return 0; 
    }
    else
    {
        if (arr[i].start >= selected->finish)
        {
            selected = &arr[i];
            return 1 + A_S(arr,i+1,j,selected);
        }
    }

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
    sort(arr,n);
    act *selected = &arr[1];
    int count = A_S(arr,1,n+1,selected);
    for (int i = 1; i <= n; i++)
    {
        printf("%d : %d  %d\n",i,arr[i].start,arr[i].finish);
    }
    printf("\nCount of Answer set is : %d",count);
    return 0;
}