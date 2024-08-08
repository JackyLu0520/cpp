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
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        add(i,a);
    }
    while(m--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)   add(x,y);
        else        printf("%d\n",getsum(y)-getsum(x-1));
    }
    return 0;
}