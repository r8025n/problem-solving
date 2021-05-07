#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int n,m,k,p;
		int j,l,o;
		int yes=0,no=0;
		scanf("%d %d %d",&n,&m,&k);
		int wish[n+5][k+5];
		for(j=0;j<n;j++){
			for(l=0;l<k;l++){
				scanf("%d",&wish[j][l]);
			}
		}
		scanf("%d",&p);
		int res[p+5];
		for(j=0;j<p;j++){
			scanf("%d",&res[j]);
		}

        if(p==0){
            for(j=0;j<n;j++){
                for(l=0;l<k;l++){
                    if(wish[j][l]<0){
                        yes++;
                        break;
                    }
                }
            }
        }
        else{
            for(j=0;j<n;j++){
                for(l=0;l<k;l++){
                    no=0;
                    for(o=0;o<p;o++){
                        if(wish[j][l]>0){
                            if(res[o]==wish[j][l]){
                                goto label;
                            }
                        }
                        else if(wish[j][l]<0){
                            if(p==0){
                                goto label;
                            }
                            if(res[o]!=abs(wish[j][l])){
                                no++;
                            }
                        }
                    }
                    if(no==p){
                        label:
                        yes++;
                        break;
                    }
                }
            }
        }

		if(yes==n){
			printf("Case %d: Yes\n",i);
		}
		else{
			printf("Case %d: No\n",i);
		}
	}
}
