#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> selected;
vector<int> key,parent;

#define inf 0x3f3f3f3f


void join(int src, int des,int w){
	adj[src].push_back(make_pair(des,w));
	adj[des].push_back(make_pair(src,w));
}

void primMinSt(int sn){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	key[sn]=0;
	pq.push(make_pair(key[sn],sn));

	int v,w;
	while(pq.empty()==false){
		int node=pq.top().second;
		pq.pop();
		selected[node]=true;

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			v=i->first;
			w=i->second;

            if(selected[v]==false && key[v]>w){
                key[v]=w;
                pq.push(make_pair(key[v],v));
                //parent[v]=node;
            }
		}
	}
}

void primMaxSt(int sn){
    priority_queue<pair<int,int>> pq;
	key[sn]=0;
	pq.push(make_pair(key[sn],sn));

	int v,w;
	while(pq.empty()==false){
		int node=pq.top().second;
		pq.pop();
		selected[node]=true;

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			v=i->first;
			w=i->second;

            if(selected[v]==false && key[v]<w){
                key[v]=w;
                pq.push(make_pair(key[v],v));
                //parent[v]=node;
            }
		}
	}
}



int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,src,des,w,minCost=0,maxCost=0;
		scanf("%d",&n);

		adj.assign(n+3,vector<pair<int,int>>());
		selected.assign(n+3,false);
		key.assign(n+3,inf);
		//parent.assign(n+3,-1);

		scanf("%d %d %d",&src,&des,&w);

		while(!(src==0 && des==0 && w==0)){
			join(src,des,w);
			scanf("%d %d %d",&src,&des,&w);
		}


		primMinSt(0);

		for(int k=1;k<=n;k++){
			minCost+=key[k];
		}

		selected.assign(n+3,false);
		key.assign(n+3,-1);

		priority_queue<pair<int,int>> pq2;

		primMaxSt(0);

		for(int k=1;k<=n;k++){
			maxCost+=key[k];
		}

		int res=maxCost+minCost;

		if(res%2==0){
			printf("Case %d: %d\n",i,res/2);
		}
		else{
			printf("Case %d: %d/2\n",i,res);
		}
	}
	return 0;
}
