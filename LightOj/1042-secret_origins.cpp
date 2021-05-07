#include<bits/stdc++.h>
using namespace std;

string s="";
int counter;
int returnOne(long long x){
    int one=0,c=0;
     while(x>0){
        if(x%2==1){
            one++;
            s='1'+s;
        }
        else{
            s='0'+s;
        }
        c++;
        x=x/2;
    }
    counter=c;
    return one;
}

int main(){
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        s="";
        long long x,res;
        int c,j,k,inOne,outOne;
        int f,one=0;
        double m,cc,d,b;
        double temp=0;
        scanf("%lld",&x);
        inOne=returnOne(x);
        c=counter-1;
        s[c+1]='\0';
        cc=(double)c;

        if(inOne==1){
            res=(long long)(2*x);
        }

        else if(counter==inOne){
            d=ceil((double)x/2);
            res=x+(long long)d;

        }
        else{
            j=c;
            if(s[j]=='1'){
                while(s[j]=='1'){
                    j--;
                }
                s[j]='1';
                s[j+1]='0';
            }
            else{
                while(s[j]=='0'){
                    j--;
                }
                while(s[j]=='1'){
                    one++;
                    if(j==0){
                        j--;

                        b=cc+1;
                        m=pow(2,b);
                        temp+=m;
                        goto flag;
                    }
                    j--;

                }
                s[j]='1';
                flag:
                s[j+1]='0';
                for(k=1;k<=one-1;k++){
                    s[c]='1';
                    c--;
                }
                for(k=j+2;k<=c;k++){
                    s[k]='0';
                }
            }
            for(k=0,j=cc;k<=cc,j>=0;k++,j--){
                temp+=((double)(s[k]-'0')*pow(2,(double)j));
            }
            res=(long long)temp;
        }

        printf("Case %d: %lld\n",i,res);
    }
}
