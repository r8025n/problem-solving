#include<stdio.h>

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int x[8];
		int x0[6]={0,0,0,1001,1001,1001};
		int ck[6]={0,0,0,0,0,0};
		int n,k,j;
		long res;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d %d %d %d %d %d",&x[0],&x[1],&x[2],&x[3],&x[4],&x[5]);
			for(k=0;k<3;k++){
				if(x0[k]<x[k])
					x0[k]=x[k];
			}
			for(k=3;k<6;k++){
				if(x0[k]>x[k])
					x0[k]=x[k];
				if(ck[k]<x[k])
					ck[k]=x[k];
			}
		}

        res=(x0[3]-x0[0])*(x0[4]-x0[1])*(x0[5]-x0[2]);
		if(res<=0)
            res=0;
		printf("Case %d: %ld\n",i,res);

	}

}
