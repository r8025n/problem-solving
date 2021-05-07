#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		long long n,m,res,mid;
		scanf("%lld %lld",&n,&m);
		mid=n/(2*m);
		res=mid*(m*m);
		printf("Case %d: %lld\n",i,res);
	}
}
