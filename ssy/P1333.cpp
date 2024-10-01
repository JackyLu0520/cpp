#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n=0;
unordered_map<string,int>m;
int deg[N];
struct dsu{
    int fa[N];
    dsu(int tot){for(int i=1;i<=tot;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){fa[query(x)]=query(y);}
};
int main(){
    dsu d(N-1);
    char s1[15],s2[15];
    while(scanf("%s %s",s1,s2)!=EOF){
        if(!m.count(s1)) m[s1]=++n;
        if(!m.count(s2)) m[s2]=++n;
        d.merge(m[s1],m[s2]);
        deg[m[s1]]++;deg[m[s2]]++;
        //cout<<s1<<' '<<s2<<'\n';
    }
    //for(auto it=m.begin();it!=m.end();it++)
    //    cout<<it->first<<' '<<it->second<<'\n';
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=(d.fa[i]==i);
    if(cnt>1){printf("Impossible");return 0;}
    cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=(deg[i]%2);
    if(cnt!=0&&cnt!=2){printf("Impossible");return 0;}
    else{printf("Possible");return 0;}
    return 0;
}