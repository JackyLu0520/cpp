#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
bool a[N][N];
int r[N][N];
int ans=0;
int main(){
    freopen("art.in","r",stdin);
    freopen("art.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        char s[N];scanf("%s",s);
        for(int j=1;j<=m;j++)
            a[i][j]=(s[j]=='B');
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j==n||a[i][j]!=a[i][j+1])
                for(int k=j;a[i][k]==a[i][j]&&k>=1;k--)
                    r[i][k]=j-k+1;
    for(int j=1;j<=m;j++){
        stack<int>s;
        int lmin[N];
        for(int i=1;i<=n;i++){
            while(!s.empty()&&r[s.top()][j]>r[i][j])
                s.pop();
            lmin[i]=s.empty()?0:s.top();
            s.push(i);
        }
        for(int i=1;i<=n;i++){
            for(int k=i;k>=1;k=lmin[k]){
                if(i-lmin[k]+1>r[k][j]){ans=max(ans,r[k][j]);break;}
                if(i-lmin[k]+1<=r[k][j]&&i-lmin[k]+1>r[lmin[k]][j]){
                    ans=max(ans,i-lmin[k]);break;
                }
            }
        }
    }
    printf("%d",ans*ans);
    return 0;
}