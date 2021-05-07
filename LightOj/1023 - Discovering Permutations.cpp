#include<bits/stdc++.h>

using namespace std;

char s[30],dup[30];
int n,k;
int cnt=0;

void next(int l){
	int i,j,c=0,op;
	char temp;

    printf("%s\n",s);

	cnt++;
	if(cnt==k){
        cnt=0;
		return;
	}

	for(i=n-1;i>l;i--){
		if(s[i]>s[l]){
            c++;
			temp=s[i];
			s[i]=s[l];
			s[l]=temp;
			break;
		}
	}
	if(c==0){
        cnt=0;
        return;
	}

	for(i=l+1,j=n-1;i<=n-1,j>=l+1;i++,j--){
        dup[i]=s[j];
	}
	for(i=l+1;i<=n-1;i++){
        s[i]=dup[i];
	}

	for(i=n-1;i>=1;i--){
		if(s[i]>s[i-1]){
			op=i-1;
			break;
		}
	}
	next(op);
}


int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int j;
		scanf("%d %d",&n,&k);
		if(n==1){
            printf("Case %d:\n",i );
            printf("A\n");
		}
		else{
            for(j=0;j<n;j++){
			s[j]=65+j;
            }
            s[j]='\0';
            printf("Case %d:\n",i);
            next(n-2);
		}

	}

}
