#include<bits/stdc++.h>
using namespace std;
const int N=60;
int n=2*26,m,st=N;
int g[N][N];
int p[N];
int deg[N];
stack<int>s;
void dfs(int u){
    for(int v=1;v<=n;v++)
        if(g[u][v]){
            g[u][v]--;
            g[v][u]--;
            dfs(v);
        }
    s.push(u);
}
inline int to_num(char c){
    if(c>='a'&&c<='z')  return c-'a'+26+1;
    else    return c-'A'+1;
}
inline char to_char(int x){
    if(x<=26)   return x+'A'-1;
    else        return x-26+'a'-1;
}
int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        char str[5];scanf("%s",str);
        int u=to_num(str[0]);
        int v=to_num(str[1]);
        g[u][v]++;
        g[v][u]++;
        deg[u]++;deg[v]++;
        st=min(min(u,v),st);
    }
    int cnt=0;
    for(int i=n;i>=1;i--)
        if(deg[i]%2){
            st=i;cnt++;
        }
    if(cnt!=0&&cnt!=2){printf("No Solution");return 0;}
    dfs(st);
    if(s.size()!=m+1){printf("No Solution");return 0;}
    while(!s.empty()){
        putchar(to_char(s.top()));
        s.pop();
    }
    return 0;
}