#include<stdio.h>
#include<math.h>

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int m,n,d,r;
		double mid;
		scanf("%d %d",&m,&n);

		d=m*n;
		mid=ceil((double)d/2);
		r=(int)mid;

		if(m==1)
			r=n;
		if(n==1)
			r=m;
		if((m==2 && n%2==0) || (n==2 && m%2==0)){
			if((d/4)%2!=0){
				r=(d/2)+2;
			}
			else{
				r=(d/2);
			}
		}
		
		if(m==2 && n%2!=0){
			r=n+1;
		}
		if(n==2 && m%2!=0){
			r=m+1;
		}

		printf("Case %d: %d\n",i,r);

	}
}