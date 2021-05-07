#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,p,q;
		int j,res=0,c=0;
		scanf("%d %d %d",&n,&p,&q);
		int w[n+5];
		for(j=0;j<n;j++){
			scanf("%d",&w[j]);
		}

		sort(w,w+n);
		if(n>p)
			n=p;
		for(j=0;j<n;j++){
			res=res+w[j];
			c++;
			if(res>p){
				res=res-w[j];
				c--;
				break;
			}
		}
		printf("Case %d: %d\n",i,c);
	}
}
