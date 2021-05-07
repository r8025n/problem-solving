#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> money;

void join(int src,int des){
    adj[src].push_back(des);
    adj[des].push_back(src);
}

int bfs(int sn){
    queue<int> q;
    q.push(sn);
    visited[sn]=1;
    int c=1;
    int total=money[sn];

    while(q.empty()==false){
        int node=q.front();
        q.pop();

        for(auto i=adj[node].begin();i!=adj[node].end();i++){
            if(visited[*i]!=1){
                visited[*i]=1;
                q.push(*i);
                c++;
                total+=money[*i];
            }
        }
    }
    int r=total/c;

    return r;
}



int main(){
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int n,m,j,totalMoney=0,src,des,sn,ret,yes=1;
        double d;
        scanf("%d %d",&n,&m);
        adj.assign(n+3,vector<int>());
        visited.assign(n+3,0);
        money.assign(n+3,0);
        queue<int> qq;

        for(j=1;j<=n;j++){
            scanf("%d",&money[j]);
            totalMoney+=money[j];
        }

        for(j=0;j<m;j++){
            scanf("%d %d",&src,&des);
            join(src,des);
            if(j==0){
                sn=src;
            }
        }

        d=totalMoney/(double)n;
        if(d-(int)d!=0){
            yes=0;
            goto no;
        }

        ret=bfs(sn);

        if(ret!=(int)d){
            yes=0;
            goto no;
        }

        for(j=1;j<=n;j++){
            if(visited[j]==0){
                qq.push(j);
            }
        }

        while(qq.empty()==false){
            int node=qq.front();
            qq.pop();
            if(visited[node]==0){
                ret=bfs(node);
                if(ret!=(int)d){
                    yes=0;
                    break;
                }
            }
        }

        no:

        if(yes==1){
            printf("Case %d: Yes\n",i);
        }
        else{
            printf("Case %d: No\n",i);
        }
    }
    return 0;
}

/*
1
8 5
6 1 1 0 5 0 2 1
1 2
1 3
1 4
5 6
7 8
*/