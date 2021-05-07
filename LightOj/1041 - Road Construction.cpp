//Used stl_map in this code for the first time. Here in the graph, nodes were name of cities
//rather than numbers. SO used map to assign a value for each cities. And pushed the values
//to the adjacency list


#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>

#define inf 0x3f3f3f3f

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> selected;
vector<int> parent,key;
map<string,int> mp;

void join(int src, int des, int w){
	adj[src].push_back(make_pair(des,w));
	adj[des].push_back(make_pair(src,w));
}

void primMst(int sn){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	parent[sn]=-1;
	key[sn]=0;
	pq.push(make_pair(key[sn],sn));

	int w,v;
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
				parent[v]=node;
			}
		}
	}
}


int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,w;
		char s[55],d[55];
		scanf("%d",&n);

		adj.assign(n*2+3,vector<pair<int,int>>());
		selected.assign(n*2+3,false);
		parent.assign(n*2+3,-1);
		key.assign(n*2+3,inf);
		mp.clear();

		int c=0,src,des;

		for(int k=0;k<n;k++){
			scanf("%s %s %d",s,d,&w);
			if(mp.count(s)>0){
				src=mp[s];
			}
			else{
				mp[s]=c;
				src=c;
				c++;
			}
			if(mp.count(d)>0){
				des=mp[d];
			}
			else{
				mp[d]=c;
				des=c;
				c++;
			}
			join(src,des,w);
		}

		primMst(0);

		int minCost=0;
		bool impossible=false;

		for(int k=0;k<=c-1;k++){
			if(key[k]==inf){
                impossible=true;
                continue;
			}
            minCost+=key[k];
		}

        if(impossible==false){
            printf("Case %d: %d\n",i,minCost);
        }
        else{
            printf("Case %d: Impossible\n",i);
        }
	}
	return 0;
}

/*
2

12
Dhaka Sylhet 0
Ctg Dhaka 0
Sylhet Chandpur 9
Ctg Barisal 9
Ctg Rajshahi 9
Dhaka Sylhet 9
Ctg Rajshahi 3
Sylhet Chandpur 5
Khulna Rangpur 7
Chandpur Rangpur 7
Dhaka Rajshahi 6
Dhaka Rajshahi 7

2
Rajshahi Khulna 4
Kushtia Bhola 1
*/
