#include<stdio.h>
#include<math.h>

double triangleArea(double a, double b, double c){
	double s=(a+b+c)/2;
	double ar=s*(s-a)*(s-b)*(s-c);
	double area=sqrt(ar);

	return area;
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		double ab,ac,bc,rat,rrr;
		scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&rat);
		double ad,ae,de;
		double hi=ab,lo=0;
		double sideRatio;
		double smallT,bigT,trape;
		bigT=triangleArea(ab,bc,ac);
		while(hi-lo>0.000001){
			ad=(hi+lo)/2;
			sideRatio=ad/ab;
			//so
			ae=ac*sideRatio;
			de=bc*sideRatio;
			smallT=triangleArea(ad,ae,de);
			trape=bigT-smallT;

			rrr=smallT/trape;

			if(rrr<rat){
				lo=ad;
			}
			else{
				hi=ad;
			}
		}
		printf("Case %d: %.10lf\n",i,ad);
	}

	return 0;
}

/*
4
100 100 100 2
10 12 14 1
7 8 9 10
8.134 9.098 7.123 5.10
*/
