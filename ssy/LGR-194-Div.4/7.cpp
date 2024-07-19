#include<bits/stdc++.h>
using namespace std;
const int K=1e3+10;
int n;
string m="respect";
int main(){
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int k,p[K],ans=0;
        cin>>k;
        for(int i=1;i<=k;i++)   cin>>p[i];
        p[0]=0;p[k+1]=s.size();
        for(int i=0;i<=k;i++){
            bool f1=0;
            for(int j=p[i];j<=p[i+1]-7;j++){
                bool f2=1;
                for(int l=0;l<7;l++)
                    if(s[j+l]!=m[l])
                        f2=0;
                if(f2)   f1=1;
            }
            if(f1)  ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}