//segment tree(lazy)

#include<stdio.h>
#include<string.h>

#define mx 100005

int segT[mx*3],r;

void init(int n){
	int i;
	for(i=1;i<=n;i++)
		segT[i]=0;
}

void update(int node,int b,int e,int i,int j){
	if(b>j || e<i)
		return;
	if(b>=i && e<=j){
		segT[node]+=1;
		return;
	}

	int left=node*2;
	int right=node*2+1;
	int mid=(b+e)/2;

	update(left,b,mid,i,j);
	update(right,mid+1,e,i,j);
}

void query(int node,int b,int e,int x,int carry){
	if(x<b || x>e)
        return;
	if(x>=b && x<=e){
		carry+=segT[node];
	}
	if(b==e && b==x){
		r=carry;
		return;
	}

	int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    query(left,b,mid,x,carry+segT[node]);
    query(right,mid+1,e,x,carry+segT[node]);
}



int main(){
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		int q,n;
        char str[mx];
		scanf("%s",str);
		scanf("%d",&q);
        n=strlen(str);


		init(n*3);

		int x,y;
        char c;
		printf("Case %d:\n",k);
		while(q--){
            getchar();
			scanf("%c",&c);
			if(c=='I'){
				scanf("%d %d",&x,&y);
				update(1,1,n,x,y);
			}
			else if(c=='Q'){
				scanf("%d",&x);
				query(1,1,n,x,0);
				if(r%2==0){
					if(str[x-1]=='1')
						printf("1\n");
					else
						printf("0\n");
				}
				else{
					if(str[x-1]=='1')
						printf("0\n");
					else
						printf("1\n");
				}
			}
		}
	}

	return 0;
}
