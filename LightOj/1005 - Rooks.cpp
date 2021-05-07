#include<stdio.h>

unsigned long long fact(int x){
	if(x==1 || x==0){
		return 1;
	}
	unsigned long long r=x*fact(x-1);
	return r;
}


unsigned long long ncr(int n, int k){
    int r=n-k;
    int p=n;
    unsigned long long m=1;
    if(r>k){
        for(int i=0;i<n-r;i++){
            m=m*p;
            p--;
        }
        m=m/fact(k);
    }
    else{
        for(int i=0;i<n-k;i++){
            m=m*p;
            p--;
        }
        m=m/fact(r);
    }
    return m;
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,k;
		unsigned long long res,mult=1;
		scanf("%d %d",&n,&k);

		if(k>n){
			res=0;
		}
		else if(k==1){
			res=n*n;
		}
		else if(k==0){
            res=1;
		}
		else{
			for(int j=0,p=n;j<k;j++,p--){
				mult=mult*p;
			}
			res=mult*ncr(n,k);
		}
		printf("Case %d: %llu\n",i,res);
	}
	return 0;
}
