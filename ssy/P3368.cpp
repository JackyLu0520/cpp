#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=5e5+10;
int n,m;
int c[N];
inline int lowbit(int x){return x&-x;}
void add(int x,int k){
    while(x<=n){
        c[x]+=k;
        x+=lowbit(x);
    }
}
int getsum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    int pre=0;
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        add(i,a-pre);
        pre=a;
    }
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){int x,y,k;scanf("%d%d%d",&x,&y,&k);add(x,k);add(y+1,-k);}
        else{int x;scanf("%d",&x);printf("%d\n",getsum(x));}
    }
    return 0;
}