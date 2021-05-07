#include<bits/stdc++.h>

long long arr[10005];

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		long long a,b,c,d,e,f,n;
		int j;
		long long res;
		scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&n);
		arr[0]=a % 10000007;
		arr[1]=b % 10000007;
		arr[2]=c % 10000007;
		arr[3]=d % 10000007;
		arr[4]=e % 10000007;
		arr[5]=f % 10000007;
		if(n<=5){
			res=arr[n];
		}
		else{
			for(j=6;j<=n;j++){
				arr[j]=(arr[j-1] % 10000007+arr[j-2] % 10000007+arr[j-3] % 10000007+arr[j-4] % 10000007+arr[j-5] % 10000007+arr[j-6] % 10000007) % 10000007;
			}
			res=arr[n];
		}

		printf("Case %d: %lld\n",i,res);
	}

	return 0;
}
