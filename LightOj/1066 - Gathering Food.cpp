int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int j,k,x,y,a=0;
		char ch;
		c=0,flip=0,p=65;
		scanf("%d",&n);
		for(j=0;j<n;j++){
            scanf("%s",arr[j]);
		}
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(arr[j][k]<=90 && arr[j][k]>=65){
					if(arr[j][k]==65){
						x=j;
						y=k;
						//printf("x=%d y=%d\n",x,y);
					}
					a++;
				}
			}
		}
		q=64+a;
        //printf("q=%d",q);
		dfs(x,y);

		for(j=0;j<n;j++){
            printf("%s\n",arr[j]);
		}

		if(flip==1){
			printf("Case %d: %d\n",i,c);
		}
		else{
			printf("Case %d: Impossible\n",i);
		}
	}
	return 0;
}