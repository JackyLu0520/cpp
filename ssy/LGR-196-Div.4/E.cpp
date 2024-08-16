#include<bits/stdc++.h>
using namespace std;
int n,t,mod=1;
vector<int>a;
int main(){
    scanf("%d%d",&n,&t);
    for(int i=1;i<=t;i++)
        mod*=10;
    for(int i=1;i<=n;i++){
        int b;scanf("%d",&b);
        a.push_back(b%mod);
    }
    sort(a.begin(),a.end());
    printf("%d",unique(a.begin(),a.end())-a.begin());
    return 0;
}