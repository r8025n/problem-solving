#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adjF;
vector<vector<int>> adjR;
vector<int> min(505);
vector<int> max(505);
int value[505];
vector<int> visited;

void join(int x,int y){
	//constructing two different DAGs
	adjF[y].push_back(x);
	adjR[x].push_back(y);
}

void bfsMin(int sn){
	queue<int> q;
	q.push(sn);
	visited[sn]=1;

	while(q.empty()==false){
		int node=q.front();
		q.pop();
		for(auto i=adjF[node].begin();i!=adjF[node].end();i++){
			if(visited[*i]==0){
				visited[*i]=1;
				min[node]=min[node]+value[*i];
				q.push(*i);
			}
		}
	}
}

void bfsMax(int sn){
	queue<int> q;
	q.push(sn);
	visited[sn]=1;

	while(q.empty()==false){
		int node=q.front();
		q.pop();
		for(auto i=adjR[node].begin();i!=adjR[node].end();i++){
			if(visited[*i]==0){
				visited[*i]=1;
				max[node]=max[node]+value[*i];
				q.push(*i);
			}
		}
	}
}

int main(){
	int v,e;t=0;
	while(5>0){
		scanf("%d %d",&v,&e);
		if(v==0 && e==0){
			break;
		}
		t++;
		visited.assign(v+5,0);
		min.assign(v+5,0);
		max.assign(v+5,0);
		for(int i=1;i<v=;i++){
			scanf("%d",&value[i]);
		}
		int x,y;
		for(int k=0;k<e;k++){
			scanf("%d %d",&x,&y);
			join(x,y);
		}
		for(int i=1;i<=v;i++){
			if(visited[i]==0){
				bfsMin(i);
			}
		}
		visited.assign(v+5,0);
		for(int i=1;i<=v;i++){
			if(visited[i]==0){
				bfsMax(i);
			}
		}
		int q,work,m,res;
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			scanf("%d",&work);
			m=max[adjF[work].begin()];
			for(auto i=adjF[work].begin();i!=adjF[work].end();i++){
				if(m>max[*i]){
					m=value[*i];
				}
			}
			res=m-min[work];
			printf("%d\n",res);
		}
		printf("\n");
	}
	return 0;
}