/*
求长度不超过m的最大子段和。1<=m<=n<=3*10^5
*/
#include<iostream>
#include<queue>
using namespace std;
const int MAXN=3e5,INF=0x3f3f3f3f;
int n,m;
int s[MAXN+10];
queue<int> q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]+=s[i-1];
    }
    int ans=-INF;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&i-q.front()>m)  q.pop();
        ans=max(ans,s[i]-s[q.empty()?0:q.front()]);
        while(!q.empty()&&s[q.back()]>=s[i])    q.pop();
        q.push(i);
    }
    cout<<ans;
    return 0;
}