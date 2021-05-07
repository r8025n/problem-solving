#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int a[5],j,k,temp,left, right;
		for(j=0;j<3;j++){
			scanf("%d",&a[j]);
		}
		for(j=0;j<3;j++){
			for(k=j+1;k<3;k++){
				if(a[j]<a[k]){
					temp=a[j];
					a[j]=a[k];
					a[k]=temp;
				}
			}
		}
		left=a[0]*a[0];
		right=(a[1]*a[1])+(a[2]*a[2]);

		if(left==right)
			printf("Case %d: yes\n",i);
		else
			printf("Case %d: no\n",i);

	}
}
