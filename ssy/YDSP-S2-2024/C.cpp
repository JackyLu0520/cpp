#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
const int N=(1<<20)+10,INF=(1<<20)+10;
struct node{
    __gnu_pbds::tree<int,__gnu_pbds::null_type,
    less<int>,__gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>id;
    int s[2];
    node(){s[0]=s[1]=0;}
}trie[22*N];
int tot=0;
int n,q;
void insert(int a,int id){
    int p=0;
    for(int i=20;i>=0;i--){
        int x=(a>>i)&1;
        if(!trie[p].s[x])
            trie[p].s[x]=++tot;
        p=trie[p].s[x];
        trie[p].id.insert(id);
    }
}
int query(int l,int r,int x){
    int p=0,ans=0;
    for(int i=20;i>=0;i--){
        int t=(x>>i)&1;
        int q=1;
        if(trie[p].s[q]==0||trie[trie[p].s[q]].id.order_of_key(r+1)==trie[trie[p].s[q]].id.order_of_key(l))  q=0;
        ans|=((t|q)<<i);
        p=trie[p].s[q];
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;scanf("%d",&a);
        insert(a,i);
    }
    scanf("%d",&q);
    while(q--){
        int l,r,x;scanf("%d%d%d",&l,&r,&x);
        printf("%d\n",query(l,r,x));
    }
    return 0;
}