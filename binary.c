//binary search
#include<stdio.h>

void bubble(int a[20], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j+1]<a[j]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
    int mid,i,k,n,beg=0,last,a[20];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    bubble(a,n);
    last=n-1;
    while(beg<last){
        mid=(beg+last)/2;
        if(a[mid]==k){
            printf("Element found at %d",mid+1);
            break;
        }
        if(a[mid]>k)
            last=mid-1;
        
        else
            beg=mid+1;
    }

    return 0;
}