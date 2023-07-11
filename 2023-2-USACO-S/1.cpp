#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,tc,tm,a[110],b[110],c[110],ans=2e9+10;
        cin>>n>>tc>>tm;
        for(int i=1;i<=n;i++)
            cin>>a[i]>>b[i]>>c[i];
        for(long long i=0;i<tc;i++)
            for(long long j=0;j<tm;j++){
                bool f=1;
                for(long long k=1;k<=n;k++)
                    if((tc-i)*a[k]+(tm-j)*b[k]>c[k]){
                        f=0;
                        break;
                    }
                if(f){
                    ans=min(ans,i+j);
                    break;
                }
            }
        cout<<ans<<endl;
    }
    return 0;
}
