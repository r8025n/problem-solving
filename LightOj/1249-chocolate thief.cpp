#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,j,cons,mx,mn;
		int l,w,h;
		int tP=-1,vP=-1;
		int c=0;
		scanf("%d",&n);
		char name[n][25];
		int vol[n];

		for(j=0;j<n;j++){
			scanf("%s %d %d %d",name[j],&l,&w,&h);
			vol[j]=l*w*h;
		}
		////for 2 people
		if(n==2){
            if(vol[0]>vol[1]){
                tP=0;vP=1;
            }
            else if(vol[0]<vol[1]){
                tP=1;vP=0;
            }
		}
		////for 3 people
		if(n==3){
            mx=0;
            mn=25;
            for(j=0;j<3;j++){
                if(mx<vol[j]){
                    mx=vol[j];
                    tP=j;
                }
                if(mn>vol[j]){
                    mn=vol[j];
                    vP=j;
                }
            }

		}
		////for more than 3 people
		else{
            for(j=0;j<n;j++){
			if(c==0 && vol[j]==vol[j+1]){
				cons=vol[j];
				c++;
			}
			if(c>0)
				break;
            }
            for(j=0;j<n;j++){
                if(vol[j]<cons){
                    vP=j;
                }
                if(vol[j]>cons){
                    tP=j;
                }
            }
		}
		if(vP==-1 && tP==-1){
			printf("Case %d: no thief\n",i);
		}
		else{
			printf("Case %d: %s took chocolate from %s\n",i,name[tP],name[vP]);
		}
	}
}
