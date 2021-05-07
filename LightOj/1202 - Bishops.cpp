#include<stdio.h>

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int r1,c1,r2,c2,mov;
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

		if(((r1+c1)%2==0 && (r2+c2)%2!=0) || ((r1+c1)%2!=0 && (r2+c2)%2==0)){
			printf("Case %d: impossible\n",i);
		}

		else{
			if((r1-c1)==(r2-c2) || (r1+c1)==(r2+c2)){
				mov=1;
			}
			else 
				mov=2;

			printf("Case %d: %d\n",i,mov);
		}
	}
}