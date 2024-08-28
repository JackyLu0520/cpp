#include<bits/stdc++.h>
using namespace std;
const long long X=26,MOD=1e9+7;
struct matrix{
    long long a[X][X]={0};int x,y;
    matrix(){}
    matrix(int _x,int _y){x=_x;y=_y;}
    long long * const operator[](const int i){
        return a[i];
    }
    matrix friend operator*(matrix a,matrix b){
        if(a.y!=b.x)    return matrix(1,1);
        matrix ans(a.x,b.y);
        for(int i=0;i<a.x;i++)
            for(int j=0;j<b.y;j++)
                for(int k=0;k<a.y;k++)
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
        return ans;
    }
};
matrix id(int x){matrix t(x,x);for(int i=0;i<x;i++)t[i][i]=1;return t;}
matrix binpow(matrix a,long long b){
    if(a.x!=a.y)    return matrix(1,1);
    matrix ans=id(a.x);
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
long long n,ans=0;
string s;
matrix dp(1,26),b(26,26);
int main(){
    cin>>n>>s;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            b[i][j]=1;
    for(int i=0;i<s.size()-1;i++)
        b[s[i]-'a'][s[i+1]-'a']=0;
    for(int i=0;i<26;i++)
        dp[0][i]=1;
    dp=dp*binpow(b,n-1);
    for(int i=0;i<26;i++)
        ans=(ans+dp[0][i])%MOD;
    cout<<ans;
    return 0;
}