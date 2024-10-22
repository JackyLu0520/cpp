#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e6+10,A=30;
string s;
long long ans;
vector<int>p[A];
int l[A],r[A];//[l,r)
int diff[A<<1];
int t[N<<1],tp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
        p[s[i]-'a'].push_back(i);
    for(int i=0;i<26;i++){
        p[i].push_back(s.size());
        p[i].push_back(s.size());
    }
    for(int i=0;i<s.size();i++){
        tp=0;
        for(int j=0;j<26;j++){
            auto it=lower_bound(p[j].begin(),p[j].end(),i);
            l[j]=*it;
            r[j]=*(it+1);
            t[tp++]=l[j];t[tp++]=r[j];
        }
        sort(t,t+tp);
        int ed=unique(t,t+tp)-t;
        memset(diff,0,sizeof(diff));
        for(int j=0;j<26;j++){
            int lit=lower_bound(t,t+ed,l[j])-t;
            int rit=lower_bound(t,t+ed,r[j])-t;
            diff[lit]++;
            diff[rit]--;
        }
        for(int j=1;j<ed;j++)
            diff[j]+=diff[j-1];
        for(int j=0;j<ed-1;j++)
            if(diff[j])
                ans+=t[j+1]-t[j];
    }
    cout<<ans<<'\n';
    return 0;
}