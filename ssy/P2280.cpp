#include<bits/stdc++.h>
using namespace std;
const int XY=5e3+10;
int n,m,s[XY][XY],ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        s[x+1][y+1]+=v;
    }
    for(int i=1;i<XY;i++)
        for(int j=1;j<XY;j++)
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    for(int i=m;i<XY;i++)
        for(int j=m;j<XY;j++)
            ans=max(ans,s[i][j]-s[i-m][j]-s[i][j-m]+s[i-m][j-m]);
    printf("%d",ans);
    return 0;
}