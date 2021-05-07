#include<iostream>
#include<queue>
#include<stack>

using namespace std;


int r,c,escape;
char maze[205][205];

void burn(){
    stack<pair<int,int>> fire;
    int a,b;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(maze[i][j]=='F'){
			    fire.push(make_pair(i,j));
			}
		}
	}
	while(!fire.empty()){
            a=fire.top().first;
            b=fire.top().second;
            fire.pop();
            if(a-1>=0 && maze[a-1][b]!='#')
                maze[a-1][b]='F';
            if(a+1>=0 && maze[a+1][b]!='#')
                maze[a+1][b]='F';
            if(b-1>=0 && maze[a][b-1]!='#')
                maze[a][b-1]='F';
            if(b+1>=0 && maze[a][b+1]!='#')
                maze[a][b+1]='F';
		}
}

int bfs(int jx,int jy){
	int time=0;
	queue<pair<int,int>> q;
	q.push(make_pair(jx,jy));
	maze[jx][jy]='V';
	int xx[]={1,-1,0,0};
	int yy[]={0,0,1,-1};
	int a,b;
	int cc=1,p=0,temp=0;
    burn();

	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();

		if(cc==0){
         burn();
         time++;
         cc=temp;
		}
		if(cc!=0)
            cc--;

		for(int i=0;i<4;i++){
			a=x+xx[i];
			b=y+yy[i];
			if(maze[a][b]=='.'){
				maze[a][b]='V';
				q.push(make_pair(a,b));
				p++;
				if(a==0 || b==0 || a==r-1 || b==c-1)
					escape=1;
			}
		}

		if(cc==0){
            temp=p;
            p=0;
		}

		if(escape==1){
			break;
		}
	}
	return time+1;
}

int main(){
	int n,k;
	scanf("%d",&n);
	for(k=1;k<=n;k++){
		int jx,jy,res;
        escape=0;
		scanf("%d %d",&r,&c);

		for(int i=0;i<r;i++){
			scanf("%s",maze[i]);
			for(int j=0;j<c;j++){
				if(maze[i][j]=='J'){
					jx=i;
					jy=j;
				}
			}
		}
        if(jx==0 || jy==0 || jx==r-1 || jy==c-1){
            escape=1;
            res=1;
        }
        else{
         res=bfs(jx,jy);
         res++;
        }

		if(escape==1){
			printf("Case %d: %d\n",k,res);
		}
		else{
			printf("Case %d: IMPOSSIBLE\n",k);
		}
	}

	return 0;
}
