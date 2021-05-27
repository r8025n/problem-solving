#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define inf 0x3f3f3f3f

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> cost;
vector<int> dist;

void join(int src,int des,int w){
    if(cost[src][des]>w){
        adj[src].push_back(des);
        adj[des].push_back(src);
        cost[src][des]=w;
        cost[des][src]=w;
    }
}

void dijkstra(int src){
    queue<int> q;
    dist[src]=0;
    q.push(src);

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(vector<int>::iterator i=adj[u].begin();i!=adj[u].end();i++){
            int v=*i;
            int w=cost[u][v];
            int maxx=max(w,dist[u]);
            if(maxx<dist[v]){
                dist[v]=maxx;
                q.push(v);
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        int n,m,source;
        int u,v,w;

        scanf("%d %d",&n,&m);
        adj.assign(n+3,vector<int>());
        cost.assign(n+3,vector<int>(n+3,inf));
        dist.assign(n+3,inf);

        while(m--){
            scanf("%d %d %d",&u,&v,&w);
            join(u,v,w);
        }

        scanf("%d",&source);

        dijkstra(source);

        printf("Case %d:\n",k);
        for(int i=0;i<n;i++){
            if(dist[i]==inf){
                printf("Impossible\n");
            }
            else{
                printf("%d\n",dist[i]);
            }
        }
    }
    return 0;
}




