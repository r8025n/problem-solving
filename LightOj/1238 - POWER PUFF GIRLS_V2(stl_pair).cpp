#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

pair<int,int> p;
int visited[22][22];
int dist[22][22];
int h,w;
int dirx[]={1,-1,0,0};
int diry[]={0,0,1,-1};
char city[22][22];

int bfs(int i,int j){
    int l,k,x,y,c;
    for(l=0;l<h;l++){
        for(k=0;k<w;k++){
            visited[l][k]=0;
            dist[l][k]=0;
        }
    }

    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    visited[i][j]=1;

    while(q.empty()==false){
        x= q.front().first;
        y=q.front().second;
        q.pop();
        c=dist[x][y]+1;
        for(k=0;k<4;k++){
            i=x+dirx[k];
            j=y+diry[k];
            if(city[i][j]=='h'){
                return c;
            }
            if(visited[i][j]==0 && city[i][j]!='m' && city[i][j]!='#' && i>=0 && i<h && j>=0 && j<w){
                visited[i][j]=1;
                dist[i][j]=c;
                q.push(make_pair(i,j));
            }
        }
    }
}


int main(){
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int j,k;
        int ta,tb,tc,res;
        scanf("%d %d",&h,&w);
        for(j=0;j<h;j++){
            scanf("%s",city[j]);
        }
        for(j=0;j<h;j++){
            for(k=0;k<w;k++){
                if(city[j][k]=='a'){
                    ta=bfs(j,k);
                }
                if(city[j][k]=='b'){
                    tb=bfs(j,k);
                }
                if(city[j][k]=='c'){
                    tc=bfs(j,k);
                }
            }
        }

        res=max(ta,max(tb,tc));

        printf("Case %d: %d\n",i,res);
    }
    return 0;
}
