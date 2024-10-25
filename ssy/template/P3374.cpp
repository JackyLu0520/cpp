#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10;
int n,m;
int c[N];
int lowbit(int x){
    return x&(-x);
}
void add(int i,int k){
    for(;i<=n;i+=lowbit(i))
        c[i]+=k;
}
int getsum(int i){
    int ans=0;
    for(;i;i-=lowbit(i))
        ans+=c[i];
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        add(i,x);
    }
    while(m--){
        int op,i,j;
        scanf("%d%d%d",&op,&i,&j);
        if(op==1){
            add(i,j);
        }else{
            printf("%d\n",getsum(j)-getsum(i-1));
        }
    }
    return 0;
}