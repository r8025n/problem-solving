#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int visited[13][13];
int dist[13][13];
char forest[13][13];
int n,xx,yy,pp,qq;

int bfs(int i,int j){
    //printf("BFS called\n");
	for(int l=0;l<n;l++){
		for(int m=0;m<n;m++){
			dist[l][m]=0;
			visited[l][m]=0;
		}
	}

	int x,y,c;

	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	visited[i][j]=1;

	while(q.empty()==false){
		x=q.front().first;
		y=q.front().second;
		q.pop();
		c=dist[x][y];
		forest[x][y]='.';

		for(int k=0;k<4;k++){
			i=x+dx[k];
			j=y+dy[k];
			if(!(i<0 || j<0 || i>=n || j>=n) && visited[i][j]==0 && (forest[i][j]=='.' || forest[i][j]==pp+1)){
				visited[i][j]=1;
				dist[i][j]=c+1;
				q.push(make_pair(i,j));
				if(forest[i][j]==pp+1){
                    forest[i][j]='.';
					xx=i;
					yy=j;
					pp=pp+1;
					return c+1;
				}
			}
		}
	}
	return -1;
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int j,k,a=0,res=0,r;
		pp=65;
		scanf("%d",&n);
		if(n==1){
            res=0;
            r=0;
		}
		for(j=0;j<n;j++){
            scanf("%s",forest[j]);
		}
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(forest[j][k]<=90 && forest[j][k]>=65){
					if(forest[j][k]==65){
						xx=j;
						yy=k;
					}
					a++;
				}
			}
		}
		qq=64+a;

		while(pp!=qq){
			r=bfs(xx,yy);
			if(r==-1){
				break;
			}
			res+=r;
		}

		if(r==-1){
			printf("Case %d: Impossible\n",i);
		}
		else{
			printf("Case %d: %d\n",i,res);
		}
	}
}
