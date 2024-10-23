#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e6+10,A=30;
string s;
long long ans;
int head[A],nxt[N],val[N],tail[A],tot=0;
void push_back(int i,int v){
    val[++tot]=v;
    if(!head[i])    head[i]=tot;
    else    nxt[tail[i]]=tot;
    tail[i]=tot;
}
void pop_front(int i){
    head[i]=nxt[head[i]];
}
struct seg{
    int l,r;
    seg(){}
    seg(int _l,int _r){l=_l;r=_r;}
    bool operator<(const seg& a)const{return l<a.l;}
}t[N];
int tp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
        push_back(s[i]-'a',i);
    for(int i=0;i<26;i++){
        push_back(i,s.size());
        push_back(i,s.size());
    }
    for(int i=0;i<s.size();i++){
        tp=0;
        for(int j=0;j<26;j++){
            if(val[head[j]]<i)   pop_front(j);
            t[tp++]=seg(val[head[j]],val[nxt[head[j]]]);
        }
        sort(t,t+tp);
        int l=0,r=0;
        for(int i=0;i<tp;i++){
            if(r>=t[i].l)   r=max(r,t[i].r);
            else{ans+=r-l;l=t[i].l;r=t[i].r;}
        }
        ans+=r-l;
    }
    cout<<ans<<'\n';
    return 0;
}