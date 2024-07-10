#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
class heap{//小根堆
    private:
    int a[N],tot=0;
    void up(int p){
        while(p>1)
            if(a[p/2]>a[p]){
                swap(a[p],a[p/2]);
                p/=2;
            }else   break;
    }
    void down(int p){
        int s=p*2;
        while(s<=tot){
            if(s<tot&&a[s]>a[s+1]) s++;
            if(a[s]<a[p]){
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
}h;
int n,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        h.push(t);
    }
    while(h.size()>1){
        int x=h.top();h.pop();
        int y=h.top();h.pop();
        h.push(x+y);
        ans+=x+y;
    }
    printf("%d",ans);
    return 0;
}