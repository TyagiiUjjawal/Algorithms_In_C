#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool place(int x, int *arr, int k)
{
    for (int i = 1; i < k; i++)
    {
        if (arr[i] == x)
        {
            return false;
        }
        int y = k - i;
        int z = arr[i] - y;
        int r = arr[i] + y;
        if (z == x || r == x)
        {
            return false;
        }
    }
    return true;
}

void n_queen(int *arr, int n, int k,int *check)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(i, arr, k))
        {
            if (k == n)
            {
                arr[k] = i;
                *check = 1;
                return ;
            }
            else
            {
                arr[k] = i;
                n_queen(arr, n, k + 1,check);
                if (*check == 1)
                {
                    break;
                }
                
            }
        }
    }
}

int main()
{
    int n;
    printf("\nEnter the number of queens : ");
    scanf("%d", &n);
    int arr[n + 1];
    int check =  0;
    n_queen(arr, n, 1,&check);
    printf("\nThe result array is : \n");
    for (int i = 1; i < n + 1; i++)
    {
        printf("\nFor queen no. %d position is : %d", i, arr[i]);
    }
    return 0;
}