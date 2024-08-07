#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,nxt[N],pre[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        nxt[i]=i+1,pre[i]=i-1;
    nxt[n]=1;
    pre[1]=n;
    for(int i=1,k=0,cnt=0;cnt<n;i=nxt[i],k=(k+1)%m)
        if(k==m-1){
            printf("%d ",i);
            nxt[pre[i]]=nxt[i];
            pre[nxt[i]]=pre[i];
            cnt++;
        }
    return 0;
}