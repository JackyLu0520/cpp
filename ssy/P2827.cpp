#include<bits/stdc++.h>
using namespace std;
const int N=7e6+1e5+10;
int n,m,q,u,v,t,add=0;
class heap{//大根堆
    private:
    int a[N],tot=0;
    void up(int p){
        while(p>1)
            if(a[p/2]<a[p]){
                swap(a[p],a[p/2]);
                p/=2;
            }else   break;
    }
    void down(int p){
        int s=p*2;
        while(s<=tot){
            if(s<tot&&a[s]<a[s+1]) s++;
            if(a[s]>a[p]){
                swap(a[p],a[s]);
                p=s;
                s=p*2;
            }else   break;
        }
    }
    public:
    void push(int x){
        a[++tot]=x;up(tot);
    }
    int top(){
        return a[1];
    }
    void pop(){
        swap(a[1],a[tot]);
        tot--;
        down(1);
    }
    int size(){
        return tot;
    }
}Q;
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        Q.push(a);
    }
    for(int i=1;i<=m;i++){
        int x=Q.top();Q.pop();x+=add;
        if(i%t==0)  printf("%d ",x);
        int x1=1LL*x*u/v;
        int x2=x-x1;
        Q.push(x1-q-add);Q.push(x2-q-add);
        add+=q;
    }
    printf("\n");
    for(int i=1;i<=n+m;i++){
        if(i%t==0)  printf("%d ",Q.top()+add);
        Q.pop();
    }
    return 0;
}