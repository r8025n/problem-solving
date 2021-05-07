//omptimaized after locking the problem...now 145ms
#include<iostream>
#include<stack>
#include<utility>
 
using namespace std;
 
int m,n,q,c;
char arr[505][505];
int visited[505][505];
stack<pair<int,int>> s;
 
void dfs(int x,int y){
    if(arr[x][y]!='#' && x>=0 && y>=0 && x<m && y<n && visited[x][y]!=1){
        if(arr[x][y]=='C'){
            c++;
        }
        s.push(make_pair(x,y));
        visited[x][y]=1;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }
}
 
 
int main(){
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int x,y,res;
        scanf("%d %d %d",&m,&n,&q);
        for(int k=0;k<m;k++){
            scanf("%s",&arr[k]);
        }
 
        for(int j=0;j<m;j++){
                for(int l=0;l<n;l++){
                    visited[j][l]=0;
                }
            }

        int a,b;
        printf("Case %d:\n",i);
        for(int k=0;k<q;k++){
            c=0;
            scanf("%d %d",&x,&y);
            if(visited[x-1][y-1]==-1){
                dfs(x-1,y-1);
                res=c;
                while(s.empty()==false){
                    a=s.top().first;
                    b=s.top().second;
                    visited[a][b]=res;
                    s.pop();
                }
            }
            else{
                res=visited[x-1][y-1];
            }
            printf("%d\n",res);
        }
    }
    return 0;
}