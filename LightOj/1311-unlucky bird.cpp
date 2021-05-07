#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		double v1,v2,v3,a1,a2;
		double t,s1,s2,d,t_d;
		scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);

		t=v1/a1;

		t_d=t*v3;

		s1=(v1*v1)/(2*a1);
		s2=(v2*v2)/(2*a2);

		d=s1+s2;

		printf("Case %d: %lf %lf\n",i,d,t_d);
	}
}
