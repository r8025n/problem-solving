#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<int> visit;
int visited,n;
long long res;

void join(int src, int des){
  adj[src].push_back(des);
}

void dfs(int sn){
  if(visit[sn]==1)
    return;
  visit[sn]=1;
  visited++;
  for(int i=0;i<adj[sn].size();i++){
    dfs(adj[sn][i]);
    res+=n-visited;
  }
}


int main(){
  int k,t;
  scanf("%d",&t);
  for(k=1;k<=t;k++){
    int src,des;
    res=0,visited=0;
    scanf("%d",&n);
    adj.assign(n+3,vector<int>());
    visit.assign(n+3,0);
    for(int i=0;i<n-1;i++){
      scanf("%d %d",&src,&des);
      join(src,des);
    }
    dfs(1);
    printf("Case %d: %d %lld\n",k,n-1,res);
  }
  return 0;
}
