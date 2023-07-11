#include<iostream>
using namespace std;
int fa[1010];
void make_set(int n){
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int query(int x){
    return fa[x]==x?x:query(fa[x]);
}
void merge(int x,int y){
    fa[query(x)]=query(y);
}
int main(){
    while(1){
        int n,m;
        int du[1010]={0};
        cin>>n;
        if(n==0)    break;
        cin>>m;
        make_set(n);
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            merge(x,y);
            du[x]++;
            du[y]++;
        }
        int cnt=0;
        bool f=1;
        for(int i=1;i<=n;i++){
            if(fa[i]==i)
                cnt++;
            if(du[i]%2)
                f=0;
        }
        if(cnt!=1)  f=0;
        cout<<f<<endl;
    }
}
