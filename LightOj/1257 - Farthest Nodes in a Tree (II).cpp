//i used vector instead of array dis1 & dis2, but they showed all output 0....why!!

#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> visited;
int n;

void join(int src, int des, int w){
	adj[src].push_back(make_pair(des,w));
	adj[des].push_back(make_pair(src,w));
}

int bfs(int sn,int *d){
	int c,mx=-1,mxn;
	visited.assign(n,0);
	memset(d,0,n*sizeof(d[0]));
	queue<int> q;
	q.push(sn);
	visited[sn]=1;
	d[sn]=0;

	while(q.empty()==false){
		int node=q.front();
		q.pop();
		c=d[node];

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			if(visited[i->first]!=1){
				visited[i->first]=1;
				d[i->first]=i->second+c;
				q.push(i->first);
				if(d[i->first]>mx){
					mx=d[i->first];
					mxn=i->first;
				}
			}
		}
	}
	return mxn;
}


int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int j,src,des,w,n1,n2,n3,res;
		scanf("%d",&n);
		adj.assign(n,vector<pair<int,int>>());
		int dis1[n+5];
		int dis2[n+5];

		for(j=0;j<n-1;j++){
			scanf("%d %d %d",&src,&des,&w);
			join(src,des,w);
		}
		n1=bfs(0,dis1);
		n2=bfs(n1,dis1);
		n3=bfs(n2,dis2);

		printf("Case %d:\n",i);
		for(j=0;j<n;j++){
            printf("%d\n",max(dis1[j],dis2[j]));
		}

	}
}

