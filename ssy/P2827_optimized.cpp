#include<bits/stdc++.h>
using namespace std;
const int N=7e6+1e5+10;
int n,m,q,u,v,t,add=0;
int a[N];
queue<int>Q[3];
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)
        Q[0].push(a[i]);
    for(int i=1;i<=m;i++){
        pair<int,int> f0=make_pair(Q[0].empty()?0xc0c0c0c0:Q[0].front(),0);
        pair<int,int> f1=make_pair(Q[1].empty()?0xc0c0c0c0:Q[1].front(),1);
        pair<int,int> f2=make_pair(Q[2].empty()?0xc0c0c0c0:Q[2].front(),2);
        pair<int,int> x=max(f0,max(f1,f2));
        Q[x.second].pop();
        x.first+=add;
        if(i%t==0)  printf("%d ",x.first);
        int x1=1LL*x.first*u/v;
        int x2=x.first-x1;
        Q[1].push(x1-q-add);Q[2].push(x2-q-add);
        add+=q;
    }
    printf("\n");
    for(int i=1;i<=n+m;i++){
        pair<int,int> f0=make_pair(Q[0].empty()?0xc0c0c0c0:Q[0].front(),0);
        pair<int,int> f1=make_pair(Q[1].empty()?0xc0c0c0c0:Q[1].front(),1);
        pair<int,int> f2=make_pair(Q[2].empty()?0xc0c0c0c0:Q[2].front(),2);
        pair<int,int> x=max(f0,max(f1,f2));
        if(i%t==0)  printf("%d ",Q[x.second].front()+add);
        Q[x.second].pop();
    }
    return 0;
}