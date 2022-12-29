#include<stdio.h>

#define MAX 9//MAX is the largest elem in the array--range
#define size 6

int cntArr[MAX+1]={0};
int sorted[size]={0};

void countSort(int input[]){
    for(int i=0;i<size;i++){
        cntArr[input[i]]++;
    }
    for(int i=0;i<=MAX;i++){
        cntArr[i]+=cntArr[i-1];
    }
    for(int i=size-1;i>=0;i--){
        sorted[cntArr[input[i]]-1]=input[i];
        cntArr[input[i]]--;
    }
}

void printArray(int arr[]){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[size];
    printf("enter 6 elements: \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    countSort(arr);
    printf("\nsorted array is: ");
    printArray(sorted);
    return 0;
}