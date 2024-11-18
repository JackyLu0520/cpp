#include<bits/stdc++.h>
using namespace std;
const int N=710,MOD=1e9+7;
int n;
string s;
int match[N];
long long dp[N][N][3][3];//0:no color 1:red 2:blue
bool vis[N][N];
void solve(int l,int r){
    if(vis[l][r])   return;
    vis[l][r]=1;
    if(r-l==1){
        for(int lc=0;lc<3;lc++)
            for(int rc=0;rc<3;rc++){
                if((lc&&rc)||(!lc&&!rc))    continue;
                dp[l][r][lc][rc]=1;
            }
    }else if(match[l]==r){
        solve(l+1,r-1);
        for(int lc=0;lc<3;lc++)
            for(int rc=0;rc<3;rc++)
                for(int llc=0;llc<3;llc++)
                    for(int rrc=0;rrc<3;rrc++){
                        if((lc&&rc)||(!lc&&!rc))    continue;
                        if(lc==llc&&lc) continue;
                        if(rc==rrc&&rc) continue;
                        dp[l][r][lc][rc]+=dp[l+1][r-1][llc][rrc];
                        dp[l][r][lc][rc]%=MOD;
                    }
    }else{
        solve(l,match[l]);
        solve(match[l]+1,r);
        for(int lc=0;lc<3;lc++)
            for(int rc=0;rc<3;rc++)
                for(int llc=0;llc<3;llc++)
                    for(int rrc=0;rrc<3;rrc++){
                        if(rc==llc&&rc)  continue;
                        dp[l][r][lc][rrc]+=dp[l][match[l]][lc][rc]*dp[match[l]+1][r][llc][rrc]%MOD;
                        dp[l][r][lc][rrc]%=MOD;
                    }
    }
#ifdef DEBUG
    for(int lc=0;lc<3;lc++)
        for(int rc=0;rc<3;rc++){
            printf("dp[%d][%d][%d][%d]=%d\n",l,r,lc,rc,dp[l][r][lc][rc]);
        }
#endif
}
long long ans;
int main(){
    cin>>s;
    n=s.size();
    s=' '+s;
    stack<int>stk;
    for(int i=n;i>=1;i--)
        if(s[i]==')')
            stk.push(i);
        else
            match[i]=stk.top(),stk.pop();
    solve(1,n);
    for(int lc=0;lc<3;lc++)
        for(int rc=0;rc<3;rc++){
            ans+=dp[1][n][lc][rc];
            ans%=MOD;
        }
    cout<<ans<<'\n';
    return 0;
}