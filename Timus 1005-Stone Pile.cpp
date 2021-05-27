#include<stdio.h>
#include<stdlib.h>


int main(){
	int n;
	scanf("%d",&n);
	int w[n],total=0;
	int res=0x3f3f3f3f;
	int max_mask=1<<n;

	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
		total+=w[i];
	}

	for(int msk=0;msk<max_mask;msk++){
		int val=0;
		for(int i=0;i<n;i++){
			if(msk & (1<<i)){
				val+=w[i];
			}
		}
		val=abs(val-(total-val));
		if(val<res){
			res=val;
		}
	}

	printf("%d\n",res);
}