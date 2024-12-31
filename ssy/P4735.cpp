#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,L=25,M=3e5+10;
int n,m,xorall;
int trie[(N+M)*(L+1)][2],cnt[(N+M)*(L+1)];
int root[N+M]={0},tot=0;//0:nil
inline void pushup(int p){
    cnt[p]=cnt[trie[p][0]]+cnt[trie[p][1]];
}
//trie[0]={0,0},cnt[0]=0;
void insert(int &p,int q,int x,int pos){
    if(!p)  p=++tot;
    if(pos==-1){
        cnt[p]=cnt[q]+1;
        return;
    }
    int c=(x>>pos)&1;
    trie[p][c^1]=trie[q][c^1];
    insert(trie[p][c],trie[q][c],x,pos-1);
    pushup(p);
}
int query(int p,int q,int x,int pos,int val){//trie(q)-trie(p)
    if(pos==-1) return val^x;
    int c=(x>>pos)&1;c^=1;
    if(cnt[trie[q][c]]==cnt[trie[p][c]])
        return query(trie[p][c^1],trie[q][c^1],x,pos-1,val|((c^1)<<pos));
    else
        return query(trie[p][c],trie[q][c],x,pos-1,val|(c<<pos));
}
int main(){
    scanf("%d%d",&n,&m);
    insert(root[0],0,0,L);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        xorall^=x;
        insert(root[i],root[i-1],xorall,L);
    }
    while(m--){
        char op[2];
        scanf("%s",op);
        if(op[0]=='A'){
            int x;
            scanf("%d",&x);
            xorall^=x;
            n++;
            insert(root[n],root[n-1],xorall,L);
        }else{
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            int ans=query(l==1?0:root[l-2],root[r-1],x^xorall,L,0);
            printf("%d\n",ans);
        }
    }
    return 0;
}