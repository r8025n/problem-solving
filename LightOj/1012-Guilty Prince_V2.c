#include<stdio.h>
 
char m[20][20];
int w,h,c=1;
 
void dfs(int x,int y){
    if(x<0 || x>=h || y<0 || y>=w){
        return;
    }
    else if(m[x][y]=='#'){
        return;
    }
    else if(m[x][y]=='.'){
        c++;
        m[x][y]='#';
    }
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x-1,y);
    dfs(x+1,y);
}
 
 
int main(){
    int n,t;
    scanf("%d",&t);
    for(n=1;n<=t;n++){
        int x,y,i,j,res;
        scanf("%d %d",&w,&h);
        for(i=0;i<h;i++){
            scanf("%s",m[i]);
            for(j=0;j<w;j++){
                if(m[i][j]=='@'){
                    x=i;
                    y=j;
                }
            }
        }
        dfs(x,y);
        res=c;
        c=1;
        printf("Case %d: %d\n",n,res);
    }
    return 0;