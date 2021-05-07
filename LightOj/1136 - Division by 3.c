#include<stdio.h>

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		long l,u;
		long mid,res;
		long double d;
		scanf("%ld %ld",&l,&u);
		if(l==u){
			if(l%3==0 || (l+1)%3==0)
				res=1;
			else
				res=0;
		}
		else if(u-l==1){
			if((u%3==0 || (u+1)%3==0) && (l%3==0 || (l+1)%3==0))
				res=2;
			else if((u%3==0 && (l%3!=0 ||(l+1)%3!=0))||((u%3!=0 || (u+1)%3!=0) && l%3==0))
				res=1;
			else
				res=0;
		}
		else{
			mid=u-l+1;
			res=(mid/3)*2;
			if(mid%3!=0){
                if((l+1)%3==0 && u%3==0){
                    res+=2;
                }
                else if(l%3==0 && u%3==0){
                    res++;
                }
                else if(u%3==0 || (u+1)%3==0 || l%3==0 || (l+1)%3==0){
                    res++;
                }

			}
        }

		printf("Case %d: %ld\n",i,res);
	}
}
