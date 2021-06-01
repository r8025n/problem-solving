//This problem can be solved in recursive dp way but won't meet the time constraint
//so it had to be solved iterative dp
//because as recursive depth become greater,
//clearing recursion function memory takes extra time which iterative does not take

#include<stdio.h>
#include<string.h>

#define M 100000007

int coin[105];
int mem[105][10005];


int checkTable(int i,int w){
    if(mem[i][w]!=-1){
        return mem[i][w];
    }

    if(coin[i]>w){
        return mem[i-1][w] % M;
    }
    else{
        return (mem[i-1][w]+mem[i][w-coin[i]]) % M;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        int n,w;
        scanf("%d %d",&n,&w);
        for(int i=1;i<=n;i++){
            scanf("%d",&coin[i]);
        }

        memset(mem,-1,sizeof(mem));

        mem[0][0]=1;

        for(int i=1;i<=w;i++){
            mem[0][i]=0;
        }

        //iterative DP solve
        //this loops will update the mem[][] table
        //and mem[n][w] will be the final result
        for(int i=1;i<=n;i++){
            for(int j=0;j<=w;j++){
                mem[i][j]=checkTable(i,j);
            }
        }

        printf("Case %d: %d\n",k,mem[n][w]);
    }

    return 0;
}
