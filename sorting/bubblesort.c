#include<stdio.h>
#include<stdbool.h>
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main(){
      int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    bool flag;
    
    for(int i=0;i<n-1;i++){
        flag=false;
        for(int j=0;j<n-1;j++){
            flag=true;
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(!flag){
            break;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}