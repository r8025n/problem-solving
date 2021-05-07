#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > adj;
vector<int> visited;
vector<int> distS;
vector<int> distD;

void join(int src,int des ){
	adj[src].push_back(des);
	adj[des].push_back(src);
}

void bfs(int sn, vector<int> &dist){
	int c,r;
	queue<int> q;
	q.push(sn);
	visited[sn]=1;
	dist[sn]=0;

	while(q.empty()==false){
		int node=q.front();
		q.pop();
		c=dist[node]+1;

		for(auto i=adj[node].begin();i<adj[node].end();i++){
			if(visited[*i]!=1){
				visited[*i]=1;
				dist[*i]=c;
				q.push(*i);
			}
		}
	}
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,r,u,v,s,d,res=0;
		int j;
		scanf("%d",&n);
		scanf("%d",&r);

		adj.assign(n,vector<int>());
		visited.assign(n,0);
		distS.assign(n,0);
		distD.assign(n,0);

		for(j=0;j<r;j++){
			scanf("%d %d",&u,&v);
			join(u,v);
		}

		scanf("%d %d",&s,&d);

		bfs(s,distS);
		visited.assign(n,0);
		bfs(d,distD);
		for(j=0;j<n;j++){
            if(distS[j]+distD[j]>res){
                res=distS[j]+distD[j];
            }
		}

		printf("Case %d: %d\n",i,res);
	}
	return 0;
}