#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
class heap1{//大根堆
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
};
class heap2{//小根堆
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
};
heap1 h1;//小的一半（包含中位数）
heap2 h2;//大的一半
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]>h1.top())   h2.push(a[i]);
        else                h1.push(a[i]);
        if(i%2){
            while(h1.size()>h2.size()+1){h2.push(h1.top());h1.pop();}
            while(h1.size()<h2.size()+1){h1.push(h2.top());h2.pop();}
            printf("%d\n",h1.top());
        }
    }
    return 0;
}