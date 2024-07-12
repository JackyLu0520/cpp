#include<bits/stdc++.h>
using namespace std;
const int N=20,M=5;
int a[N];
bool f;
int main(){
    freopen("data.in","w",stdout);
    srand(time(0));
    int n=rand()%N+1,m=rand()%min(n,M)+1;printf("%d %d\n",n,m);
    do{
        bool vis[M]={0};f=0;
        for(int i=1;i<=n;i++){
            a[i]=rand()%m+1;vis[a[i]]=1;
        }
        for(int i=1;i<=m;i++)
            if(!vis[i])
                f=1;
    }while(f);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}