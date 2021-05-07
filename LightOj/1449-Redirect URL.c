#include<stdio.h>

int main(){
    int n,t;
    scanf("%d",&t);
    for(n=1;n<=t;n++){
        char url[2500];
        int l=0,i;
        scanf("%s",url);
        while(url[l]!='\0')
            l++;
        if(url[4]!='s'){
            printf("Case %d: https",n);;
            for(i=4;i<l;i++)
                printf("%c",url[i]);
            printf("\n");
        }
        else{
            printf("Case %d: %s\n",n,url);
        }
    }

    return 0;
}