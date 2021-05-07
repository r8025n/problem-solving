//first program with weighted graph using stl

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int n,f;

vector<vector<pair<int,int>>> adj;
vector<int> visited;
vector<int> dist;

void join(int src, int des, int w){
	adj[src].push_back(make_pair(des,w));
	adj[des].push_back(make_pair(src,w));
}

void bfs(int sn){
	int c;
	visited.assign(n,0);
	dist.assign(n,0);

	queue<int> q;
	q.push(sn);
	visited[sn]=1;
	//dist[sn]=0;

	while(q.empty()==false){
		int node=q.front();
		q.pop();
		c=dist[node];

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			if(visited[i->first]!=1){
				visited[i->first]=1;
				dist[i->first]=i->second+c;
				q.push(i->first);
			}
		}

	}
}

int look(){
	int i,mx=-1;
	for(i=0;i<n;i++){
		if(dist[i]>mx){
			mx=dist[i];
			f=i;
		}
	}

	return mx;
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int j,src,des,w,res;
		scanf("%d",&n);
		adj.assign(n,vector<pair<int,int>>());

		for(j=0;j<n-1;j++){
			scanf("%d %d %d",&src,&des,&w);
			join(src,des,w);
		}
		bfs(0);
		res=look();
		bfs(f);
		res=look();

		printf("Case %d: %d\n",i,res);
	}
	return 0;
}
