#include<iostream>
#define inf 0x3f3f3f3f


int arr[25][3];
int mem[25][3];

int min_cost(int n,int m,int nn){
    if(n==nn-1){
        return arr[n][m];
    }
    if(mem[n][m]!=-1){
        return mem[n][m];
    }

    int cost=inf;
    for(int i=0;i<3;i++){
        if(i!=m){
            cost=std::min(cost,arr[n][m]+min_cost(n+1,i,nn));
        }
    }
    mem[n][m]=cost;
    return mem[n][m];
}

int main(){
    int t;
    scanf("%d",&t);

    for(int k=1;k<=t;k++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&arr[i][j]);
                mem[i][j]=-1;
            }
        }

        int res1=min_cost(0,0,n);
        int res2=min_cost(0,1,n);
        int res3=min_cost(0,2,n);

        int res=std::min(res1,res2);
        res=std::min(res,res3);

        printf("Case %d: %d\n",k,res);
    }
    return 0;
}
