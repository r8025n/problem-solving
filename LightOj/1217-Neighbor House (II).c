#include<stdio.h>
#include<string.h>

int mem[1005][3];

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int dpSolve(int i,int *arr,int n,int zero){
//zero here keep tracks of if arr[0] was added or not, if added zero=1 else zero=0
    if(i>n-1){
        return 0;
    }

    if(zero==1 && i==n-2){
        return arr[n-2];
    }
    if(zero==1 && i==n-1){
        return 0;
    }

    if(zero==0 && i==n-1){
        return arr[n-1];
    }

    if(mem[i][zero]!=-1){
        return mem[i][zero];
    }
    if(i==0){
        zero=1;
    }
    int opt1=arr[i]+dpSolve(i+2,arr,n,zero);
    if(i==0){
        zero=0;
    }
    int opt2=dpSolve(i+1,arr,n,zero);

    int res=max(opt1,opt2);

    mem[i][zero]=res;
    return mem[i][zero];
}

int main(){
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        memset(mem,-1,sizeof(mem));
        int n;
        scanf("%d",&n);
        int arr[n+5];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        int result=dpSolve(0,arr,n,2); //used zero=2 so it doesntconflict with internal logics

        printf("Case %d: %d\n",k,result);
    }

    return 0;
}
