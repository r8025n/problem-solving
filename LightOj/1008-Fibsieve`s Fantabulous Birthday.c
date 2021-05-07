#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		unsigned long long r,c,rr,cc;
		unsigned long long a,m;
		unsigned long long x;
		long double y,z;
		scanf("%llu",&x);
		if(x==1){
			r=1;
			c=1;
		}
		else{
		y=sqrt(x);
		z=ceil(y);
		a=(int)z;
		rr=a;
		m=(a*a-a+1);
		cc=a-abs(m-x);
			if(a%2==0){
				if(x>m){
					c=rr;
					r=cc;
				}
				else{
					c=cc;
					r=rr;
				}
			}
			else{
				if(x<m){
                    c=rr;
					r=cc;
				}

				else{
					c=cc;
					r=rr;
				}
			}
		}
		printf("Case %d: %llu %llu\n",i,c,r);
	}
}
