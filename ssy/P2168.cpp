#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,k;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int w;
        scanf("%d",&w);
        q.push(make_pair(w,1));
    }
    while((q.size()-1)%(k-1))   q.push(make_pair(0,1));
    
}