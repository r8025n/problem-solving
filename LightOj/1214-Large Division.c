#include<stdio.h>

int main(){
    int t,p;
    scanf("%d",&t);
    for(p=1;p<=t;p++){
        char a[205];
        long long d=0;
        int l=0,b,k,i;

        scanf("%s %d",a,&b);

        while(a[l]!='\0'){
            l++;
        }

        if(a[0]=='-'){
            k=1;
        }
        else
            k=0;

        for(i=k;i<l;i++){
            d=(a[i]-'0')+d*10;
            d=d%b;
        }

        if(d==0){
            printf("Case %d: divisible\n",p);
        }
        else
            printf("Case %d: not divisible\n",p);
    }

    return 0;

}
