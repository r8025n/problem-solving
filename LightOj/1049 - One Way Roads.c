#include<stdio.h>

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,j,tw=0,c=0,p,tmp,x,r1=0,r2,res;
		scanf("%d",&n);
		int a[n+2],b[n+2],w[n+2];
		for(j=0;j<n;j++){
			scanf("%d %d %d",&a[j],&b[j],&w[j]);
			tw+=w[j];
		}
		p=a[0];
		x=b[0];
		while(x!=p){
			for(j=0;j<n;j++){
				if(c==j){
					continue;
				}
				if(a[j]==x){
					x=b[j];
					c=j;
					break;
				}
				else if(b[j]==x){
					x=a[j];
					tmp=a[j];
					a[j]=b[j];
					b[j]=tmp;

					r1+=w[j];
					c=j;
					break;
				}
			}
		}
		r2=tw-r1;
		if(r1>r2){
			res=r2;
		}
		else{
			res=r1;
		}

		printf("Case %d: %d\n",i,res);
	}

	return 0;
}