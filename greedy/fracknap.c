#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct item
{
    int wt;
    float profit;
} item;

void insertion_sort(item *it, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        item m = it[i];
        float key = it[i].profit / it[i].wt;
        while (j >= 0 && (it[j].profit / it[j].wt) < key)
        {
            it[j + 1] = it[j];
            j--;
        } 
        it[j + 1] = m;
    }
}

void fractional_knapsack(item *it, int n, int totalwt)
{
    int sum=0;
    insertion_sort(it, n);
    int wtcount[n];
    int count = 0;
    int i = 0;
    while (count + it[i].wt < totalwt)
    {
        printf("\nWeight = %d and profit = %f", it[i].wt, it[i].profit);
        sum+=it[i].profit;
        count += it[i].wt;
        i++;
    }
    if (it[i].wt == totalwt - count)
    {
        printf("\nWeight = %d and profit = %f", it[i].wt, it[i].profit);
        sum+=it[i].profit;
    }
    else
    {
        printf("\nWeight = %d and profit = %f", totalwt - count, (it[i].profit/it[i].wt)*(totalwt-count));
        sum+=(it[i].profit/it[i].wt)*(totalwt-count);
        printf(" \n the profit is %d",sum);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of items : ");
    scanf("%d", &n);
    item it[n];
    printf("\nEnter the data for each item : \n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the weight and profit for item %d : ", i + 1);
        scanf("%d%f", &it[i].wt, &it[i].profit);
    }
    int totalwt;
    printf("\nEnter hte total weight of the bag : ");
    scanf("%d", &totalwt);
    fractional_knapsack(it, n, totalwt);
    return 0;
}