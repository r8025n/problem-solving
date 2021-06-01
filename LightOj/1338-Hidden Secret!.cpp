#include<bits/stdc++.h>

using namespace std;

string sortS(string &str){
	sort(str.begin(),str.end());
	return str;
}


int main(){
	int i,t;
	scanf("%d\n",&t);
	for(i=1;i<=t;i++){
		int j=0,k=0,l=0,m=0,trig;
		char a[105],b[105];
		string s1,s2;
		s1="";
		s2="";
		fgets(a,105,stdin);
        fgets(b,105,stdin);
		while(a[j]!='\0'){
			if(a[j]!=' '){
            s1=s1+a[j];
			j++;
			k++;
			}
			else{
                j++;
			}

		}
		s1[k]='\0';
		while(b[l]!='\0'){
			if(b[l]!=' '){
            s2=s2+b[l];
			l++;
			m++;
			}
			else{
                l++;
			}
		}
		s2[m]='\0';
		if(k!=m){
			trig=0;
		}
		else{
			transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
			transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
			s1=sortS(s1);
			s2=sortS(s2);
			if(s1==s2){
				trig=1;
			}
			else
				trig=0;
		}

		if(trig==1){
			printf("Case %d: Yes\n",i);
		}
		else
			printf("Case %d: No\n",i);
	}
}
