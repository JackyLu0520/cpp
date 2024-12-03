#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,root,len;
int head[N],nxt[2*N],ver[2*N],tot=1;
inline void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
inline pair<int,int>query(vector<int>q){
    printf("? %d",q.size());
    for(int &u:q)
        printf(" %d",u);
    printf("\n");fflush(stdout);
    int x,d;scanf("%d%d",&x,&d);
    return make_pair(x,d);
}
int depth[N];
vector<int>s[N];
void dfs(int u,int p){
    depth[u]=depth[p]+1;
    s[depth[u]].push_back(u);
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs(v,u);
    }
}
int ans1,ans2;
inline bool check(int mid){
    if(s[mid].empty())
        return 0;
    int x,d;tie(x,d)=query(s[mid]);
    if(d==len)  ans1=x;
    return d==len;
}
vector<int>s1;
int depth1[N];
void dfs1(int u,int p){
    depth1[u]=depth1[p]+1;
    if(depth1[u]==len)   s1.push_back(u);
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs1(v,u);
    }
}
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        memset(head,0,sizeof(head));tot=1;
        for(int i=1;i<n;i++){
            int u,v;scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
        }
        for(int i=1;i<=n;i++)
            s[i].clear();
        s1.clear();
        depth[0]=depth1[0]=-1;
        vector<int>t;
        for(int i=1;i<=n;i++)
            t.push_back(i);
        tie(root,len)=query(t);
        dfs(root,0);
        int l=(len-1)/2+1,r=len;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid))  l=mid+1;
            else            r=mid-1;
        }
        dfs1(ans1,0);
        ans2=query(s1).first;
        printf("! %d %d\n",ans1,ans2);fflush(stdout);
        char result[20];
        scanf("%s",result);
        if(result[0]=='I')  return 0;
    }
    return 0;
}