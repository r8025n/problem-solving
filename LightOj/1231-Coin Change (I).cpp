#include<iostream>
#include<string.h>

int coin[55],quantity[55],mem[55][1005];


int dpSolve(int i,int w,int n){
	if(w<0){
		return 0;
	}

    if(w==0)
        return 1;
	if(i==n && w!=0){
		return 0;
	}

	if(mem[i][w]!=-1)
        return mem[i][w];

	int res=0;

	for(int j=0;j<=quantity[i];j++){
        res+=dpSolve(i+1,w-(j*coin[i]),n);
        res=res%100000007;
	}


	mem[i][w]=res;

	return mem[i][w];
}

int main(){
	int t;
	scanf("%d",&t);

	for(int k=1;k<=t;k++){
		int n,w;
		scanf("%d %d",&n,&w);


		for(int i=0;i<n;i++){
			scanf("%d",&coin[i]);
		}

		for(int i=0;i<n;i++){
			scanf("%d",&quantity[i]);
		}

        memset(mem,-1,sizeof(mem));

		int res=dpSolve(0,w,n);

		printf("Case %d: %d\n",k,res);
	}

	return 0;
}
