#include<iostream>
#include<algorithm>

int n;
int val[18][18];
int mem[16][1<<16];


int isOn(int mask,int pos){
	return mask & (1<<pos);
}

int turnOn(int mask,int pos){
	return mask | (1<<pos);
}

int dpSolve(int man,int womanMask){
	if(womanMask==(1<<n)-1){
		return 0;
	}

	if(mem[man][womanMask]!=-1){
		return mem[man][womanMask];
	}

	int mn=-1;
	for(int w=0;w<n;w++){
		if(isOn(womanMask,w)==0){
			int result=dpSolve(man+1,turnOn(womanMask,w))+ val[man][w];
			mn=std::max(mn,result);
		}
	}

	mem[man][womanMask]=mn;
	return mem[man][womanMask];
}


int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		int output,mask=0;
		scanf("%d",&n);

		for(int k=0;k<n;k++){
			for(int j=0;j<n;j++){
				scanf("%d",&val[k][j]);
			}
		}

		for(int k=0;k<n;k++){
			for(int j=0;j<1<<n;j++){
				mem[k][j]=-1;
			}
		}

		output=dpSolve(0,mask);

		printf("Case %d: %d\n",i,output);
	}

	return 0;
}
