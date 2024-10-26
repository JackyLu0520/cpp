#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+10;
int n;
pair<int,int>m[3][N];
int ans[3][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int g,s,b;scanf("%d%d%d",&g,&s,&b);
        m[0][i]=make_pair(g,i);
        m[1][i]=make_pair(s,i);
        m[2][i]=make_pair(b,i);
    }
    sort(m[0]+1,m[0]+n+1,greater<pair<int,int>>());
    sort(m[1]+1,m[1]+n+1,greater<pair<int,int>>());
    sort(m[2]+1,m[2]+n+1,greater<pair<int,int>>());
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;){
            int k=j;
            for(;k<=n&&m[i][j].first==m[i][k].first;k++)
                ans[i][m[i][k].second]=j;
            j=k;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",min(ans[0][i],min(ans[1][i],ans[2][i])));
    return 0;
}