//insertion sort
#include<stdio.h>

int main(){
    int k,i,j,n,a[20];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        k=a[i];
        j=i-1;
        while(j>=0&&a[j]>k){
            a[j+1]=a[j];
            j-=1;
        }
        a[j+1]=k;
    }
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);  
    return 0;
}