#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> nov;
int k,n,m,c;

void join(int src, int des){
	adj[src].push_back(des);
}

void bfs(int sn){
	visited.assign(n+3,0);

	queue<int> q;
	q.push(sn);
	visited[sn]=1;

	while(q.empty()==false){
		int node=q.front();
		q.pop();

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			if(visited[*i]!=1){
				visited[*i]=1;
				nov[*i]=nov[*i]+1;
				if(nov[*i]==k){
					c++;
				}
				q.push(*i);
			}
		}
	}
}


int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int j,o,src,des;
		c=0;
		scanf("%d %d %d",&k,&n,&m);
		int arr[k+3];
		adj.assign(n+3,vector<int>());
		nov.assign(n+3,0);
		for(j=0;j<k;j++){
			scanf("%d",&arr[j]);
			nov[arr[j]]++;
		}
		for(j=0;j<m;j++){
			scanf("%d %d",&src,&des);
			join(src,des);
		}
		for(j=0;j<k;j++){
			bfs(arr[j]);
		}
        if(k==1){
            c++;
        }
		printf("Case %d: %d\n",i,c);
	}
}
