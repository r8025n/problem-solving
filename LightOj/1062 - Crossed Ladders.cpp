#include<stdio.h>
#include<math.h>

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		double x,y,c,cc;
		scanf("%lf %lf %lf",&x,&y,&c);
		double lo=0,hi,mid;
		if(x<y){
			hi=x;
		}
		else{
			hi=y;
		}

        int k=100;
		double px,qy;
		while(hi-lo>.000001){
			mid=(hi+lo)/2;
			px=sqrt(pow(x,2)-pow(mid,2));
			qy=sqrt(pow(y,2)-pow(mid,2));

			cc=1/(1/px+1/qy);
			if(cc>c){
				lo=mid;
			}
			else{
				hi=mid;
			}
		}
		printf("Case %d: %.10lf\n",i,mid);
	}
	return 0;
}


/*
4
30 40 10
12.619429 8.163332 3
10 10 3
10 10 1
*/
