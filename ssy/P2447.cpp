#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=2010;
int n,m;
bitset<N> a[M];
int ans=-1;
bool Gauss(){
    for(int i=1;i<=n;i++){
        int t=i;
        while(t<=m&&!a[t].test(i))
            t++;
        if(t>m) return 0;
        ans=max(ans,t);
        swap(a[i],a[t]);
        for(int j=1;j<=m;j++)
            if(i!=j&&a[j].test(i))
                a[j]^=a[i];
    }
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        string s;bool t;
        cin>>s>>t;
        for(int j=0;j<n;j++)
            a[i].set(j+1,s[j]=='1');
        a[i].set(n+1,t);
    }
    if(Gauss()){
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++)
            cout<<(a[i][n+1]?"?y7M#":"Earth")<<'\n';
    }else   cout<<"Cannot Determine";
    return 0;
}