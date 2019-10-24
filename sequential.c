//sequential search
#include<stdio.h>

int main(){
    int a[200],i,c,flag=0,n;
    scanf("%d",&n);
    scanf("%d",&c);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==c)
        {
            printf("found");
            flag=1;
            break;
        }
    }
    if(flag==0)
    printf("not found");
    return 0;
}
