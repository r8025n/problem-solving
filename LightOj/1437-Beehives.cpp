#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent,dist;


void join(int src,int des){
	adj[src].push_back(des);
	adj[des].push_back(src);
}

int bfs(int sn){
	int cycle_length=20001,d,dd;
	queue<int> q;
	q.push(sn);
	visited[sn]=true;
	dist[sn]=0;
	parent[sn]=0;

	while(!q.empty()){
		int node=q.front();
		d=dist[node]+1;
		q.pop();
        for(auto k=adj[node].begin();k!=adj[node].end();k++){

			if(visited[*k]==false){
				visited[*k]=true;
				dist[*k]=d;
				q.push(*k);
				if(parent[*k]==-1)
                    parent[*k]=node;
			}
			else{
				if(*k!=parent[node]){
					dd=dist[*k]+dist[node]+1;
					cycle_length=min(cycle_length,dd);
				}
			}
		}
	}

	return cycle_length;
}



int main(){
	int k,t;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		int n,m,res=20001,r;
		scanf("%d %d",&n,&m);

		adj.assign(n+2,vector<int>());
		visited.assign(n+2,false);
		dist.assign(n+2,-1);
		parent.assign(n+2,-1);

		int src,des;
		for(int i=0;i<m;i++){
			scanf("%d %d",&src,&des);
			join(src,des);
		}
        for(int i=0;i<n;i++){
            r=bfs(i);
            res=min(res,r);
            visited.assign(n+2,false);
            dist.assign(n+2,-1);
            parent.assign(n+2,-1);
        }
		if(res==20001){
			printf("Case %d: impossible\n",k);
		}
		else{
			printf("Case %d: %d\n",k,res);
		}
	}

	return 0;
}

