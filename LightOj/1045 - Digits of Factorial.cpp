#include<bits/stdc++.h>

long double d[1000005];

int main(){
    int j;
    d[1]=0;
    for(j=2;j<=1000000;j++){
        d[j]=log10(j)+d[j-1];
    }
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int n,b,r;
        scanf("%d %d",&n,&b);
        if(n==0){
            r=1;
        }
        else{
            r=(int)floor(d[n]/log10(b))+1;
        }
        printf("Case %d: %d\n",i,r);
    }
}




