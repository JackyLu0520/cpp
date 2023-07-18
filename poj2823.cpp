#include<iostream>
#include<deque>
using namespace std;
const int MAXN=1e6;
int n,k;
int a[MAXN+10],Min[MAXN+10],Max[MAXN+10],minp=0,maxp=0;
deque<int> q1,q2;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        while(!q1.empty()&&a[q1.back()]<=a[i]) q1.pop_back();
        while(!q2.empty()&&a[q2.back()]>=a[i]) q2.pop_back();
        q1.push_back(i);
        q2.push_back(i);
        while(!q1.empty()&&q1.front()<=i-k) q1.pop_front();
        while(!q2.empty()&&q2.front()<=i-k) q2.pop_front();
        if(i>=k){
            Max[++maxp]=a[q1.front()];
            Min[++minp]=a[q2.front()];
        }
    }
    for(int i=1;i<=minp;i++)
        cout<<Min[i]<<' ';
    cout<<endl;
    for(int i=1;i<=maxp;i++)
        cout<<Max[i]<<' ';
    return 0;
}