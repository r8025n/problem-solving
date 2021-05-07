#include<stdio.h>


int query(int index,int *arr){
	int sum=0;
	while(index!=0){
		sum+=arr[index];
		index-=index & (-index);
	}

	return sum;
}

void update(int x,int index,int *bit,int n){
	while(index<=n){
		bit[index]+=x;
		index+=index & (-index);
	}
}


int main(){
	int t,k;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		int n,q,i,x;
		scanf("%d %d",&n,&q);
		int BIT[n+5],sack[n+5];

		for(i=1;i<=n;i++){
            scanf("%d",&sack[i]);
			BIT[i]=0;
		}

		for(i=1;i<=n;i++){
			update(sack[i],i,BIT,n);
		}


		int p,a,b,y;
		printf("Case %d:\n",k);

		while(q--){
			scanf("%d",&p);
			if(p==1){
				scanf("%d",&a);
				printf("%d\n",sack[a+1]);
				y=sack[a+1]*(-1);
				sack[a+1]=0;
				update(y,a+1,BIT,n);
			}

			else if(p==2){
				scanf("%d %d",&a,&b);
				sack[a+1]+=b;
				update(b,a+1,BIT,n);
			}

			else if(p==3){
				scanf("%d %d",&a,&b);
				int res= query(b+1,BIT)-query(a,BIT);
				printf("%d\n",res);
			}
		}
	}
	return 0;
}
