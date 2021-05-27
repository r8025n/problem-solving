#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		map<int,int> mp;
		map<int,int>::iterator it;
		int n,val,sign;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&val);
			if(val<0)
				sign=-1;
			else
				sign=1;
			if(mp.count(abs(val))==0){
				mp.insert(pair<int,int>(abs(val),sign));
			}
			else{
				mp[abs(val)]=sign;
			}
		}

		int sum=0;

		for(it=mp.begin();it!=mp.end();it++){
			sum=sum+(it->first*it->second);
		}

		printf("Case %d: %d\n",k,sum);

	}
    return 0;
}
