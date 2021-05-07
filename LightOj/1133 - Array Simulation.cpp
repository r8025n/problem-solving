#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,m,j,k,l,temp;
		char c;
		int x,y;
		scanf("%d %d",&n,&m);
		int a[n+5],b[n+5];

		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		for(j=0;j<m;j++){
			scanf(" %c",&c);
			if(c=='P'){
				scanf("%d %d",&x,&y);
				temp=a[x];
				a[x]=a[y];
				a[y]=temp;
			}
			else if(c=='S'){
				scanf("%d",&x);
				for(k=0;k<n;k++){
					a[k]=a[k]+x;
				}
			}
			else if(c=='M'){
				scanf("%d",&x);
				for(k=0;k<n;k++){
					a[k]=a[k]*x;
				}
			}
			else if(c=='D'){
				scanf("%d",&x);
				for(k=0;k<n;k++){
					a[k]=a[k]/x;
				}
			}
			else if(c=='R'){
				for(l=0,k=n-1;l<n,k>=0;l++,k--){
					b[l]=a[k];
				}
				for(l=0;l<n;l++){
					a[l]=b[l];
				}
			}
		}
		printf("Case %d:\n",i);
		for(j=0;j<n;j++){
			printf("%d",a[j]);
			if(j!=n-1)
				printf(" ");
		}
		printf("\n");
	}
}
