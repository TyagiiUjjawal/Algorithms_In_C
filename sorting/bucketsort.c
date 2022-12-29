#include<stdio.h>

float sorted[10];

void insertionSort(float bkt[][5],int bktNo,int bktSz){
    int i,j;
    float key;
    for(i=1;i<bktSz;i++){
        key=bkt[bktNo][i];
        j=i-1;
        while(j>=0 && bkt[bktNo][j]>key){
            bkt[bktNo][j+1]=bkt[bktNo][j];
            j--;
        }
        bkt[bktNo][j+1]=key;
    }
}

void bucketSort(float arr[],int n){
    int numOfBks = 10;
    float bkt[10][5];
    int cntBkt[10]={0};

    //insert elements into their respective buckets
    for(int i=0;i<n;i++){
        int index = (int)(arr[i]*10);
        bkt[index][cntBkt[index]++]=arr[i];//cntBkt[index] has --how many elems in each bucket..
    }

    //sort each bucket
    for(int i=0;i<numOfBks;i++){
        insertionSort(bkt,i,cntBkt[i]);
    }

    //concatenate all bkts
    int k=0;
    for(int i=0;i<numOfBks;i++){
        for(int j=0;j<cntBkt[i];j++){
            sorted[k]=bkt[i][j];
            k++;
        }
    }
}

void printArray(float arr[],int n){
    for(int i=0;i<n;i++){
        printf("%f ",arr[i]);
    }
}

int main(){
    int n;
    printf("enter array size: ");
    scanf("%d",&n);
    float arr[n];
    printf("enter array elements..fractional values: \n");
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }
    bucketSort(arr,n);
    printArray(sorted,n);
    return 0;
}
