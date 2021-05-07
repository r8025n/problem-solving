#include<stdio.h>

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		long long w,n,m;
		long double d;
		scanf("%lld",&w);
		if(w%2!=0){
			printf("Case %d: Impossible\n",i);
		}
		else{
			for(m=2;;m+=2){
				if(((w/m)%2!=0) && ((long double)w/(long double)m-w/m==0)){
					n=w/m;
					break;
				}
			}
			printf("Case %d: %lld %lld\n",i,n,m);
		}

	}
}