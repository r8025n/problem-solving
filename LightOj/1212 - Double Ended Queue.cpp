#include<stdio.h>

int main(){
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int n,m,j,data;
        int val=0;
        scanf("%d %d",&n,&m);
        char c[20];
        int left[105],right[105];
        int l=-1,r=-1;
        int ol=0,or=0;

        printf("Case %d:\n",i);
        fgets(c,20,stdin);

        for(j=0;j<m;j++){
            memset(c,'\0',sizeof(c[0]));
            fgets(c,20,stdin);

            if(c[4]=='L'){
                //pushleft
                if(val==n){
                    printf("The queue is full\n");
                }
                else{
                    sscanf(c,"%*s %d",&data);
                    l++;
                    val++;
                    left[l]=data;
                    printf("Pushed in left: %d\n",data);
                }
            }
            else if(c[4]=='R'){
                //pushright
                if(val==n){
                    printf("The queue is full\n");
                }
                else{
                    sscanf(c,"%*s %d",&data);
                    r++;
                    val++;
                    right[r]=data;
                    printf("Pushed in right: %d\n",data);
                }
            }
            else if(c[3]=='L'){
                //popleft
                if(val==0){
                    printf("The queue is empty\n");
                }
                else if(l==-1 && val!=0/* && r>-1*/){
                    data=right[or];
                    if(or<r){
                        or++;
                    }
                    else if(or==r){
                        r=-1;
                        or=0;
                    }
                    val--;
                    printf("Popped from left: %d\n",data);
                }
                else{
                    data=left[l];
                    if(l==ol){
                        l=-1;
                        ol=0;
                    }
                    else{
                        l--;
                    }
                    val--;
                    printf("Popped from left: %d\n",data);
                }
            }
            else if(c[3]=='R'){
                //popright
                if(val==0){
                    printf("The queue is empty\n");
                }
                else  if(r==-1 && val!=0){
                    data=left[ol];
                    if(ol<l){
                        ol++;
                    }
                    else if(ol==l){
                        l=-1;
                        ol=0;
                    }
                    val--;
                    printf("Popped from right: %d\n",data);
                }
                else{
                    data=right[r];
                    if(r==or){
                        r=-1;
                        or=0;
                    }
                    else{
                        r--;
                    }
                    val--;
                    printf("Popped from right: %d\n",data);
                }
            }
        }
    }
}
