#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct job
{
  int dl;
  int profit;	
};
void swap(struct job *a,struct job *b)
{
    struct job temp=*a;
    *a=*b;
    *b=temp;
}
int parti(struct job arr[],int l,int h)
{
    int i=l-1,j=h+1;
    float piv=arr[l].profit;
    while(1)
    {
        do
        {
            i++;
        }while((arr[i].profit)>piv);
        do
        {
            j--;
        }while((arr[j].profit)<piv);
        if(i>=j) return j;
        swap(&arr[i],&arr[j]);
    }
}
void sort(struct job arr[],int l,int h)
{
   if(l<h)
   {
       int p=parti(arr,l,h);
       sort(arr,l,p);
       sort(arr,p+1,h);
   }
}
void JobSeqeuncing(struct job arr[],int n)
{
	sort(arr,0,n-1);
	
	int maxd=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i].dl>maxd)
		maxd=arr[i].dl;
	}
	//printf("%d ",maxd);
	int temp[maxd+1];
	for(int i=0;i<=maxd;i++)
	{
		temp[i]=0;
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(temp[arr[i].dl]==0)
		{
			cnt+=arr[i].profit;
			temp[arr[i].dl]=1;
			
		}
		else
		{
			int j=arr[i].dl-1;
			while(j>0&&temp[j]!=0)
			{
				j--;
			}
			if(j!=0)
			{
				cnt+=arr[i].profit;
			    temp[j]=1;
			}
			
		}
	}
	printf("%d ",cnt);
}
int main()
{
    printf("Enter no. of jobs::");
    int n;
    scanf("%d",&n);
    struct job arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter deadline and end profit for %d activity::",i+1);

        scanf("%d%d",&arr[i].dl,&arr[i].profit);
    }
    JobSeqeuncing(arr,n);
}