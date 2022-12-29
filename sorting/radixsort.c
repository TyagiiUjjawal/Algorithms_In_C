#include<stdio.h>
#define MAX 9

int cntArr[MAX+1]={0};
int sorted[MAX+1]={0};

void radixSort(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int place=1,i=0;
    while(max/place>0){
        if(place>=10){
            for(int i=0;i<n;i++){
            arr[i]=sorted[i];
        }
        }
        countSort(arr,n,place);
        place*=10;
    }
}

void countSort(int arr[],int n,int place){
    for(int i=0;i<n;i++){
        int index=arr[i]/place;
        cntArr[index % 10]++;
    }
    // printf("\n");//debug
    // for(int i=0;i<MAX+1;i++){
    //     printf("%d ",cntArr[i]);
    // }
    for(int i=1;i<MAX+1;i++){
        cntArr[i]+=cntArr[i-1];
    }
    // printf("\n");//debug
    // for(int i=0;i<MAX+1;i++){
    //     printf("%d ",cntArr[i]);
    // }
    for(int i=n-1;i>=0;i--){
        int index=arr[i]/place;
        sorted[cntArr[index % 10]-1]=arr[i];
        cntArr[index % 10]--;
    }
    // printf("\n");//debug
    // for(int i=0;i<n;i++){
    //     printf("%d ",sorted[i]);
    // }
    for(int i=0;i<MAX+1;i++){//reinitialising count_array to zeroes 
        cntArr[i]=0;
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("\nenter array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    radixSort(arr,n);
    printf("\nsorted array is: ");
    printArray(sorted,n);
    return 0;
}