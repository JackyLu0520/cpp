#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,K=1e5+10;
int n,k,x[N],cnt[N];
vector<int>t;
int head[N],nxt[K+3*N],ver[K+3*N],ew[K+3*N],tot=1;//-1:NIL
inline void clear(){
    memset(head,-1,sizeof(head));
    tot=1;
}
inline void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N],inq[N];
queue<int>q;
void spfa(int st){
    memset(dis,~0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    q.emplace(st);dis[st]=0;inq[st]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i!=-1;i=nxt[i]){
            int v=ver[i],w=ew[i];
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.emplace(v);
                    inq[v]=1;
                }
            }
        }
    }
}
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        memset(cnt,0,sizeof(cnt));
        clear();
        scanf("%d%d",&n,&k);
        t.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
            t.emplace_back(x[i]);
        }
        sort(t.begin(),t.end());
        t.erase(unique(t.begin(),t.end()),t.end());
        for(int i=1;i<=n;i++){
            int p=lower_bound(t.begin(),t.end(),x[i])-t.begin()+1;
            cnt[p]++;
        }
        for(int i=1;i<=k;i++){
            int l,r,w;scanf("%d%d%d",&l,&r,&w);
            int lp=lower_bound(t.begin(),t.end(),l)-t.begin();
            int rp=upper_bound(t.begin(),t.end(),r)-t.begin();
            add(lp,rp,w);//sum[rp]-sum[lp]>=w
        }
        for(int i=1;i<=t.size();i++)
            add(i,i-1,-cnt[i]);//sum[i-1]-sum[i]>=-cnt[i]
        for(int i=1;i<=t.size();i++)
            add(i-1,i,0);//sum[i]-sum[i-1]>=0
        for(int i=0;i<=t.size();i++)
            add(t.size()+1,i,0);
        spfa(t.size()+1);
        printf("%d\n",n-dis[t.size()]);
#ifdef DEBUG
        for(int i=1;i<=t.size();i++)
            printf("%d ",dis[i]);
        printf("\n");
#endif
    }
    return 0;
}