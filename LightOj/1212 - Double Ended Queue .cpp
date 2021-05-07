#include<bits/stdc++.h>

using namespace std;

int mx;
int top1;
int top2;
int bot1;
int bot2;

void pushL(int *a,int n){
    top1++;
    if(top1>=top2){
        printf("The queue is full\n");
        top1--;
    }
    else{
        a[top1]=n;
        printf("Pushed in left: %d\n",n);
    }
}
void pushR(int *a,int n){
    top2--;
    if(top2<=top1){
        printf("The queue is full\n");
        top2++;
    }
    else{
        a[top2]=n;
        printf("Pushed in right: %d\n",n);
    }
}

void popL(int *a){
    int data;
    if(top1<bot2 && top2>bot1){
        printf("The queue is empty\n");
    }
    else if(top1<bot2){
       data=a[bot1];
       bot1--;
       printf("Popped from left: %d\n",data);
    }
    else{
        data=a[top1];
        top1--;
        printf("Popped from left: %d\n",data);
    }
}

void popR(int *a){
    int data;
    if(top1<bot2 && top2>bot1){
        printf("The queue is empty\n");
    }
    else if(top2>bot1){
        data=a[bot2];
        bot2++;
        printf("Popped from right: %d\n",data);
    }
    else{
        data=a[top2];
        top2++;
        printf("Popped from right: %d\n",data);
    }
}



int main(){
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int n;
        top1=-1;
        bot2=0;
        scanf("%d %d\n",&mx,&n);
        top2=mx;
        bot1=mx-1;
        int q[mx],j,data;
        char c[20];
        //printf("Case %d:\n",i);
        for(j=0;j<n;j++){
            memset(c,'\0',sizeof(c[0]));
            fgets(c,20,stdin);
            if(j==0)
                printf("Case %d:\n",i);
            if(c[4]=='L'){
                sscanf(c,"%*s %d",&data);
                pushL(q,data);
            }
            else if(c[4]=='R'){
                sscanf(c,"%*s %d",&data);
                pushR(q,data);
            }
            else if(c[3]=='L'){
                popL(q);
            }
            else if(c[3]=='R'){
                popR(q);
            }
        }
    }

}
