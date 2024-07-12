#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,s[N],ans=0;
deque<int>q;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    q.push_back(0);
    for(int i=1;i<=n;i++){
        while(!q.empty()&&s[i]<=s[q.back()])    q.pop_back();
        q.push_back(i);
        while(!q.empty()&&i-q.front()>m)    q.pop_front();
        if(q.empty())   ans=max(ans,s[i]);
        else            ans=max(ans,s[i]-s[q.front()]);
    }
    printf("%d",ans);
    return 0;
}