#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<bool> possible; 
int count;

void join(int src, int des){
	adj[src].push_back(des);
	adj[des].push_back(src);
} 

/*void dfs(int sn){
	visited[sn]=1;

	for(auto i=adj[sn].begin();i!=adj[sn].end();i++){
		if(possible[node]==false && possible[*i]==false){
			possible[*i]=true;
			count++;
		}
		if(visited[*i]!=1){
			dfs(*i);
		}
	}
}*/

void bfs(int sn){
	queue<int> q;
	visited[sn]=1;
	q.push(sn);
	possible[sn]=true;

	while(q.empty()==false){
		int node=q.front();
		q.pop();

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			if(possible[node]==false && possible[*i]==false){
				possible[*i]=true;
				count++;
			}

			if(visited[*i]!=1){
				visited[*i]=1;
				q.push(*i);
			}
		}
	}
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int count=1;
		int n,m;
		scanf("%d %d",&n,&m);
		
		adj.assign(n+3,vector<int>());
		visited.assign(n+3,0);
		possible.assign(n+3,false);


		int src,des;
		for(int k=0;k<m;k++){
			scanf("%d %d",src,des);
			join(src,des);
		}

		//possible[1]=true;
		dfs(1);

		printf("Case %d: %d\n",i,count);
	}
}