#include<stdio.h>

int binarySearch(int x,int *arr,int lo,int hi){
    int mid;
    while(lo<hi){
        mid=(hi+lo)/2;
        if(hi-lo==1){
            if(arr[lo]>=x){
                mid=lo;
                break;
            }
            else{
                mid=hi;
                break;
            }
        }
        if(arr[mid]>x){
            hi=mid;
        }
        else if(arr[mid]<x){
            lo=mid;
        }
        else if(arr[mid]==x){
            lo=hi;
        }
    }
    return mid;
}

int main(){
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int n,q,segStart,segEnd;
        scanf("%d %d",&n,&q);
        int lo=0,hi=n-1;
        int arr[n+5],res[q+2];

        for(int k=0;k<n;k++){
            scanf("%d",&arr[k]);
        }
        //if n equals 1 only
        if(n==1){
            for(int k=0;k<q;k++){
                scanf("%d %d",&segStart,&segEnd);
                if(segStart<=arr[0] && segEnd>=arr[0]){
                    res[k]=1;
                }
                else{
                    res[k]=0;
                }
            }

            printf("Case %d:\n",i);
            for(int k=0;k<q;k++){
                printf("%d\n",res[k]);
            }
        }
        else{
            int s1,s2,r;
            for(int k=0;k<q;k++){
                r=0;
                scanf("%d %d",&segStart,&segEnd);
                s1=binarySearch(segStart,arr,lo,hi);
                s2=binarySearch(segEnd,arr,lo,hi);
                if(segStart<=arr[n-1] && segEnd>arr[n-1]){
                    segEnd=arr[n-1];
                }
                if(segEnd==arr[s2]){
                   r+=1;
                }

                r+=s2-s1;
                res[k]=r;
            }

            printf("Case %d:\n",i);
            for(int k=0;k<q;k++){
                printf("%d\n",res[k]);
            }
        }
    }
    return 0;
}

/*
2
5 3
1 4 6 8 10
0 5
6 10
7 100000
5 1
10 20 30 40 50
15 45
//////
1
1 3
10
1 9
10 15
9 1000
*/
