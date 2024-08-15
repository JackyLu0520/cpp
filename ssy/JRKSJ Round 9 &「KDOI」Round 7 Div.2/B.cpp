#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N],ans=1e9+10;
struct deque{
    int q[N],head=0,tail=1;
    bool empty(){return head==tail;}
    int front(){return q[head];}
    int back(){return q[tail-1];}
    void pop_back(){tail--;}
    void push_back(int x){q[tail++]=x;}
    void pop_front(){head++;}
}q1;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    /*for(int i=1;i<=m;i++){
        for(int j=1;j<p;j++)
            a[j]=max(a[j],a[j+1]);
        p--;
    }*/
    for(int i=1;i<=n;i++){
        while(!q1.empty()&&a[q1.back()]<=a[i])   q1.pop_back();
        q1.push_back(i);
        while(!q1.empty()&&q1.front()<=i-m-1)  q1.pop_front();
        if(i>=m+1)    ans=min(ans,a[q1.front()]);
    }
    printf("%d",ans);
    return 0;
}