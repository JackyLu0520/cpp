#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,m,a[MAXN];
int st[MAXN][21],lg[MAXN];//st[i][j]:[i,i+2^j-1]
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&st[i][0]);
    for(int i=2;i<=n;i++)
        lg[i]=lg[i/2]+1;
    for(int j=1;j<=20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            //st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        int lgd=lg[y-x+1];
        //int ans=max(st[x][lgd],st[y-(1<<lgd)+1][lgd]);
        int ans=min(st[x][lgd],st[y-(1<<lgd)+1][lgd]);
        printf("%d\n",ans);
    }
    return 0;
}