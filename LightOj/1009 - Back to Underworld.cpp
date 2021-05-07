#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int track[20005];
int node[20005];
int n1,n2;

void join(int src, int des){
	adj[src].push_back(des);
	adj[des].push_back(src);
}

int bfs(int sn){
    int c1=0,c2=0;
	queue<int> q;
	q.push(sn);
	visited[sn]=1;
	track[sn]=1;
	node[sn]=0;
	c1++;
	n2++;

	while(q.empty()==false){
		int nod=q.front();
		q.pop();

		for(auto i=adj[nod].begin();i!=adj[nod].end();i++){
			if(visited[*i]!=1){
				visited[*i]=1;
				node[*i]=0;
				q.push(*i);
				n2++;
				if(track[nod]==1){
					track[*i]=2;
					c2++;
				}
				else if(track[nod]==2){
					track[*i]=1;
					c1++;
				}
			}
		}
	}
	return max(c1,c2);
}

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,src,des,j,sn,res=0;
		n1=0,n2=0;
		scanf("%d",&n);

        memset(track,0,sizeof(track));
        memset(node,0,sizeof(node));
		adj.assign(20005,vector<int>());
		visited.assign(20005,0);

		for(j=0;j<n;j++){
			scanf("%d %d",&src,&des);
			join(src,des);
			if(j==0){
				sn=src;
			}
			if(node[src]!=1){
                n1++;
                node[src]=1;
			}
			if(node[des]!=1){
                n1++;
                node[des]=1;
			}
		}
		res+=bfs(sn);
		while(n2!=n1){
            for(j=0;j<20000;j++){
                if(node[j]==1){
                    sn=j;
                    break;
                }
            }
            res+=bfs(sn);
		}
		printf("Case %d: %d\n",i,res);
	}
}

/*
3
2
1 2
2 3
3
1 2
2 3
4 2
4
1 2
2 3
3 4
1 4
*/



