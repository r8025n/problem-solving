#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

#define inf 0x3f3f3f3f

vector<vector<pair<int,int>>> adj;
vector<vector<int>> adj2;
vector<int> parent, key,dist;
vector<bool> selected,visited;

void join1(int src,int des, int w){
	adj[src].push_back(make_pair(des,w));
	adj[des].push_back(make_pair(src,w));
}

void join2(int src,int des){
    adj2[src].push_back(des);
    adj2[des].push_back(src);
}

void primMst(int sn){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	key[sn]=0;

	pq.push(make_pair(key[sn],sn));

	int v,weight;

	while(pq.empty()==false){
		int node=pq.top().second;
		pq.pop();

		selected[node]=true;

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			v=i->first;
			weight=i->second;

			if(selected[v]!=true && key[v]>weight){
				key[v]=weight;
				pq.push(make_pair(key[v],v));
				parent[v]=node;
			}
		}
	}
}

void dfs(int node){
    visited[node]=true;

    for(auto i=adj2[node].begin();i!=adj2[node].end();i++){
        if(visited[*i]!=true){
            if(key[*i]>dist[node]){
                dist[*i]=key[*i];
            }
            else{
                dist[*i]=dist[node];
            }
            dfs(*i);

        }
    }
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,m,myCity;
		int src,des,w;
		scanf("%d %d",&n,&m);

		adj.assign(n+5,vector<pair<int,int>>());
		selected.assign(n+5,false);
		key.assign(n+5,inf);
		parent.assign(n+5,-1);
		adj2.assign(n+5,vector<int>());
		dist.assign(n+5,-1);
		visited.assign(n+5,false);

		for(int k=0;k<m;k++){
			scanf("%d %d %d",&src,&des,&w);
			join1(src,des,w);
		}
		scanf("%d",&myCity);

		primMst(myCity);

		for(int k=0;k<n;k++){
            if(parent[k]!=-1)
                join2(parent[k],k);
		}

		dist[myCity]=0;
		dfs(myCity);

		printf("Case %d:\n",i);
		for(int k=0;k<n;k++){
			if(dist[k]!=-1){
				printf("%d\n",dist[k]);
			}
			else{
				printf("Impossible\n");
			}
		}

	}

	return 0;
}