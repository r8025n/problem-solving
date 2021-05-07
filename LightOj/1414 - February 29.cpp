#include<bits/stdc++.h>

using namespace std;

char month[12][15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


int ckLp(int n){
	if(n%4==0){
        if(n%100==0 && n%400!=0)
            return 0;
        else
            return 1;
	}
	else
        return 0;
}


int main(){
	int i,t;
	scanf("%d\n",&t);
	for(i=1;i<=t;i++){
		int j,x,res,h,c=0;
		int d[2],y[2],mn[2];
		double dd;
		char a[30],b[30],m[2][15];
		fgets(a,30,stdin);
		fgets(b,30,stdin);
		sscanf(a,"%s %d %*s %d",&m[0],&d[0],&y[0]);
		sscanf(b,"%s %d %*s %d",&m[1],&d[1],&y[1]);

		for(j=0;j<12;j++){
			x=strcmp(m[0],month[j]);
			if(x==0){
				mn[0]=j;
				break;
			}
		}
		for(j=0;j<12;j++){
			x=strcmp(m[1],month[j]);
			if(x==0){
				mn[1]=j;
				break;
			}
		}

        if(mn[0]>1){
            y[0]++;
        }

        if(mn[1]<1 || (mn[1]==1 && d[1]<29)){
            y[1]--;
        }

        res=y[1]/4-(y[0]-1)/4;
        res-=y[1]/100-(y[0]-1)/100;
        res+=y[1]/400-(y[0]-1)/400;



		printf("Case %d: %d\n",i,res);
	}
}


