#include<cstdio>
using namespace std;
const int MAXN=1e6;
int n,k;
int a[MAXN+10],Min[MAXN+10],Max[MAXN+10],p=0;
struct deque{
    int head,tail;
    int a[MAXN*2+10];
    deque(){head=0;tail=0;}
    int front(){return a[head];}
    int back(){return a[tail-1];}
    void push_back(int n){a[tail++]=n;}
    void pop_front(){head++;}
    void pop_back(){tail--;}
    bool empty(){return head==tail;}
};
deque q1,q2;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        while(!q1.empty()&&a[q1.back()]<=a[i]) q1.pop_back();
        while(!q2.empty()&&a[q2.back()]>=a[i]) q2.pop_back();
        q1.push_back(i);
        q2.push_back(i);
        while(!q1.empty()&&q1.front()<=i-k) q1.pop_front();
        while(!q2.empty()&&q2.front()<=i-k) q2.pop_front();
        if(i>=k){
            p++;
            Max[p]=a[q1.front()];
            Min[p]=a[q2.front()];
        }
    }
    for(int i=1;i<=p;i++)
        printf("%d ",Min[i]);
    printf("\n");
    for(int i=1;i<=p;i++)
        printf("%d ",Max[i]);
    return 0;
}