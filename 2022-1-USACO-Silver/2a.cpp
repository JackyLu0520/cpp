#include<iostream>
#include<cstring>
using namespace std;
int n,q,c[2][1510],ans=0,f[1510][1510]={0},d[1510][1510];
int main(){
    cin>>n;
    for(int i=0;i<=n;i++)
        d[0][i]=d[i][0]=-1;
    for(int i=1;i<=n;i++){
        string t;
        cin>>t>>c[0][i];
        for(int j=0;j<n;j++)
            d[i][j+1]=t[j]=='R'?0:1;
    }
    for(int i=1;i<=n;i++)
        cin>>c[1][i];
    cin>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(d[i-1][j]==1)   f[i][j]+=f[i-1][j];
            if(d[i][j-1]==0)   f[i][j]+=f[i][j-1];
            f[i][j]++;
        }
    for(int i=1;i<=n;i++)
        if(d[i][n]==0)
            ans+=c[0][i]*f[i][n];
    for(int i=1;i<=n;i++)
        if(d[n][i]==1)
            ans+=c[1][i]*f[n][i];
    cout<<ans<<endl;
    while(q--){
        int x,y,next[2][2]={{0,1},{1,0}};
        ans=0;
        cin>>x>>y;
        d[x][y]=!d[x][y];

        for(int x1=x,y1=y+1;x1!=n+1&&y1!=n+1;x1+=next[d[x1][y1]][0],y1=next[d[x1][y1]][1]);
        for(int x2=x+1,y2=y;x2!=n+1&&y2!=n+1;x2+=next[d[x2][y2]][0],y2=next[d[x2][y2]][1]);
        cout<<ans<<endl;
    }
    return 0;
}
