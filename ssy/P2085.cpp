#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e4+10;
int n,m;
int a[N],b[N],c[N];
priority_queue<pii,vector<pii>,greater<pii>>q;
int p[N];
int val(int x){
    return a[x]*p[x]*p[x]+b[x]*p[x]+c[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<=n;i++){
        p[i]=1;
        q.push(make_pair(val(i),i));
    }
    for(int i=1;i<=m;i++){
        pii t=q.top();q.pop();
        printf("%d ",t.first);
        p[t.second]++;
        q.push(make_pair(val(t.second),t.second));
    }
    return 0;
} 