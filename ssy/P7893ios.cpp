#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long t;cin>>t;
    while(t--){
        long long n,p;
        cin>>n>>p;
        if(p==1){cout<<0<<'\n';continue;}
        long long ans=0;
        for(long long s=1;n>0;s=-s,n/=p)
            ans+=s*n;
        cout<<ans<<'\n';
    }
    return 0;
}