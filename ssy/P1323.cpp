#include<bits/stdc++.h>
using namespace std;
int k,m;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
    scanf("%d%d",&k,&m);
    q.push(1);
    for(int i=1;i<=k;i++){
        int t=q.top();q.pop();
        q.push(2*t+1);q.push(4*t+5);
    }
}