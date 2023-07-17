#include<iostream>
#include<queue>
using namespace std;
const int MAXN=1e6;
int n,k;
int a[MAXN+10],Max[MAXN+10],Min[MAXN+10];
queue<int> q1,q2;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        while(!q1.empty()&&q1.size()>k) q1.pop();
        while(!q2.empty()&&q2.size()>k) q2.pop();
        while(!q1.empty()&&q1.back()<a[i]) q1.pop();
        while(!q2.empty()&&q2.back()>a[i]) q2.pop();
        q1.push(a[i]);
        q2.push(a[i]);
        Max[i]=q1.front();
        Min[i]=q2.front();
    }
    for(int i=k;i<=n;i++)
        cout<<Min[i]<<' ';
    cout<<endl;
    for(int i=k;i<=n;i++)
        cout<<Max[i]<<' ';
    return 0;
}