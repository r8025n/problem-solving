#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> dist;
int a,b,c,h,n;

void join(int src, int des){
	adj[src].push_back(des);
	//adj[des].push_back(src);
}

int bfs(int sn){
	visited.assign(n,0);
	dist.assign(n,0);
	int c=0;

	queue<int> q;
	q.push(sn);
	visited[sn]=1;

	while(q.empty()==false){
		int node=q.front();
		q.pop();
		c=dist[node]+1;

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			if(visited[*i]!=1){
				if(*i==h){
					return c;
				}
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
		int hh,w,j,k,o=0;
		int r1,r2,r3,mx=-1;
		scanf("%d %d",&hh,&w);
		n=hh*w;
		adj.assign(n+5,vector<int>());
		char city[hh+3][w+3];
		int dup[hh+3][w+3];
		for(j=0;j<hh;j++){
			scanf("%s",city[j]);
		}
		for(j=0;j<hh;j++){
			for(k=0;k<w;k++){
				o++;
				dup[j][k]=o;
				if(city[j][k]=='h'){
					h=dup[j][k];
				}
				else if(city[j][k]=='a'){
					a=dup[j][k];
				}
				else if(city[j][k]=='b'){
					b=dup[j][k];
				}
				else if(city[j][k]=='c'){
					c=dup[j][k];
				}
			}
		}
		for(j=0;j<hh;j++){
            for(k=0;k<w;k++){
                if(city[j][k]=='.' || city[j][k]=='a' || city[j][k]=='b' || city[j][k]=='c' || city[j][k]=='h'){
                    if((city[j-1][k]=='.' || city[j-1][k]=='a' || city[j-1][k]=='b' || city[j-1][k]=='c' || city[j-1][k]=='h')&& j-1>=0){
                        join(dup[j][k],dup[j-1][k]);
                    }
                    if((city[j+1][k]=='.' || city[j+1][k]=='a' || city[j+1][k]=='b' || city[j+1][k]=='c' || city[j+1][k]=='h')&&j+1<h){
                        join(dup[j][k],dup[j+1][k]);
                    }
                    if((city[j][k-1]=='.' || city[j][k-1]=='a' || city[j][k-1]=='b' || city[j][k-1]=='c' || city[j][k-1]=='h')&& k-1>=0){
                        join(dup[j][k],dup[j][k-1]);
                    }
                    if((city[j][k+1]=='.' || city[j][k+1]=='a' || city[j][k+1]=='b' || city[j][k+1]=='c' || city[j][k+1]=='h')&& k+1<w){
                        join(dup[j][k],dup[j][k+1]);
                    }
                }
            }
		}
		r1=bfs(a);
		if(r1>=mx)
			mx=r1;
		r2=bfs(b);
		if(r2>=mx)
			mx=r2;
		r3=bfs(c);
		if(r3>=mx)
			mx=r3;

		printf("Case %d: %d\n",i,mx);
	}
}
