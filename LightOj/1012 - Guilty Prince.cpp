#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > adj;
vector<int> visited;

void join(int src,int des){
	adj[src].push_back(des);
	adj[des].push_back(src);
}

int bfs(int sn){
	int c=0;
	queue<int> q;
	q.push(sn);
	visited[sn]=1;

	while(q.empty()==false){
		int node=q.front();
		q.pop();

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			if(visited[*i]!=1){
				visited[*i]=1;
				c++;
				q.push(*i);
			}
		}
	}
	return c;
}

int main(){
	int n,t;
	scanf("%d",&t);
	for(n=1;n<=t;n++){
		int w,h,x,y,res;
		int j,k,c=1;
		scanf("%d %d",&w,&h);
		char main[h+3][w+3];
		int dup[h+3][w+3];

		adj.assign(w*h+5,vector<int>());
		visited.assign(w*h+5,0);


		for(j=0;j<h;j++){
            scanf("%s",main[j]);
		}
		for(j=0;j<h;j++){
            for(k=0;k<w;k++){
                if(main[j][k]=='@'){
					x=j;
					y=k;
				}
				dup[j][k]=c;
				c++;
            }
		}

		for(j=0;j<h;j++){
			for(k=0;k<w;k++){
				if(main[j][k]=='.' || main[j][k]=='@'){
					if((main[j][k-1]=='.' || main[j][k-1]=='@') && k-1>=0){ //left
						join(dup[j][k],dup[j][k-1]);
					}
					if((main[j][k+1]=='.' || main[j][k+1]=='@') && k+1<h){  //right
						join(dup[j][k],dup[j][k+1]);
					}
					if((main[j-1][k]=='.' || main[j-1][k]=='@') && j-1>=0){ //up
						join(dup[j][k],dup[j-1][k]);
					}
					if((main[j+1][k]=='.' || main[j+1][k]=='@') && j+1<w){ //down
						join(dup[j][k],dup[j+1][k]);
					}
				}
			}
		}

		res=bfs(dup[x][y]);
		printf("Case %d: %d\n",n,res+1);
	}
}





/*
Test Cases:
4
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
*/