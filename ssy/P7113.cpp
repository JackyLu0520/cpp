#include<bits/stdc++.h>
using namespace std;
typedef __int128 lll;
const int N=1e5+10,D=6;
int n;
int head[N],nxt[D*N],ver[D*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int ind[N],outd[N];
queue<int>q;
lll gcd(lll a,lll b){
    return b?gcd(b,a%b):a;
}
lll lcm(lll a,lll b){
    return a/gcd(a,b)*b;
}
void printlll(lll x){
    if(x){
        printlll(x/10);
        putchar(char(x%10+'0'));
    }
}
struct frac{//a/b
    lll a,b;
    frac(lll x=0,lll y=1){a=x,b=y;}
    frac friend operator+(frac x,frac y){
        frac z;
        z.b=lcm(x.b,y.b);
        z.a=z.b/x.b*x.a+z.b/y.b*y.a;
        lll t=gcd(z.a,z.b);
        z.a/=t;z.b/=t;
        return z;
    }
    frac friend operator/(frac x,lll y){
        x.b*=y;
        int t=gcd(x.a,x.b);
        x.a/=t;x.b/=t;
        return x;
    }
    void print(){
        printlll(a);putchar(' ');
        printlll(b);putchar('\n');
    }
}a[N];
int main(){
    scanf("%d%*d",&n);
    for(int i=1;i<=n;i++){
        int d;scanf("%d",&d);
        while(d--){
            int a;scanf("%d",&a);
            add(i,a);
            ind[a]++;outd[i]++;
        }
    }
    for(int i=1;i<=n;i++)
        if(!ind[i]){
            q.push(i);
            a[i]=frac(1);
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            ind[v]--;
            a[v]=a[v]+(a[u]/outd[u]);
            if(!ind[v]) q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        if(!outd[i])
            a[i].print();
    return 0;
}