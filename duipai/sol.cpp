#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=22;
int n,m,a[N];
vector<int>tmp;
struct node{
    int sum;
    int ls,rs;
}t[2*N+N*L];int tot=0;
int root[N];
inline void clear(){
    tot=0;
    memset(root,0,sizeof(root));
}
inline void pushup(int p){
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
void build(int &p,int l,int r){
    if(!p)  p=++tot,t[p].ls=t[p].rs=0;
    if(l==r){t[p].sum=0;return;}
    int mid=(l+r)/2;
    build(t[p].ls,l,mid);
    build(t[p].rs,mid+1,r);
    pushup(p);
}
void add(int &p,int q,int i,int k,int l,int r){
    if(!p)  p=++tot,t[p].ls=t[p].rs=0;
    if(l==r){
        t[p].sum=t[q].sum+k;
        return;
    }
    int mid=(l+r)/2;
    if(i<=mid)  t[p].rs=t[q].rs,add(t[p].ls,t[q].ls,i,k,l,mid);
    else        t[p].ls=t[q].ls,add(t[p].rs,t[q].rs,i,k,mid+1,r);
    pushup(p);
}
int query(int p,int k,int l,int r){
    if(l==r)    return tmp[l-1]<=k?t[p].sum:0;
    int mid=(l+r)/2;
    if(k<=tmp[mid-1])   return query(t[p].ls,k,l,mid);
    else                return query(t[p].rs,k,mid+1,r)+t[t[p].ls].sum;
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
    int _;
    scanf("%d",&_);
    for(int caseid=1;caseid<=_;caseid++){
        printf("Case %d:\n",caseid);
        scanf("%d%d",&n,&m);
        clear();
        tmp.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            tmp.emplace_back(a[i]);
        }
        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        build(root[0],1,tmp.size());
        for(int i=1;i<=n;i++){
            int p=lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin()+1;
            add(root[i],root[i-1],p,1,1,tmp.size());
        }
#ifdef DEBUG
        for(int i=1;i<=tmp.size();i++)
            printf("%d ",tmp[i-1]);
        printf("\n");
        for(int i=0;i<=n;i++){
            printf("%d:",i);
            for(int j=1;j<=tmp.size();j++)
                printf("%d ",singlequery(root[i],j,1,tmp.size()));
            printf("\n");
        }
#endif
        for(int i=1;i<=m;i++){
            int l,r,h;
            scanf("%d%d%d",&l,&r,&h);l++;r++;
            int qr=query(root[r],h,1,tmp.size()),ql=query(root[l-1],h,1,tmp.size());
#ifdef DEBUG
            printf("%d %d ",qr,ql);
#endif
            printf("%d\n",qr-ql);
        }
    }
    return 0;
}