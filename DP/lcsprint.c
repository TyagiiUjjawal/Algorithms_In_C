#include<stdio.h>
#include<string.h>
char s1[20];
char s2[20];
int lcs[20][20];
int seq[20][20];
int max(int a, int b){
if(a>=b) return a;
return b;
}
void print_seq(int seq[20][20], int l1, int l2){
   if(l1==0 || l2==0) return;
    if(seq[l1][l2]==10){

   print_seq(seq,l1-1,l2-1);

   printf("%c",s1[l1-1]);

}

else if(seq[l1][l2]==11){

print_seq(seq,l1-1,l2);
}

else{
print_seq(seq,l1,l2-1);
}
}
int lcs_ans(int l1,int l2){
int i,j,k;
for(i=0;i<l1;i++){
lcs[i][0]=0;
}
for(i=0;i<l2;i++){
lcs[0][i]=0;
}
for(i=1;i<=l1;i++){
for(j=1;j<=l2;j++){
if(s1[i-1]==s2[j-1]){
lcs[i][j]=1+lcs[i-1][j-1];
seq[i][j]=10;
}
else{
if(lcs[i-1][j]>=lcs[i][j-1]){
lcs[i][j]=lcs[i-1][j];
seq[i][j]=11;
}
else{
lcs[i][j]=lcs[i][j-1];
seq[i][j]=12;
}
}
}
}
printf("number of common char %d \n",lcs[l1][l2]);
print_seq(seq,l1,l2);
return 0;
}

int main(){
printf("enter both strings \n");
scanf("%s",s1);
scanf("%s",s2);
int l1=strlen(s1);
int l2=strlen(s2);
printf("%d and %d \n",l1,l2);
lcs_ans(l1,l2);
}