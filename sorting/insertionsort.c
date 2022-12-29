#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    int j;
    int key;
    for(int i=1;i<n;i++){
        j=i-1;
        key=arr[i];
        while(j>0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}