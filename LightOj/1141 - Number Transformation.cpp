#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> visited;
vector<int> dist;

void sieve(int n,int *arr){
	arr[1]=-1;
	arr[2]=2;

	for(int i=3;i<n;i++){
		if(i%2==0)
			arr[i]=-1;
		else
			arr[i]=i;
	}

	for(int i=3;i*i<=n;i++){
		if(arr[i]!=-1){
			for(int k=2;k*i<=n;k++){
				arr[k*i]=-1;
			}
		}
	}
}

int bfs(int x,int y, int *arr){
	int c,z;
	queue<int> q;
	q.push(x);
	visited[x]=true;

	while(q.empty()==false){
		int node=q.front();
		q.pop();
		c=dist[node]+1;

        for(int i=2;i*2<=node;i++){
            z=node+i;
            if(node%i==0 && arr[i]!=-1 && visited[z]==false && z<=y){
                visited[z]=true;
                if(z==y){
                    return c;
                }
                q.push(z);
                dist[z]=c;
            }
        }
	}
	return -1;
}

int main(){
	int i,t;
	int n=1010;
	int prime[n];
	sieve(n,prime);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int s,t,res;
		scanf("%d %d",&s,&t);
		visited.assign(1010,false);
		dist.assign(1010,0);
		if(t<s)
			res=-1;
        else if(t==s)
            res=0;
		else{
			res=bfs(s,t,prime);
		}

		printf("Case %d: %d\n",i,res);
	}
	return 0;
}
