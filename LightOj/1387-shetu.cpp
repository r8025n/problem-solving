#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,i;
	scanf("%d\n",&t);
	for(i=1;i<=t;i++){
		int j,k,l,n,total=0,temp;
		int rep[105],r=0;
		char op[25],num[20];
		scanf("%d\n",&n);
		for(j=1;j<=n;j++){
			memset(op,'\0',sizeof(op[0]));
			memset(num,'\0',sizeof(num[0]));
			fgets(op,25,stdin);
			if(op[0]=='d'){
				for(k=7,l=0;op[k]!='\0';k++,l++){
					num[l]=op[k];
				}
				num[l]='\0';
				sscanf(num,"%d",&temp);
				total+=temp;
			}
			else{
				rep[r]=total;
				r++;
			}
		}
		printf("Case %d:\n",i);
		for(j=0;j<r;j++){
			printf("%d\n",rep[j]);
		}
	}
}