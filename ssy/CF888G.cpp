#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,L=31;
struct node{
    int s[2];
    int l,r;
};
struct bin_trie{
    node t[N*L];
    int tot=1;
    node operator[](const int& i){
        return t[i];
    }
    void insert(int x,int id){
        int p=1;
        for(int i=L-1;i>=0;i--){
            int c=(x>>i)&1;
            if(!t[p].s[c]){
                t[p].s[c]=++tot;
                t[t[p].s[c]].l=id;
            }
            t[t[p].s[c]].r=id;
            p=t[p].s[c];
        }
    }
    int query(int p,int x,int d){
        int ans=0;
        for(int i=d;i>=0;i--){
            int c=(x>>i)&1;
            if(!t[p].s[c]){
                ans|=(1<<i);
                p=t[p].s[c^1];
            }else
                p=t[p].s[c];
        }
        return ans;
    }
}trie;
int n,a[N];
long long dfs(int p,int d){
    if(d<0) return 0ll;
    if(trie[p].s[0]&&trie[p].s[1]){
        int ans=(1<<30);
        for(int i=trie[trie[p].s[0]].l;i<=trie[trie[p].s[0]].r;i++)
            ans=min(ans,trie.query(trie[p].s[1],a[i],d-1)+(1<<d));
        return dfs(trie[p].s[0],d-1)+dfs(trie[p].s[1],d-1)+ans;
    }else if(trie[p].s[0])
        return dfs(trie[p].s[0],d-1);
    else if(trie[p].s[1])
        return dfs(trie[p].s[1],d-1);
    else
        return 0ll;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        trie.insert(a[i],i);
    printf("%lld",dfs(1,L-1));
    return 0;
}