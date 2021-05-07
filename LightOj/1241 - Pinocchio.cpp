#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,j,d,lie=0;
		scanf("%d",&n);
		int arr[n+5];
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}

		for(j=0;j<n-1;j++){
			if(arr[j+1]-arr[j]==0){
				continue;
			}
			else if(arr[j+1]-arr[j]<=5){
				lie++;
			}
			else{
				d=(arr[j+1]-arr[j])/5;
				if((arr[j+1]-arr[j])%5==0)
					lie+=d;
				else
					lie+=(d+1);
			}
		}
		printf("Case %d: %d\n",i,lie);
	}
}