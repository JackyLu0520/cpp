#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
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
}h;
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            h.push(x);
        }else if(op==2){
            printf("%d\n",h.top());
        }else{
            h.pop();
        }
    }
    return 0;
}