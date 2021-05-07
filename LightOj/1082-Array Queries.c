#include<stdio.h>
#include<limits.h>
#define min(x,y) ((x)<(y)?(x):(y))

void init(int node,int b,int e,int *arr,int *tree){
	if(b==e){
		tree[node]=arr[b];
		return;
	}
	int left=node*2;
	int right=node*2+1;
	int mid=(b+e)/2;

	init(left,b,mid,arr,tree);
	init(right,mid+1,e,arr,tree);

	tree[node]=min(tree[left],tree[right]);
}

int mn;

void query(int i,int j,int node,int b,int e,int *tree){
	if(b>j || e<i){
		return;
	}
	if(b>=i && e<=j){
		mn=min(mn,tree[node]);
		return;
	}

	int left=2*node;
	int right=2*node+1;

	int mid=(b+e)/2;

	query(i,j,left,b,mid,tree);
	query(i,j,right,mid+1,e,tree);
}

int main(){
	int k,t;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		int n,q,i;
		scanf("%d %d",&n,&q);
		int arr[n+5],segT[n*3+5];
		for(i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}

		init(1,1,n,arr,segT);

		printf("Case %d:\n",k);
		int a,b;
		while(q--){
			mn=INT_MAX;
			scanf("%d %d",&a,&b);
			query(a,b,1,1,n,segT);
			printf("%d\n",mn);
		}
	}

	return 0;
}
