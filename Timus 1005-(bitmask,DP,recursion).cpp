#include<iostream>

#define inf 0x3f3f3f3f
#define mx 25

using namespace std;

int ans=inf,n,total,r;
int w[mx],mem[1<<mx];

bool isOn(int mask,int pos){
    return (bool)(mask & (1<<pos));
}

int turnOn(int mask,int pos){
    return mask | (1<<pos);
}

int solve(int mask){
    if(mask==(1<<(n+1))-1){
        return 0;
    }
    if(mem[mask]!=-1)
        return mem[mask];

    for(int i=0;i<=n;i++){
        if(!isOn(mask,i)){
            int result=solve(turnOn(mask,i))+w[i];
            r=result;
            ans=min(ans,abs(result-(total-result)));
        }
    }
    mem[mask]=r;
    return mem[mask];
}

int main(){
    total=0;
    scanf("%d",&n);
    for(int i=1; i<=n;i++){
        scanf("%d",&w[i]);
        total+=w[i];
    }
    int lim=1<<(n+1);
    for(int i=0;i<=lim;i++){
        mem[i]=-1;
    }
    w[0]=0;
    int res=solve(1);

    printf("%d\n",ans);

    return 0;
}
