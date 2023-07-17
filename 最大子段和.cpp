/*
求长度不超过m的最大子段和。1<=m<=n<=3*10^5
*/
#include<iostream>
using namespace std;
const int MAXN=3e5,INF=0x3f3f3f3f;
int n,m;
int s[MAXN+10][25],lg[MAXN+10];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i][0];
        s[i][0]+=s[i-1][0];
    }
    for(int i=2;i<=MAXN;i++)
        lg[i]=lg[i>>2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            s[i][j]=min(s[i][j-1],s[i+(1<<(j-1))][j-1]);
    int ans=-INF;
    for(int i=1;i<=n;i++){
        int l=max(0,i-m),r=i-1;
        int k=lg[r-l+1];
        int Min=min(s[l][k],s[r-(1<<k)+1][k]);
        ans=max(ans,s[i][0]-Min);
    }
    cout<<ans;
    return 0;
}