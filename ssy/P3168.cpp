#include<bits/stdc++.h>
//#define DEBUG
using namespace std;
const int M=1e5+10,N=1e5+10,L=22;
int m,n;
vector<pair<int,int>>op[N];
vector<int>tmp;
struct node{
    int sum,cnt;
    int ls,rs;
}t[2*M+2*M*L];
int root[N],tot=0;
inline void pushup(int p){
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
    t[p].cnt=t[t[p].ls].cnt+t[t[p].rs].cnt;
}
void build(int &p,int l,int r){
    if(!p)  p=++tot;
    if(l==r){t[p].sum=t[p].cnt=0;return;}
    int mid=(l+r)/2;
    build(t[p].ls,l,mid);
    build(t[p].rs,mid+1,r);
    pushup(p);
}
void add(int &p,int q,int i,int k,int pl,int pr){
    if(!p)  p=++tot;
    if(pl==pr){
        t[p].sum=t[q].sum+tmp[i-1]*k;
        t[p].cnt=t[q].cnt+k;
        return;
    }
    int mid=(pl+pr)/2;
    if(i<=mid)  t[p].rs=t[q].rs,add(t[p].ls,t[q].ls,i,k,pl,mid);
    else        t[p].ls=t[q].ls,add(t[p].rs,t[q].rs,i,k,mid+1,pr);
    pushup(p);
}
int query(int p,int k,int ret,int pl,int pr){
    if(pl==pr)  return ret;
    int mid=(pl+pr)/2;
    if(k<=t[t[p].ls].cnt)   return query(t[p].ls,k,ret,pl,mid);
    else                    return query(t[p].rs,k-t[t[p].ls].cnt,ret+t[t[p].ls].sum,mid+1,pr);
}
#ifdef DEBUG
int singlequery(int p,int i,int pl,int pr){
    if(pl==pr)  return t[p].sum;
    int mid=(pl+pr)/2;
    if(i<=mid)  return singlequery(t[p].ls,i,pl,mid);
    else        return singlequery(t[p].rs,i,mid+1,pr);
}
#endif
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        int s,e,p;
        scanf("%d%d%d",&s,&e,&p);
        op[s].emplace_back(p,1);
        op[e+1].emplace_back(p,-1);
        tmp.emplace_back(p);
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    build(root[0],1,tmp.size());
    for(int i=1;i<=n;i++){
        if(op[i].empty()){
            root[i]=root[i-1];
            continue;
        }
        int pre=root[i-1];
        for(auto j=op[i].begin();j!=op[i].end();j++){
            int p,k;tie(p,k)=*j;
            p=lower_bound(tmp.begin(),tmp.end(),p)-tmp.begin()+1;
            root[i]=0;
            add(root[i],pre,p,k,1,tmp.size());
            pre=root[i];
        }
    }
#ifdef DEBUG
    for(int i=1;i<=n;i++){
        printf("%d:",i);
        for(int j=0;j<tmp.size();j++){
            printf("%d ",singlequery(root[i],j+1,1,tmp.size()));
        }
        printf("\n");
    }
#else
    int pre=1;
    for(int i=1;i<=n;i++){
        int x,a,b,c;
        scanf("%d%d%d%d",&x,&a,&b,&c);
        int k=1+(a*pre+b)%c;
        pre=query(root[x],k,0,1,tmp.size());
        printf("%d\n",pre);
    }
#endif
    return 0;
}