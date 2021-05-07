#include<stdio.h>

long long factC(int n){
	long long x;
	if(n>=1){
		x=n*factC(n-1);
		return x;
	}
	else
		return 1;
}


int main(){

	long long a[25];
	a[0]=1;
    a[1]=1;
    a[2]=2;
    a[3]=6;
    a[4]=24;
    a[5]=120;
    a[6]=720;
    a[7]=5040;
    a[8]=40320;
    a[9]=362880;
    a[10]=3628800;
    a[11]=39916800;
    a[12]=479001600;
    a[13]=6227020800;
    a[14]=87178291200;
    a[15]=1307674368000;
    a[16]=20922789888000;
    a[17]=355687428096000;
    a[18]=6402373705728000;
    a[19]=121645100408832000;
    //a[20]=2432902008176640000;
	int i,t,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int j,b[19],c=0, flag=0;
		long long x;
		scanf("%lld",&x);
		for(j=19;j>=0;j--){
			if(a[j]<=x){
				b[c]=j;
				if(a[j]==x){
					flag=1;
					break;
				}
				c++;
				x=x-a[j];
			}
		}

		if(flag==0){
			printf("Case %d: impossible\n",i);
		}
		else{
			for(j=c;j>=0;j--){
				if(j==c){
                    printf("Case %d: ",i);
				}
				printf("%d!",b[j]);
				if(j!=0)
					printf("+");
			}
			printf("\n");
		}
	}
}
