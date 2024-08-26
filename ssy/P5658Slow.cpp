#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
char c[N];
vector<int>son[N];
//stack<char>s;
struct Stack{
    char a[N],tot=0;
    void push(char c){a[++tot]=c;}
    bool empty(){return tot==0;}
    char top(){return a[tot];}
    void pop(){tot--;}
}s;
int cnt[N],ans[N];
void dfs1(int u){
    int op;
    if(c[u]=='('){op=1;s.push(c[u]);}
    else if(c[u]==')'&&(s.empty()||s.top()!='(')){op=2;s.push(c[u]);}
    else if(c[u]==')'&&s.top()=='('){op=3;s.pop();}
    if(s.empty())   cnt[u]++;
    for(int v:son[u])
        dfs1(v);
    if(op==1)   s.pop();
    else if(op==2)  s.pop();
    else if(op==3)  s.push('(');
}
void dfs2(int u){
    for(int v:son[u]){
        ans[v]=ans[u]+cnt[v];
        dfs2(v);
    }
}
int main(){
    scanf("%d%s",&n,c+1);
    for(int i=2;i<=n;i++){
        int fa;scanf("%d",&fa);
        son[fa].push_back(i);
    }
    for(int i=1;i<=n;i++)
        dfs1(i);
    dfs2(1);
    int ans1=0;
    for(int i=1;i<=n;i++)
        ans1^=ans[i]*i;
    printf("%d",ans1);
    return 0;
}