#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,c;
int arr[205][105];
int val[205][105];

int mx(int x,int y){
	if(x>y)
		return x;
	else
		return y;
}

void dfs(int x,int y){
	if(x<0 || y<0 || x>2*n-2 || y>n-1 || arr[x][y]==-1){
		return;
	}
	else if(x<n-1){
		val[x][y]=mx(val[x][y],c+arr[x][y]);
		c=val[x][y];
		dfs(x+1,y);
		c=val[x][y];
		dfs(x+1,y+1);
	}
	else if(x>=n-1){
		val[x][y]=mx(val[x][y],c+arr[x][y]);
		c=val[x][y];
		dfs(x+1,y);
		c=val[x][y];
		dfs(x+1,y-1);
	}
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int k=0;k<n;k++){
			for(int j=0;j<=k;j++){
				scanf("%d",&arr[k][j]);
			}
			for(int j=k+1;j<n;j++){
				arr[k][j]=-1;
			}
		}
		int p;
		for(int k=n;k<2*n-1;k++){
			p=2*n-1-k;
			for(int j=0;j<p;j++){
				scanf("%d",&arr[k][j]);
			}
			for(int j=p;j<n;j++){
				arr[k][j]=-1;
			}
		}

		for(int k=0;k<2*n-1;k++){
            for(int j=0;j<n;j++){
                visit[k][j]=0;
                val[k][j]=0;
            }
		}
		c=0;
		int res;
		dfs(0,0);
		res=val[2*n-2][0];
		printf("Case %d: %d\n",i,res);
	}
}

/*
2
4
7
6 4
2 5 10
9 8 12 2
2 12 7
8 2
10
2
1
2 3
1
*/
